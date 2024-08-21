#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 1：
输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4

示例 2：
输入：n = 13
输出：2
解释：13 = 4 + 9
*/

class Solution {
public:
    int numSquares(int n) {
        /**
         * 动态规划
         * dp[i]为表示i所需的完全平方数的最少数量
         * 显然，这些完全平方数的范围是[1, sqrt(i)]
         * 假设遍历到其中一个数为j，那么还需要i - j^2
         * 此时dp[i] = 1 + min(dp[i - j^2])
        */ 
        if (n == 1)
            return 1;

        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i){
            int curMin = 1e9;
            for (int j = 1; j * j <= i; ++j){
                curMin = min(curMin, dp[i - j * j]); 
            }
            dp[i] = curMin + 1;
        }
        return dp[n];
    }
};

class Solution2 // 二刷
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; pow(i, 2) <= n; ++i) {
            for (int j = pow(i, 2); j <= n; ++j)
                dp[j] = min(dp[j], dp[j - pow(i, 2)] + 1);
        }
        return dp[n];
    }
};

int main(){
    int n = 12;
    Solution obj;
    cout << "res: " << obj.numSquares(n) << endl;

    return 0;
}