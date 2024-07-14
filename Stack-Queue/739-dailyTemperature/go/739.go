package main

import "fmt"

func dailyTemperatures(temperatures []int) []int {
	res := make([]int, len(temperatures))
	for cur := len(temperatures) - 2; cur >= 0; cur-- {
		after := cur + 1
		for temperatures[after] <= temperatures[cur] && res[after] != 0 {
			after += res[after]
		}
		if temperatures[after] > temperatures[cur] {
			res[cur] = after - cur
		}
	}
	return res
}

func main() {
	t := []int{30, 40, 50, 60}
	res := dailyTemperatures(t)
	fmt.Printf("%v\n", res)
}