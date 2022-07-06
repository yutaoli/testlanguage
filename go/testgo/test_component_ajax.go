package main

import (
	"encoding/json"
	"io"
	"log"
	"net/http"
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

func HelloServer(w http.ResponseWriter, req *http.Request) {
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
	http.HandleFunc("/test/getGridData", HelloServer)
	http.HandleFunc("/hello1", HelloServer1)
	err := http.ListenAndServe(":9090", nil)
	if err != nil {
		log.Fatal("ListenAndServe: ", err)
	}
}
