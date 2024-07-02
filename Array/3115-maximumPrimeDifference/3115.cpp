#include <iostream>
#include <vector>

using namespace std;

/*
给你一个整数数组 nums。

返回两个（不一定不同的）质数在 nums 中 下标 的 最大距离。

示例 1：
输入： nums = [4,2,9,5,3]
输出： 3
解释： nums[1]、nums[3] 和 nums[4] 是质数。因此答案是 |4 - 1| = 3。

示例 2：
输入： nums = [4,8,2,8]
输出： 0
解释： nums[2] 是质数。因为只有一个质数，所以答案是 |2 - 2| = 0。
*/

class Solution
{
public:
    bool IsPrime(int n)
    {
        if (n == 1)
            return false;
        for (int i = 2; i < n; ++i)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int> &nums)
    {
        // 思路：双指针
        int left = -1, right = -1;
        for (int i = 0, j = nums.size() - 1; i <= j;)
        {
            if (left == -1 && IsPrime(nums[i]))
                left = i;

            if (right == -1 && IsPrime(nums[j]))
                right = j;

            if (left != -1 && right != -1)
                break;

            if (left == -1)
                ++i;
            if (right == -1)
                --j;
        }
        return right - left;
    }
};