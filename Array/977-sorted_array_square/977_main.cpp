#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

示例 2：
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]

提示：
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 已按 非递减顺序 排序
*/

class Solution
{
public:
    vector<int> sortedSquares_Violence(vector<int> &nums)
    {
        // 暴力解法：先平方再排序
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = pow(nums[i], 2);
        }
        sort(nums.begin(), nums.end());
        return nums;
    }

    vector<int> sortedSquares(vector<int> &nums)
    {
        // 思路：左右双指针
        // 原数组可能有负数，这样平方之后，“两头”的数总是最大的
        vector<int> res(nums.size());
        int curLast = res.size() - 1; // 待填入的位置
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int ls = pow(nums[left], 2);
            int rs = pow(nums[right], 2);
            if (ls > rs)
            {
                res[curLast--] = ls;
                left++;
            }
            else
            {
                res[curLast--] = rs;
                right--;
            }
        }
        return res;
    }
};
