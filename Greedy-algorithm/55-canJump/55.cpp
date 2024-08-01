#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

示例 1：
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

示例 2：
输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
*/

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        /**
         * 贪心，不断尝试往远了跳
         * 维护一个最远距离farDist，如果它比当前下标小了说明无法跳更远
         */
        int farDist = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (farDist < i)
                return false;
            farDist = max(farDist, i + nums[i]);
        }
        return true;
    }
};

class Solution2 // 二刷
{
public:
    bool canJump(vector<int> &nums)
    {
        int farDist = 0; // 维护一个能到达的最长距离farDist
        for (int i = 0; i < nums.size(); ++i)
        {
            if (farDist < i)
                return false;
            farDist = max(farDist, i + nums[i]);
        }
        return true;
    }
};