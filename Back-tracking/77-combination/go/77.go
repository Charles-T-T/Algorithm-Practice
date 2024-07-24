package main

import "fmt"

type Helper struct {
	path []int
	res  [][]int
}

func (helper *Helper) backTracking(start int, end int, k int) {
	// 递归出口
	if len(helper.path) == k {
		// newPath := make([]int, len(helper.path))
		// copy(newPath, helper.path)
		// helper.res = append(helper.res, newPath)
		helper.res = append(helper.res, append([]int(nil), helper.path...))
		return
	}
	// 横向遍历
	for i := start; i <= end; i++ {
		helper.path = append(helper.path, i)           // 处理
		helper.backTracking(i+1, end, k)               // 递归
		helper.path = helper.path[:len(helper.path)-1] // 回溯
	}
}

func combine(n int, k int) [][]int {
	helper := Helper{}
	helper.backTracking(1, n, k)
	return helper.res
}

func main() {
	res := combine(4, 2)
	fmt.Println(res)
}
