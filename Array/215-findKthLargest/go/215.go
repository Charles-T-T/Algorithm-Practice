package main

import (
	"math/rand"
	"sync"
)

func findSeqKth(nums []int, l int, r int, k int) int {
	if l == r {
		return nums[k]
	}

	pivot_id := l + rand.Intn(r)%(r-l)
	pivot := nums[pivot_id]
	i, j := l-1, r+1

	// 这里用 goroutine 实际导致协程切换开销更大
	// 纯纯为了练练 goroutine 这样写的，实际没必要
	var wg sync.WaitGroup
	for i < j {
		wg.Add(2)

		go func() {
			defer wg.Done()
			for {
				i++
				if nums[i] >= pivot {
					break
				}
			}
		}()

		go func() {
			defer wg.Done()
			for {
				j--
				if nums[j] <= pivot {
					break
				}
			}
		}()

		wg.Wait()

		if i < j {
			nums[i], nums[j] = nums[j], nums[i]
		}
	}

	if k <= j {
		return findSeqKth(nums, l, j, k)
	} else {
		return findSeqKth(nums, j+1, r, k)
	}
}

func findKthLargest(nums []int, k int) int {
	return findSeqKth(nums, 0, len(nums)-1, len(nums)-k)
}
