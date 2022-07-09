// https://gobyexample.com/
// update@2022年7月9日 17:59:31
// 1、go里除了函数用括号，语句暂时没有见到用括号的，if，for都没有括号
package main

import (
	"errors"
	"fmt"
	"math"
	"time"
)

func HelloWorld() {
	fmt.Println("hello world!")
}

func Values() {
	fmt.Println("go" + "lang")

	fmt.Println("1+1=", 1+1)
	fmt.Println("7.0/3.0=", 7.0/3.0)
	fmt.Println(true && false)
	fmt.Println(true || false)
	fmt.Println(!true)
}

func Variables() {
	// 一个变量声明
	var a = "initial"
	fmt.Println(a)

	var f int = 3
	fmt.Println(f)

	g := "apple"
	fmt.Println(g)

	// N个变量声明
	var b, c int = 1, 2
	fmt.Println(b, c)
}

func Constants() {
	const s string = "constant"

	fmt.Println(s)
	const n = 5000000

	const d = 2e20 / n
	fmt.Println(d)

	fmt.Println(int64(d))
	fmt.Println(math.Sin(n))
}

func For() {
	n := 0
	for ; n <= 5; n++ {
		if n%2 == 0 && n != 2 {
			continue
		}
		fmt.Println(n)
	}
}

func If() {
	if 7%2 == 0 {
		fmt.Println("7 is even")
	} else {
		fmt.Println("7 is odd")
	}

	if num := 9; num < 0 {
		fmt.Println(num, "is negative")
	} else if num < 10 {
		fmt.Println(num, "has 1 digit.")
	} else {
		fmt.Println(num, "has multiple digitals.")
	}
}

func Switch() {
	i := 2
	fmt.Println("write ", i, " as ")
	switch i {
	case 1:
		fmt.Println("one")
	case 2:
		fmt.Println("two")
	case 3:
		fmt.Println("three")
	}

	switch time.Now().Weekday() {
	case time.Saturday, time.Sunday:
		fmt.Println("It's the weekend")
	default:
		fmt.Println("It's a weekday")
	}

	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("It's before moon")
	default:
		fmt.Println("It's after noon")
	}

	whatAmI := func(i interface{}) {
		switch t := i.(type) {
		case bool:
			fmt.Println("I'm a bool")
		case int:
			fmt.Println("I'm an int")
		default:
			fmt.Printf("Don't know type %T\n", t)
		}
	}

	whatAmI(true)
	whatAmI(1)
	whatAmI("hey")
}

func Array() {
	//
	var a [5]int
	fmt.Println("emp:", a)

	a[4] = 100
	fmt.Println("set:", a)
	fmt.Println("get:", a[4])

	fmt.Println("len:", len(a))

	//
	b := [5]int{1, 2, 3, 4, 5}
	fmt.Println("dcl:", b)

	//
	var twoD [2][3]int
	for i := 0; i < 2; i++ {
		for j := 0; j < 3; j++ {
			twoD[i][j] = i + j
		}
	}
	fmt.Println("2d: ", twoD)
}

func Slices() {
	s := make([]string, 3)
	fmt.Println("emp:", s)

	s[0] = "a"
	s[1] = "b"
	s[2] = "c"
	fmt.Println("set:", s)
	fmt.Println("get:", s[2])
	fmt.Println("len:", len(s))

	// b类似指针
	b := s
	b[0] = "1"
	fmt.Println("b=", b)
	fmt.Println("s=", s)

	s = append(s, "d")
	s = append(s, "e", "f")
	fmt.Println("apd:", s)
}

func Maps() {
	m := make(map[string]int)

	// add
	m["k1"] = 7
	m["k2"] = 13
	fmt.Println("map:", m)

	// update
	m["k1"] = 70000
	fmt.Println("m[k1]=", m["k1"])

	// query
	_, ok := m["k3"] // 并不会插入k3
	fmt.Println("ok: ", ok)
	fmt.Println("len:", len(m))

	if _, ok := m["k5"]; !ok {
		m["k5"] = 1
		fmt.Println("k5 is not in m,insert it!")
	}
	fmt.Println("m:", m)

	// delete
	delete(m, "k2")
	fmt.Println("map:", m)

	n := map[string]int{"foo": 1, "bar": 2}
	fmt.Println("map:", n)
}

