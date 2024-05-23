#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

示例 1：
输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 2：
输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
*/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        if (len == 2)
            return max(nums[0], nums[1]);

        // dp[i]表示只考虑前i家的情况下能得到的最高金额
        vector<int> dp = {nums[0], max(nums[0], nums[1])};
        dp.resize(len);
        for (int i = 2; i < len; ++i){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[len - 1];
    }
};

int main(){
    vector<int> nums = {2, 1, 1, 2};
    Solution obj;
    cout << "res: " << obj.rob(nums) << endl;

    return 0;
}