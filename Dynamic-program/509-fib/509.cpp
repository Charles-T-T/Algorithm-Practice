#include <iostream>
#include <vector>

using namespace std;

/*
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给定 n ，请计算 F(n) 。

示例 1：
输入：n = 2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1

示例 2：
输入：n = 3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2

示例 3：
输入：n = 4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3
*/

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else
            return fib(n - 1) + fib(n - 2);
    }

    int fib_dynamic(int n)
    {
        if (n <= 1)
            return n;
        int dp[n + 1];
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

class Solution2 // 二刷
{
public:
    int fib(int n) // 递归
    {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }

    int fibII(int n) // 动态规划
    {
        if (n <= 1)
            return n;
        vector<int> dp(n);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; ++i) 
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

int main() {
    Solution2 obj;
    cout << obj.fibII(3) << endl;
    return 0;
}