func Range() {
	nums := []int{2, 3, 4}
	sum := 0

	for _, num := range nums {
		sum += num
	}
	fmt.Println("sum:", sum)

	for i, num := range nums {
		if num == 3 {
			fmt.Println("index:", i)
		}
	}

	kvs := map[string]string{"a": "apple", "b": "banana"}
	for k, v := range kvs {
		fmt.Printf("%s -> %s\n", k, v)
	}

	for k := range kvs {
		fmt.Println("key:", k)
	}

	for i, c := range "ago" {
		fmt.Println(i, c)
	}

}

func plus(a int, b int) int {
	return a + b
}

func plusPlus(a, b, c int) int {
	return a + b + c
}

func Function() {
	res := plus(1, 2)
	fmt.Println("1+2=", res)

	res = plusPlus(1, 2, 3)
	fmt.Println("1+2+3=", res)
}

func vals() (int, int) {
	return 3, 7
}

func MultipleReturnValues() {
	a, b := vals()
	fmt.Println(a)
	fmt.Println(b)

	_, c := vals()
	fmt.Println(c)
}

func sum(nums ...int) {
	fmt.Print(nums, ",total=")
	total := 0

	for _, num := range nums {
		total += num
	}

	fmt.Println(total)
}

func VariadicFunctions() {
	sum(1, 2)
	sum(1, 2, 3)
	nums := []int{1, 2, 3, 4, 5}
	sum(nums...)
}

func intSeq() func() int {
	i := 0
	return func() int {
		i++
		return i
	}
}

func Closures() {
	nextInt := intSeq()
	fmt.Println(nextInt())
	fmt.Println(nextInt())
	fmt.Println(nextInt())

	newInts := intSeq()
	fmt.Println(newInts())
}

func fact(n int) int {
	if n == 0 {
		return 1
	}
	return n * fact(n-1)
}

func Recursion() {
	fmt.Println(fact(7))

	var fib func(n int) int
	fib = func(n int) int {
		if n < 2 {
			return n
		}

		return fib(n-1) + fib(n-2)
	}

	fmt.Println(fib(7))
}

func zeroval(ival int) {
	ival = 0
}

func zeroptr(iptr *int) {
	*iptr = 0
}

func Pointers() {
	i := 1
	fmt.Println("initial:", i)

	zeroval(i)
	fmt.Println("zeroval:", i)

	zeroptr(&i)
	fmt.Println("zeroptr:", i)

	fmt.Println("pointer:", &i)
}

type person struct {
	name string
	age  int
}

func newPerson(name string) *person {
	p := person{name: name}
	p.age = 42
	return &p
}

func Structs() {
	fmt.Println(person{"Bob", 20})
	fmt.Println(person{name: "Alice", age: 30})
	fmt.Println(person{name: "Fred"})

	fmt.Println(&person{name: "Ann", age: 40})
	fmt.Println(newPerson("Jon"))

	s := person{name: "Sean", age: 50}
	fmt.Println(s.name)

	sp := &s
	fmt.Println(sp.age)

	sp.age = 51
	fmt.Println(sp.age)
}

type rect1 struct {
	width, height int
}

func (r *rect1) area() int {
	return r.width * r.height
}

func (r rect1) perim() int {
	return 2 * r.width * r.height
}

func Methods() {
	r := rect1{width: 10, height: 5}
	fmt.Println("area: ", r.area())
	fmt.Println("perim:", r.perim())

	rp := &r
	fmt.Println("area: ", rp.area())
	fmt.Println("perim:", rp.perim())
}

/////////interface begin/////////////
type geometry interface {
	area() float64
	perim() float64
}

type rect struct {
	width, height float64
}

type circle struct {
	radius float64
}

func (r rect) area() float64 {
	return r.width * r.height
}

func (r rect) perim() float64 {
	return 2*r.width + 2*r.height
}

func (c circle) area() float64 {
	return math.Pi * c.radius * c.radius
}

