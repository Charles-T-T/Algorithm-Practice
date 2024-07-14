package main

import "fmt"

type MyQueue struct {
	q []int
}

func (mq MyQueue) front() int {
	return mq.q[0]
}

func (mq MyQueue) back() int {
	return mq.q[len(mq.q)-1]
}

func (mq *MyQueue) pop() {
	mq.q = mq.q[1:len(mq.q)]
}

func (mq *MyQueue) push(num int) {
	for len(mq.q) != 0 && mq.back() < num {
		mq.q = mq.q[0 : len(mq.q)-1]
	}
	mq.q = append(mq.q, num)
}

func maxSlidingWindow(nums []int, k int) []int {
	res := []int{}
	mq := MyQueue{}
	for i := 0; i < k; i++ {
		mq.push(nums[i])
	}
	res = append(res, mq.front())
	left, right := 1, k
	for right < len(nums) {
		if nums[left-1] == mq.front() {
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
	nums := []int{1, 3, 1, 2, 0, 5}
	k := 3
	res := maxSlidingWindow(nums, k)
	fmt.Printf("%v\n", res)
}
