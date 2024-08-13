package main

import "fmt"

func findMaxForm(strs []string, m int, n int) int {
	dp := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		dp[i] = make([]int, n+1)
	}
	for _, str := range strs {
		zeroCount, oneCount := 0, 0
		for _, c := range str {
			if c == '0' {
				zeroCount++
			}
			if c == '1' {
				oneCount++
			}
		}
		for i := m; i >= zeroCount; i-- {
			for j := n; j >= oneCount; j-- {
				dp[i][j] = max(dp[i][j], dp[i-zeroCount][j-oneCount]+1)
			}
		}
	}
	return dp[m][n]
}

func main() {
	fmt.Println(findMaxForm([]string{"10", "0001", "111001", "1", "0"}, 5, 3))
}