func (c circle) perim() float64 {
	return 2 * math.Pi * c.radius
}

func measure(g geometry) {
	fmt.Println(g)
	fmt.Println(g.area())
	fmt.Println(g.perim())
}

// 一堆同名method
func Interface() {
	r := rect{width: 3, height: 4}
	c := circle{radius: 5}

	measure(r)
	measure(c)

}

/////////interface end/////////////

type base struct {
	num int
}

func (b base) describe() string {
	return fmt.Sprintf("base with num:%v", b.num)
}

type container struct {
	base
	str string
}

func StructEmbedding() {
	co := container{
		base: base{num: 1},
		str:  "some name",
	}

	fmt.Printf("co={num:%v, str:%v}\n", co.num, co.str)

	fmt.Println("also num:", co.base.num)

	type describer interface {
		describe() string
	}
	var d describer = co
	fmt.Println("describer:", d.describe())
}

func MapKeys[K comparable, V any](m map[K]V) []K {
	r := make([]K, 0, len(m))
	for k := range m {
		r = append(r, k)
	}
	return r
}

type List[T any] struct {
	head, tail *element[T]
}

type element[T any] struct {
	next *element[T]
	val  T
}

func (lst *List[T]) Push(v T) {
	if lst.tail == nil {
		lst.head = &element[T]{val: v}
		lst.tail = lst.head
	} else {
		lst.tail.next = &element[T]{val: v}
		lst.tail = lst.tail.next
	}
}

func (lst *List[T]) GetAll() []T {
	var elems []T
	for e := lst.head; e != nil; e = e.next {
		elems = append(elems, e.val)
	}
	return elems
}

// 1.18生效
func Generics() {
	var m = map[int]string{1: "2", 2: "4", 4: "8"}
	fmt.Println("keys m:", MapKeys(m))

	_ = MapKeys[int, string](m)
	lst := List[int]{}
	lst.Push(10)
	lst.Push(13)
	lst.Push(23)
	fmt.Println("list:", lst.GetAll())
}

func errorf1(arg int) (int, error) {
	if arg == 42 {
		return -1, errors.New("cannot work with 42")
	}

	return arg + 3, nil
}

type argError struct {
	arg  int
	prob string
}

func (e *argError) Error() string {
	return fmt.Sprintf("%d - %s", e.arg, e.prob)
}

func errorf2(arg int) (int, error) {
	if arg == 42 {
		return -1, &argError{arg, "cannot work with it"}
	}
	return arg + 3, nil
}

func Error() {
	for _, i := range []int{7, 42} {
		if r, e := errorf1(i); e != nil {
			fmt.Println("errorf1 failed:", e)
		} else {
			fmt.Println("errorf1 worked:", r)
		}
	}

	for _, i := range []int{7, 42} {
		if r, e := errorf2(i); e != nil {
			fmt.Println("errorf2 failed:", e)
		} else {
			fmt.Println("errorf2 worked:", r)
		}
	}

	_, e := errorf2(42)
	if ae, ok := e.(*argError); ok {
		fmt.Println(ae.arg)
		fmt.Println(ae.prob)
	}
}

func goroutinesf(from string) {
	for i := 0; i < 3; i++ {
		fmt.Println(from, ":", i)
	}
}

func Goroutines() {
	goroutinesf("direct")

	go goroutinesf("goroutine")

	go func(msg string) {
		fmt.Println(msg)
	}("going")
	time.Sleep(3 * time.Second)
	fmt.Println("done")
}

func Channels() {
	messages := make(chan string) // no buffer，等价于 make(chan string, 0)

	go func() { messages <- "ping" }()

	msg := <-messages
	fmt.Println(msg)
}

func ChannelBuffering() {
	messages := make(chan string, 2)
	messages <- "buffered"
	messages <- "channel"

	fmt.Println(<-messages)
	fmt.Println(<-messages)
}

func worker(done chan bool) {
	fmt.Print("working...")
	time.Sleep(time.Second)
	fmt.Println("done")

	done <- true
}

func ChannelSynchronization() {
	done := make(chan bool)
	go worker(done)

	<-done
}

