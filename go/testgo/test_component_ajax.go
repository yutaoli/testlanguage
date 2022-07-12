package main

import (
	"encoding/json"
	"io"
	"net/http"
	"os"

	"github.com/sirupsen/logrus"
	log "github.com/sirupsen/logrus"
)

type Data struct {
	Name string
	Age  int
	Sex  string
}

type Ret struct {
	Code  int
	Param string
	Msg   string
	Data  []Data
}

var f *os.File

func InitLog() *os.File {
	// 创建、追加、读写，777，所有权限
	var err error
	f, err = os.OpenFile("log.log", os.O_CREATE|os.O_APPEND|os.O_RDWR, os.ModePerm)
	if err != nil {
		return nil
	}

	logrus.SetReportCaller(true)
	/* 	logrus.SetFormatter(&logrus.TextFormatter{
		//以下设置只是为了使输出更美观
		DisableColors:   true,
		TimestampFormat: "2006-01-02 15:03:04",
	}) */
	log.SetOutput(f)
	//log.SetFlags(log.Ldate | log.Ltime | log.Lshortfile)
	log.SetFormatter(&log.JSONFormatter{
		TimestampFormat: "2006-01-02 15:03:04",
	})
	return f
}

func HelloServer(w http.ResponseWriter, req *http.Request) {
	defer func() {
		if r := recover(); r != nil {
			log.Error("recover,msg:\n", r)
		}
	}()

	log.Debug("in,header:\n", w.Header())

	data := Data{Name: "Jack", Age: 30, Sex: "Male"}
	data2 := Data{Name: "Mary", Age: 21, Sex: "Female"}
	data3 := Data{Name: "LiLei", Age: 30, Sex: "Male"}

	ret := new(Ret)
	id := req.FormValue("id")
	//id := req.PostFormValue('id')

	ret.Code = 0
	ret.Param = id
	ret.Msg = "success"
	ret.Data = append(ret.Data, data)
	ret.Data = append(ret.Data, data2)
	ret.Data = append(ret.Data, data3)
	ret_json, _ := json.Marshal(ret)

	io.WriteString(w, string(ret_json))

}
func HelloServer1(w http.ResponseWriter, req *http.Request) {
	io.WriteString(w, "hello, world1!\n")
}

func main() {
	defer func() {
		f.Close()
	}()
	f = InitLog()
	log.Debug("in main")

	http.HandleFunc("/test_component_ajax/getGridData", HelloServer)
	http.HandleFunc("/hello1", HelloServer1)
	err := http.ListenAndServe(":1234", nil)
	if err != nil {
		log.Fatal("ListenAndServe: ", err)
	}
}
