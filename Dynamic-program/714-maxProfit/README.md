# 714. 买卖股票的最佳时机含手续费

[点此跳转题目链接](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

## 题目描述

给定一个整数数组 `prices`，其中 `prices[i]`表示第 `i` 天的股票价格 ；整数 `fee` 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

**注意：** 这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

 

**示例 1：**

```
输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
输出：8
解释：能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
```

**示例 2：**

```
输入：prices = [1,3,7,5,10,3], fee = 3
输出：6
```

 

**提示：**

- `1 <= prices.length <= 5 * 104`
- `1 <= prices[i] < 5 * 104`
- `0 <= fee < 5 * 104`



## 题解

在普通的股票问题基础上增加了一个手续费，但这个手续费又并不是变化的，所以完全没影响 :rofl: ​，每次考虑卖出的时候把手续费扣除即可。

动态规划秒了，此类问题的详细思路可参见我之前写的 [CSDN-股票问题 I](https://blog.csdn.net/weixin_54468359/article/details/141615047?spm=1001.2014.3001.5501) 。

**代码（C++）**

```cpp
int maxProfit(vector<int> &prices, int fee)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
    dp[0][1] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp.back()[0];
}
```

**Python**

```python
def maxProfit(self, prices: List[int], fee: int) -> int:
    dp = [[0, 0] for _ in range(len(prices))]
    dp[0][1] = -prices[0]

    for i in range(1, len(prices)):
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee)
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])

    return dp[-1][0]
```

**Golang**

```go
func maxProfit(prices []int, fee int) int {
	dp := make([][2]int, len(prices))
	dp[0][1] = -prices[0]

	for i := 1; i < len(prices); i++ {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]-fee)
		dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i])
	}

	return dp[len(prices)-1][0]
}
```

