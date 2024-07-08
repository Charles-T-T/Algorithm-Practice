package main

import "fmt"

func twoSum(nums []int, target int) []int {
	numMap := make(map[int]int)
	for i, num := range nums {
		numMap[num] = i
	}

	res := make([]int, 2)
	for i, num := range nums {
		pos, ok := numMap[target - num]
		if ok && pos != i {
			res[0] = pos
			res[1] = i
			break
		}
	}
	return res
}

func main() {
	fmt.Println("test")
}