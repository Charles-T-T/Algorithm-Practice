package main

import	"fmt"

var	result [][]int
var path []int

func appendCopy(result [][]int, path []int) [][]int {
	tmp := make([]int, len(path))
	copy(tmp, path)
	return append(result, tmp)
}

func backTracking(n int, start int, k int) {
	if len(path) == k {
		result = appendCopy(result, path)
		return
	}

	for i := start; i <= n; i++ {
		path = append(path, i)
		backTracking(n, i + 1, k)
		path = path[:len(path)-1]
	} 
}

func combine(n int, k int) [][]int {
	result = make([][]int, 0)
	path = make([]int, 0)
	backTracking(n, 1, k)

	return result
}

func main() {
	var n int
	var k int
	fmt.Printf("Please input n and k: ")
	fmt.Scanf("%d %d", &n, &k)
	fmt.Println("n, k: ", n, k)
	combine(n, k)
	fmt.Println(result)
}