func Ping(pings chan<- string, msg string) {
	pings <- msg
}

func Pong(pings <-chan string, pongs chan<- string) {
	msg := <-pings
	pongs <- msg
}
func ChannelDirections() {
	pings := make(chan string, 1)
	pongs := make(chan string, 1)
	Ping(pings, "passed message")
	Pong(pings, pongs)
	fmt.Println(<-pongs)
}

func Select() {
	c1 := make(chan string)
	c2 := make(chan string)

	go func() {
		time.Sleep(1 * time.Second)
		c1 <- "one"
	}()

	go func() {
		time.Sleep(2 * time.Second)
		c2 <- "two"
	}()

	for i := 0; i < 2; i++ {
		select {
		case msg1 := <-c1:
			fmt.Println("received", msg1)
		case msg2 := <-c2:
			fmt.Println("received", msg2)
		}
	}
}

func Timeouts() {
	c1 := make(chan string, 1)
	go func() {
		time.Sleep((2 * time.Second))
		c1 <- "result 1"
	}()

	select {
	case res := <-c1:
		fmt.Println(res)
	case <-time.After(1 * time.Second):
		fmt.Println("timeout 1")
	}

	c2 := make(chan string, 1)
	go func() {
		time.Sleep(2 * time.Second)
		c2 <- "result 2"
	}()

	select {
	case res := <-c2:
		fmt.Println(res)
	case <-time.After(3 * time.Second):
		fmt.Println("timeout 2")
	}
}

func NonblockingChannelOperations() {
	messages := make(chan string)
	signal := make(chan bool)

	/* go func(messages chan string, name string) {
		messages <- name
	}(messages, "hi")

	time.Sleep(1 * time.Second) */
	select {
	case msg := <-messages:
		fmt.Println("receive message", msg)
	default:
		fmt.Println("no message received")
	}

	msg := "hi"
	select {
	case messages <- msg:
		fmt.Println("send message", msg)
	default:
		fmt.Println("no message sent")
	}

	select {
	case msg := <-messages:
		fmt.Println("received message", msg)
	case sig := <-signal:
		fmt.Println("received signal", sig)
	default:
		fmt.Println("no activity")
	}
}

func CloseChannel() {
	jobs := make(chan int, 5)
	done := make(chan bool)

	go func() {
		for {
			j, more := <-jobs // close就返回more==false
			if more {
				fmt.Println("receive job", j)
			} else {
				fmt.Println("receive all jobs")
				done <- true
				return
			}
		}
	}()

	for j := 1; j <= 3; j++ {
		jobs <- j
		fmt.Println("send job", j)
	}
	close(jobs)
	fmt.Println("send all jobs")

	<-done
}

func RangeOverChannels() {
	queue := make(chan string, 2)
	queue <- "done"
	queue <- "two"
	close(queue)

	for elem := range queue {
		fmt.Println(elem)
	}
}

func Timer() {
	timer1 := time.NewTimer(2 * time.Second)
	<-timer1.C
	fmt.Println("Timer 1 fired")

	timer2 := time.NewTimer(time.Second)
	go func() {
		fmt.Println("in Timer 2")
		<-timer2.C
		fmt.Println("Timer 2 fired")
	}()

	stop2 := timer2.Stop()
	if stop2 {
		fmt.Println("Timer 2 stopped")
	} else {
		fmt.Println("Timer 2 not stopped")
	}

	time.Sleep(2 * time.Second)

	stop2 = timer2.Stop()
	if stop2 {
		fmt.Println("Timer 2 stopped2")
	} else {
		fmt.Println("Timer 2 not stopped2")
	}
}

func Tickers() {
	ticker := time.NewTicker(500 * time.Millisecond) // 每隔500ms触发一次，写入 ticker.C
	done := make(chan bool)

	go func() {
		for {
			select {
			case <-done:
				return
			case t := <-ticker.C:
				fmt.Println("Tick at", t)
			}
		}
	}()

	time.Sleep(1600 * time.Millisecond)
	ticker.Stop()
	done <- true
	fmt.Println("Ticker stopped")
}

func main() {
	Tickers()
}
