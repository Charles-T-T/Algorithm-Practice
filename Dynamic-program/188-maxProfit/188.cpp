#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        
        // 奇数：持有；偶数：不持有
        for (int j = 0; j < 2 * k; j += 2) 
            dp[0][j + 1] = -prices[0];
        
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 0; j < 2 * k - 1; j += 2) {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }

        return dp.back().back();
    }
};

int main() {
    int k = 2;
    vector<int> prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    Solution obj;
    cout << obj.maxProfit(k, prices) << endl;

    return 0;
}