#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。

示例 2：
输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
*/

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        /** 
         * 思路：
         * 确定了分割出去的一部分，剩下的自然就是另一部分
         * 只要分割部分之和为总和的一半即可
         * 
         * 转化为背包问题：
         * 容量为target的背包，能否恰好装下target价值的物品
        */
        int sum = 0, target;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false; // 总和不是偶数，必然不可能分割等和子集
        else
            target = sum / 2;

        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++){
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if (dp[target] == target)
            return true;
        else
            return false;
    }
};
 
int main(){
    vector<int> nums = {1, 5, 11, 5};
    Solution obj;
    if (obj.canPartition(nums))
        cout << "True!" << endl;
    else
        cout << "False!" << endl;

    return 0;
}