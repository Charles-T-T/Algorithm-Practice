#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 动态规划经典入门
        // 确定dp数组：dp[i]表示到达第i级台阶有多少种方法
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++){
            /**
             * 到达第i级无非两条路：
             * 1. 从第i - 1级爬一级
             * 2. 从第i - 2级爬两级
            */
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};