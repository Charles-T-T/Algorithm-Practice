#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // dp[i][j]: 最多有i个0和j个1的子集的最大长度
        // 对于新的二进制字符串k，其中0和1数量为k_0和k_1:
        // dp[i][j] = max(dp[i][j], dp[i - k_0][j - k_1] + 1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string &str : strs) {
            int zeroCount = count(str.begin(), str.end(), '0');
            int oneCount = count(str.begin(), str.end(), '1');
            for (int i = m; i >= zeroCount; --i) {
                for (int j = n; j >= oneCount; --j) 
                    dp[i][j] = max(dp[i][j], dp[i - zeroCount][j - oneCount] + 1);
            }
        }
        return dp[m][n];
    }
};