#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组
是数组中的一个连续部分。

示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2：
输入：nums = [1]
输出：1

示例 3：
输入：nums = [5,4,-1,7,8]
输出：23
*/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        /**
         * 思路：贪心算法
         * 遍历nums并累加
         * 若当前和变为负数，则从下一个数字开始重新从0累加
         * 因为和为负数时，再往下加只会“拖累”后面的和
         * 每次更新最大和，以保留结果
         */

        int i = 0;
        int curSum = 0, maxSum = -1e5;
        while (i < nums.size())
        {
            curSum += nums[i];
            maxSum = max(curSum, maxSum);
            if (curSum < 0)
            {
                curSum = 0;
                i++;
                continue;
            }
            i++;
        }
        return maxSum;
    }
};

int main()
{
    vector<int> nums = {-1};
    Solution obj;
    cout << "res: " << obj.maxSubArray(nums) << endl;

    return 0;
}