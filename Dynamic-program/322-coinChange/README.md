# 322. 零钱兑换

[点此跳转题目链接](https://leetcode.cn/problems/coin-change/description/)

## 题目描述

给你一个整数数组 `coins` ，表示不同面额的硬币；以及一个整数 `amount` ，表示总金额。

计算并返回可以凑成总金额所需的 **最少的硬币个数** 。如果没有任何一种硬币组合能组成总金额，返回 `-1` 。

你可以认为每种硬币的数量是无限的。

 

**示例 1：**

```
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
```

**示例 2：**

```
输入：coins = [2], amount = 3
输出：-1
```

**示例 3：**

```
输入：coins = [1], amount = 0
输出：0
```

 

**提示：**

- `1 <= coins.length <= 12`
- `1 <= coins[i] <= 231 - 1`
- `0 <= amount <= 104`



## 题解

典型的 **完全背包问题** ——因为每种硬币的数量是无限的。同时，题目要求的是硬币的个数，也就是求组合数，故按照常规的 **先遍历物品、再遍历背包大小** 的顺序 **动态规划** 即可解决。

- `dp` 数组含义： `dp[j]` 表示凑成总金额 `j` 需要的最小硬币个数

- 状态转移方程： `dp[j] = min(dp[j], dp[j - coin] + 1)` 

  > 考虑一个新的硬币 `coin` ，如果加上它恰好凑成总金额 `j` ，则之前的总金额为 `j - coin` ，彼时所用的最小硬币个数为 `dp[j - coin]` ；加上新的这枚 `coin` ，所用硬币个数为 `dp[j - coin] + 1` 。然后取这个值和原来的 `dp[j]` 中较小的那个。

:warning: 如果凑不出则返回-1，且每次要取 `dp` 最小值，故一开始要将 `dp` 数组中的元素初始化为极大值。

**代码（C++）**

```cpp
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int coin : coins) {
        for (int j = coin; j <= amount; ++j) {
            if (dp[j - coin] < INT_MAX)
                dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
```

**go**

```go
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
```
