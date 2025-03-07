package main

import (
	"fmt"
)

func beautifulSubarrays(nums []int) int64 {
	xor_prefix_sums_cnt := make(map[int]int64)
	xor_prefix_sums_cnt[0] = 1
	var beautiful_cnt int64 = 0
	cur_xor_prefix_sum := 0
	for _, num := range nums {
		cur_xor_prefix_sum ^= num
		beautiful_cnt += xor_prefix_sums_cnt[cur_xor_prefix_sum]
		xor_prefix_sums_cnt[cur_xor_prefix_sum]++
	}
	return beautiful_cnt
}

func main() {
	nums := []int{4, 3, 1, 2, 3}
	fmt.Println(beautifulSubarrays(nums))
}
