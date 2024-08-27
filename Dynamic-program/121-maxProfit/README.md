# 121. 买卖股票的最佳时机

[点此跳转题目链接](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/)

## 题目描述

给定一个数组 `prices` ，它的第 `i` 个元素 `prices[i]` 表示一支给定股票第 `i` 天的价格。

你只能选择 **某一天** 买入这只股票，并选择在 **未来的某一个不同的日子** 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 `0` 。

 

**示例 1：**

```
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
```

**示例 2：**

```
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
```

 

**提示：**

- `1 <= prices.length <= 105`
- `0 <= prices[i] <= 104`



## 题解

首先考虑最符合直觉的 **贪心算法** ：从前往后，找到“前面最小的”和“其后最大的”，求差值即可：

```cpp
int maxProfit(vector<int> &prices)
{
    int low = INT_MAX;
    int profit = INT_MIN;
    for (int price : prices) {
        low = min(low, price);             // 更新左边最小值
        profit = max(profit, price - low); // 更新最大差值
    }
    return profit;
}
```

或者考虑 **动态规划** ，其中 `dp[0]` 表示当前**不持有**股票所得的最大利润， `dp[1]` 表示当前**持有**股票所得的最大利润：

```cpp
int maxProfitII(vector<int> &prices)
{
    vector<int> dp = {0, -prices[0]};
    for (int i = 1; i < prices.size(); ++i) {
        dp[1] = max(dp[1], -prices[i]);        // 当前持有股票
        dp[0] = max(dp[0], dp[1] + prices[i]); // 当前不持有股票
    }
    return dp[0];
}
```

