package main

import "fmt"

func jump(nums []int) int {
	farest_dist := 0
	cover_dist := 0
	hop_cnt := 0
	for i := 0; i < len(nums)-1; i++ {
		if i+nums[i] > farest_dist {
			farest_dist = i + nums[i]
		}
		if i >= cover_dist {
			hop_cnt++
			cover_dist = farest_dist
		}
		if cover_dist >= len(nums)-1 {
			break
		}
	}
	return hop_cnt
}

func main() {
	nums := []int{2, 3, 1, 1, 4}
	fmt.Println(jump(nums))
}