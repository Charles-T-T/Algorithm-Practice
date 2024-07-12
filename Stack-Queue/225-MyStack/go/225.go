package main

type MyStack struct {
	slice []int
}


func Constructor() MyStack {
	return MyStack{}
}


func (st *MyStack) Push(x int)  {
	st.slice = append(st.slice, x)
}


func (st *MyStack) Pop() int {
	top := st.slice[len(st.slice) - 1]
	st.slice = st.slice[0 : len(st.slice) - 1]
	return top
}


func (st *MyStack) Top() int {
	top := st.Pop()
	st.slice = append(st.slice, top)
	return top
}


func (st *MyStack) Empty() bool {
	return len(st.slice) == 0
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */