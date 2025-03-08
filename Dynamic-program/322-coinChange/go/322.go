package main

import (
	"fmt"
	"sort"
)

func coinChange(coins []int, amount int) int {
	// dp[i]: 凑成 i 需要的最少硬币个数
	sort.Ints(coins)
	dp := make([]int, amount+1)
	for i := range dp {
		dp[i] = amount + 1
	}
	dp[0] = 0
	for i := coins[0]; i <= amount; i++ {
		for j := 0; j < len(coins); j++ {
			if coins[j] <= i {
				dp[i] = min(dp[i], dp[i-coins[j]]+1)
			}
		}
	}
	if dp[amount] > amount {
		return -1
	} else {
		return dp[amount]
	}
}

func main() {
	coins := []int{1, 2, 5}
	fmt.Println(coinChange(coins, 11))
}
