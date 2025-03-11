package main

import "math/rand"

func majorityElement(nums []int) int {
	numCount := make(map[int]int)
	var limit int = len(nums) / 2
	for _, num := range nums {
		numCount[num]++
		if numCount[num] > limit {
			return num
		}
	}
	return 0
}

// 随机化（神奇的方法）
func majorityElement_2(nums []int) int {
	limit := len(nums) / 2
	for {
		randID := rand.Intn(len(nums))
		candidate := nums[randID]
		count := 0
		for _, num := range(nums) {
			if num == candidate {
				count++
			}
		}
		if count > limit {
			return candidate
		}
	}
}