#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。



示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
*/
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // 思路：采用快慢双指针，构成一个滑动窗口，动态更新最短长度
        int slow = 0, fast = 0;
        const int MAX = numeric_limits<int>::max();
        int minLen = MAX;
        int curSum = nums[fast];
        while (1)
        {
            if (curSum >= target)
            {
                minLen = min(minLen, fast - slow + 1);
                curSum -= nums[slow];
                slow++;
            }
            else
            {
                fast++;
                if (fast >= nums.size())
                    break;
                curSum += nums[fast];
            }
        }
        return minLen == MAX ? 0 : minLen;
    }

    // Carl's version
    int minSubArrayLen_Carl(int target, vector<int> &nums)
    {
        int left = 0, right = 0;
        int length = 1e6;
        int sum = 0;

        for (right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                int curLength = right - left + 1;
                length = curLength < length ? curLength : length;
                sum -= nums[left++];
            }
        }

        return length == 1e6 ? 0 : length;
    }
};
