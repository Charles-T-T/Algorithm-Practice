#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1I // 贪心算法
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0)
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};

class Solution1II // 动态规划
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        }
        return dp.back()[0];
    }

    // 简化为滚动数组
    int maxProfitII(vector<int> &prices)
    {
        vector<int> dp = {0, -prices[0]};
        for (int i = 1; i < prices.size(); ++i) {
            dp[0] = max(dp[0], dp[1] + prices[i]);
            dp[1] = max(dp[1], dp[0] - prices[i]);
        }
        return dp[0];
    }
};