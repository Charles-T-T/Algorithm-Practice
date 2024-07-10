package main

import "fmt"

func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
	abSumMap := make(map[int]int)
	for _, a := range nums1 {
		for _, b := range nums2 {
			abSumMap[a+b]++
		}
	}
	count := 0
	for _, c := range nums3 {
		for _, d := range nums4 {
			count += abSumMap[-c-d]
		}
	}
	return count
}

func main() {
	nums1 := []int{1, 2}
	nums2 := []int{-2, -1}
	nums3 := []int{-1, 2}
	nums4 := []int{0, 2}

	fmt.Println("result:", fourSumCount(nums1, nums2, nums3, nums4))
}