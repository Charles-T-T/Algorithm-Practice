#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    // 普通的打家劫舍
    int robRange(const vector<int> &nums, int start, int end)
    {
        if (end == start)
            return nums[start];
        vector<int> dp(end - start + 1);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i < dp.size(); ++i)
            dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]);
        return dp[end - start];
    }

public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution obj;
    cout << obj.rob(nums) << endl;
    return 0;
}