package main

import (
	"fmt"
)

func min(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func minPathSum(grid [][]int) int {
	row := len(grid)
	col := len(grid[0])
	dp := make([][]int, row)
	for i := range dp {
		dp[i] = make([]int, col)
	}

	for i := range dp {
		for j := range dp[i] {
			if i == 0 && j == 0 {
				dp[i][j] = grid[0][0]
			} else if i == 0 {
				dp[i][j] = dp[i][j-1] + grid[i][j]
			} else if j == 0 {
				dp[i][j] = dp[i-1][j] + grid[i][j]
			} else {
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
			}
		}
	}

	return dp[row-1][col-1]
}

func main() {
	fmt.Printf("Please input row and col num: ")
	var m, n int
	fmt.Scan(&m, &n)
	
	grid := make([][]int, m)
	fmt.Println("Please input values in the gird, divided by space and enter:")
	for i := range grid {
		grid[i] = make([]int, n)
		for j := range grid[i] {
			fmt.Scan(&grid[i][j])
		}
	}

	fmt.Printf("Result: %d\n", minPathSum(grid))
}