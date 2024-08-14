# 518. 零钱兑换 II

[点此跳转题目链接](https://leetcode.cn/problems/coin-change-ii/description/)

## 题目描述

给你一个整数数组 `coins` 表示不同面额的硬币，另给一个整数 `amount` 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 `0` 。

假设每一种面额的硬币有无限个。 

题目数据保证结果符合 32 位带符号整数。

 

**示例 1：**

```
输入：amount = 5, coins = [1, 2, 5]
输出：4
解释：有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```

**示例 2：**

```
输入：amount = 3, coins = [2]
输出：0
解释：只用面额 2 的硬币不能凑成总金额 3 。
```

**示例 3：**

```
输入：amount = 10, coins = [10] 
输出：1
```

 

**提示：**

- `1 <= coins.length <= 300`
- `1 <= coins[i] <= 5000`
- `coins` 中的所有值 **互不相同**
- `0 <= amount <= 5000`



## 题解

实际上是个完全背包问题，题目可以转化为：

**用 `weights` 为 `coins` 的物品恰好装满容量为 `amount` 的背包共有多少种方法（每个物品的使用次数不限）？** 

于是采用经典的动态规划套路即可解决，其中

- `dp` 数组的含义： `dp[j]` 表示用 `coins` 凑出总金额 `j` 一共有 `dp[j]` 种方法
- 状态转移方程：对于容量为 `j` 的背包，考虑一个新的 `coins[i]` ，如果把它装进去（相应的可能要拿出其他硬币，即对应 `dp[j - coins[i]]` ）恰好装满，则自然新增了 `dp[j - coins[i]]` 种方法，所以有 `dp[j] += dp[j - coins[i]]` 

> 有关完全背包和该算法更细致的解析参见 [代码随想录](https://programmercarl.com/0518.零钱兑换II.html)  

**代码（C++）**

```cpp
int change(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); ++i) {
        for (int j = coins[i]; j <= amount; ++j)
            dp[j] += dp[j - coins[i]];
    }
    return dp[amount];
}
```

