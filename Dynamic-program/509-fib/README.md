# 509. 斐波那契数

[点此跳转题目链接](https://leetcode.cn/problems/fibonacci-number/description/)

## 题目描述

**斐波那契数** （通常用 `F(n)` 表示）形成的序列称为 **斐波那契数列** 。该数列由 `0` 和 `1` 开始，后面的每一项数字都是前面两项数字的和。也就是：

```
F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
```

给定 `n` ，请计算 `F(n)` 。

 

**示例 1：**

```
输入：n = 2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1
```

**示例 2：**

```
输入：n = 3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2
```

**示例 3：**

```
输入：n = 4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3
```

 

**提示：**

- `0 <= n <= 30`



## 题解

动态规划究极入门题目 ( :dog: )

可以递归秒杀：

```cpp
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
```

也可以采用动态规划解决：

- dp数组的含义： `dp[i]` 表示第i个斐波那契数的值
- 状态转移方程：根据斐波那契数列的定义，有 `dp[i] = dp[i - 1] + dp[i - 2]` 

```cpp
int fib(int n) 
{
    if (n <= 1)
        return n;
    vector<int> dp(n);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; ++i) 
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
```

动态规划基础参见 [代码随想录-动态规划理论基础](https://programmercarl.com/动态规划理论基础.html#动态规划的解题步骤) 。

 