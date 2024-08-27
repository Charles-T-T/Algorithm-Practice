#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1I // 贪心算法
{
public:
    int maxProfit(vector<int> &prices)
    {
        int low = INT_MAX;
        int profit = INT_MIN;
        for (int price : prices) {
            low = min(low, price);       // 更新左边最小值
            profit = max(profit, price - low); // 更新最大差值
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
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][1] = max(dp[i - 1][1], -prices[i]); // 手上有股票
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); // 手上没股票
        }
        return dp.back()[0];
    }

    // 简化为滚动数组
    int maxProfitII(vector<int> &prices)
    {
        vector<int> dp = {0, -prices[0]};
        for (int i = 1; i < prices.size(); ++i) {
            dp[1] = max(dp[1], -prices[i]); // 当前持有股票
            dp[0] = max(dp[0], dp[1] + prices[i]); // 当前不持有股票
        }
        return dp[0];
    }
};

