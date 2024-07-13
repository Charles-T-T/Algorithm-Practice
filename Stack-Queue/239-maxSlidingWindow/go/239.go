package main

import "fmt"

type MyQueue struct {
	q []int
}

func (mq MyQueue) front() int {
	return mq.q[0]
}

func (mq MyQueue) back() int {
	return mq.q[len(mq.q) - 1]
}

func (mq *MyQueue) pop() {
	mq.q = mq.q[:len(mq.q)-1]
}

func (mq *MyQueue) push(num int) {
	for len(mq.q) != 0 && mq.back() < num {
		mq.pop()
	}
	mq.q = append(mq.q, num)
}

func (mq MyQueue) size() int {
	return len(mq.q)
}

func maxSlidingWindow(nums []int, k int) []int {
	res := []int{}
	mq := MyQueue{}
	left, right := 0, k-1
	for right < len(nums) {
		if mq.size() > 0 && nums[left] == mq.front() {
			mq.pop()
		}
		mq.push(nums[right])
		res = append(res, mq.front())
		left++
		right++
	}
	return res
}

func main() {
	nums := []int{1,3,-1,-3,5,3,6,7}
	k := 3
	res := maxSlidingWindow(nums, k)
	fmt.Printf("%v\n", res)
}