#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(3));
        
        // 0：不持有但不是当天卖出
        // 1：持有
        // 2：当天卖出
        dp[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = dp[i - 1][1] + prices[i];
        }

        return max(dp.back()[0], dp.back()[2]);
    }
};

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    Solution obj;
    cout << obj.maxProfit(prices) << endl;

    return 0;
}