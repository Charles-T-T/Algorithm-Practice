package main

import "fmt"

func leftChildID(id int) int {
	return id*2 + 1
}

func rightChildID(id int) int {
	return id*2 + 2
}

func heapfyDown(heap []int, i int) {
	n := len(heap)
	for i < n-1 {
		left := leftChildID(i)
		right := rightChildID(i)
		largest := i
		if left < n && heap[left] > heap[largest] {
			largest = left
		}
		if right < n && heap[right] > heap[largest] {
			largest = right
		}
		if largest != i {
			heap[largest], heap[i] = heap[i], heap[largest]
			i = largest
		} else {
			return
		}
	}
}

func topKFrequent(nums []int, k int) []int {
	num2cnt := make(map[int]int)
	cnt2num := make(map[int][]int)
	heap := make([]int, 0, len(nums))
	for _, num := range nums {
		num2cnt[num]++
	}
	for num, cnt := range num2cnt {
		cnt2num[cnt] = append(cnt2num[cnt], num)
		heap = append(heap, cnt)
	}
	// 按频数建立大根堆
	for i := len(nums)/2 - 1; i >= 0; i-- {
		heapfyDown(heap, i)
	}
	// 从大根堆中取出 top k
	res := make([]int, 0, k)
	for range k {
		// 找出当前最大频数对应的数字
		curMaxCnt := heap[0]
		targetNums := cnt2num[curMaxCnt]
		res = append(res, targetNums[len(targetNums)-1])
		cnt2num[curMaxCnt] = cnt2num[curMaxCnt][:len(targetNums)-1]
		// 更新大根堆
		heap[0] = heap[len(heap)-1]
		heap = heap[:len(heap)-1]
		heapfyDown(heap, 0)
	}
	return res
}

func main() {
	nums := []int{1,2,1,2,1,2,3,1,3,2}
	k := 2
	fmt.Println(topKFrequent(nums, k))
}
