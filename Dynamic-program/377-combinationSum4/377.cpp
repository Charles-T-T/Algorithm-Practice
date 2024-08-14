#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= target; ++j) {
            for (int num : nums) {
                if (j >= num && INT_MAX - dp[j] > dp[j - num])
                    dp[j] += dp[j - num];
            }
        }
        return dp[target];
    }
};