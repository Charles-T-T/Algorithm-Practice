package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func firstMissingPositive(nums []int) int {
	n := len(nums)
	// 长度为 n 的数组，其中缺失的最小正整数，最大为 n + 1
	// 先将非正数全部改成 n + 1
	for i := range nums {
		if nums[i] <= 0 {
			nums[i] = n + 1
		}
	}
	// 然后检查新 nums，并标记那些小于 n + 1 的数
	// 标记方法为在另一个数组 tmp 中，将数值减一作为下标，设为 -1
	// 这样，顺序读取 tmp，遇到不是 -1 的，就说明在 nums 中出现了
	// “不连续”的正数，缺的那个就是下标加一
	// e.g.
	// -2 -3 0 2 1 3 9 5
	// 9 9 9 2 1 3 9 5
	// -1 -1 -1 2 -1 3 9 5
	// 这里第一个正数（2）对应下标为 3，因此断定缺的是 4
	tmp := make([]int, n)
	copy(tmp, nums)
	for _, num := range nums {
		if num < n+1 {
			tmp[num-1] = -1
		}
	}
	for i, v := range tmp {
		if v > 0 {
			return i + 1
		}
	}
	return n + 1
}

func main() {
	nums := make([]int, 0)
	fmt.Print("input the nums: ")
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	fields := strings.Fields(line)
	for _, field := range fields {
		num, _ := strconv.Atoi(field)
		nums = append(nums, num)
	}
	
	fmt.Println("result: ", firstMissingPositive(nums))
}