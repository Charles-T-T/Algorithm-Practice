#include <iostream>
#include <vector>

using namespace std;

/*
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

示例 1:
输入: nums = [1,2,3,4]
输出: [24,12,8,6]

示例 2:
输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]
*/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size(), 0);

        // 从前往后、从后往前在零元位置（如果有）乘两遍
        // m1：第一遍累乘；m2：第二遍累乘
        int m1 = 1, m2 = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            res[i] = m1;
            m1 *= nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            res[i] *= m2;
            m2 *= nums[i];
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    Solution obj;
    vector<int> res = obj.productExceptSelf(nums);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}