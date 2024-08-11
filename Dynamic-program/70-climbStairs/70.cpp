#include <iostream>
#include <vector>

using namespace std;

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
示例 1：
输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶

示例 2：
输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
*/

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int dp[n + 1];
        dp[0] = 0, dp[1] = 1, dp[2] = 2;
        for (int i = 3; i < n + 1; i++)
        {
            /**
             * 上到第i级的方法：
             * 1. 上前i - 1级，再上一级
             * 2. 上前i - 2级，再上两级
             */
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

#include <iostream>

using namespace std;

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
示例 1：
输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶

示例 2：
输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
*/

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int dp[n + 1];
        dp[0] = 0, dp[1] = 1, dp[2] = 2;
        for (int i = 3; i < n + 1; i++)
        {
            /**
             * 上到第i级的方法：
             * 1. 上前i - 1级，再上一级
             * 2. 上前i - 2级，再上两级
             */
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

class Solution2 // 二刷
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};