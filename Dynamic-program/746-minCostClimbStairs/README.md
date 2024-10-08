# 746. 使用最小花费爬楼梯

[点此跳转题目链接](https://leetcode.cn/problems/min-cost-climbing-stairs/description/)

## 题目描述

给你一个整数数组 `cost` ，其中 `cost[i]` 是从楼梯第 `i` 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 `0` 或下标为 `1` 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。

 

**示例 1：**

```
输入：cost = [10,15,20]
输出：15
解释：你将从下标为 1 的台阶开始。
- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
总花费为 15 。
```

**示例 2：**

```
输入：cost = [1,100,1,1,1,100,1,1,100,1]
输出：6
解释：你将从下标为 0 的台阶开始。
- 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
- 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
- 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
- 支付 1 ，向上爬一个台阶，到达楼梯顶部。
总花费为 6 。
```

 

**提示：**

- `2 <= cost.length <= 1000`
- `0 <= cost[i] <= 999`



## 题解

动态规划入门题目。显然，爬到第 `i` 个台阶有两种方法：

- 从第 `i - 1` 个台阶向上爬1阶，对应花费：爬到第 `i - 1` 个台阶的花费 + 第 `i - 1` 这一级的花费（即 `cost[i - 1]` ）
- 从第 `i - 2` 个台阶向上爬2阶，对应花费：爬到第 `i - 2` 个台阶的花费 + 第 `i - 2` 这一级的花费（即 `cost[i - 2]` ）

为了求得总的最小花费，每次确定爬到第 `i` 个台阶的花费时，也应该取上述两种方法种花费最小的那一种（有贪心内味了）。因此，可以确定：

-  `dp` 数组的含义： `dp[i]` 表示爬到第 `i` 个台阶的最小花费
- 状态转移方程： `dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])` 

**代码（C++）**

```cpp
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1);
    dp[0] = 0, dp[1] = 0;
    for (int i = 2; i <= n; ++i)
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    return dp[n];
}
```

> :warning: 注意，题目要求的“楼梯顶部”是最后一级台阶再往上一级的位置，所以 `dp` 数组开 `n + 1` 的大小、返回的也是 `dp[n]` 