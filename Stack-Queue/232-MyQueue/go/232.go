package main

type MyQueue struct {
	s []int
}


func Constructor() MyQueue {
	return MyQueue{}
}


func (queue *MyQueue) Push(x int)  {
	queue.s = append(queue.s, x)
}


func (queue *MyQueue) Pop() int {
	top := queue.s[0]
	queue.s = queue.s[1:]
	return top
}


func (queue *MyQueue) Peek() int {
	return queue.s[0]
}


func (queue *MyQueue) Empty() bool {
	return len(queue.s) == 0
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */