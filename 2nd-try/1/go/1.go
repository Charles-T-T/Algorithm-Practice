package main

import "fmt"

func twoSum(nums []int, target int) []int {
	numMap := make(map[int]int)
	for i, num := range nums {
		numMap[num] = i
	}

	res := make([]int, 2)
	for i, num := range nums {
		pos, ok := numMap[target-num]
		if ok && pos != i {
			res[0] = pos
			res[1] = i
			break
		}
	}
	return res
}

func main() {
	nums := []int{2, 7, 11, 15}
	target := 9
	res := twoSum(nums, target)
	fmt.Printf("result: %v\n", res)
}
