package main

import "fmt"

func findLength(nums1 []int, nums2 []int) int {
	length := 0
	d := make([][]int, len(nums1)+1)
	for i := range d {
		d[i] = make([]int, len(nums2)+1)
	}

	for i := 1; i <= len(nums1); i++ {
		for j := 1; j <= len(nums2); j++ {
			if nums1[i-1] == nums2[j-1] {
				d[i][j] = d[i-1][j-1] + 1
				length = max(length, d[i][j])
			}
		}
	}

	return length
}

func main() {
	nums1 := []int{1, 2, 3, 2, 1}
	nums2 := []int{3, 2, 1, 4, 7}
	fmt.Println(findLength(nums1, nums2))
}