#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1I // 分段+普通股票规划，超时
{
private:
    int simpleMax(const vector<int> &prices, int start, int end) {
        int low = INT_MAX, res = 0;
        for (int i = start; i < end; ++i) {
            low = min(low, prices[i]);
            res = max(res, prices[i] - low);
        }
        return res;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        for (int i = 0; i < prices.size(); ++i) {
            // if (i == 6)
            //     cout << "pause" << endl;
            // res = max(simpleMax(prices, 0, i), simpleMax(prices, i, prices.size()));
            int v1 = simpleMax(prices, 0, i);
            int v2 = simpleMax(prices, i, prices.size());
            res = max(res, v1 + v2);
        }
        return res;
    }
};

class Solution1II // 动态规划
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(4, INT_MIN / 2));
        dp[0][0] = -prices[0]; // 第一天若要操作，只能买入
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }
        return max(0, max(dp.back()[1], dp.back()[3])); // 如果股票一直跌，不如不买
    }

    // 滚动数组
    int maxProfitII(vector<int> &prices)
    {
        vector<int> dp(4, INT_MIN / 2);
        dp[0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp[0] = max(dp[0], -prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[2] = max(dp[2], dp[1] - prices[i]);
            dp[3] = max(dp[3], dp[2] + prices[i]);
        }
        return max(0, max(dp[1], dp[3]));
    }
};

int main() {
    vector<int> prices = {1, 2, 3, 4, 5};
    Solution1I obj;
    cout << obj.maxProfit(prices) << endl;
    return 0;
}