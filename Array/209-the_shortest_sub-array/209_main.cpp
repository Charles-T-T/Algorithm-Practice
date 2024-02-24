#include <iostream>
#include <vector>

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
    int minSubArrayLen1(int target, vector<int> &nums)
    {
        // 思路：双指针
        int left = 0, right = 0;
        int sum = nums[left];

        // 如果第一个就>=target
        if (sum >= target)
            return 1;

        while (sum < target && right < nums.size() - 1)
            sum += nums[++right];

        // 如果整个nums加起来也没有target大
        if (sum < target)
            return 0;

        // 到这里则说明存在符合条件的不为0的length
        while (right < nums.size() - 1)
        {
            sum = sum + nums[++right] - nums[left++];
            while (sum > target)
            {
                // 可以尝试（从左边）缩小子数组长度
                sum -= nums[left];
                if (sum >= target)
                {
                    left++;
                    continue;
                }
                sum += nums[left];
                break;
            }
        }

        while (sum > target)
        {
            // 可以尝试（从左边）缩小子数组长度
            sum -= nums[left];
            if (sum >= target)
            {
                left++;
                continue;
            }
            sum += nums[left];
            break;
        }

        return right - left + 1;
    }

    // Carl's version
    int minSubArrayLen2(int target, vector<int> &nums)
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

int main()
{
    vector<int> nums;
    int target, n;
    cout << "please input the target: ";
    cin >> target;
    cout << "please input the length of nums: ";
    cin >> n;

    int num;
    cout << "please input the nums, divided by space:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        nums.push_back(num);
    }

    Solution obj;
    cout << "Result: " << obj.minSubArrayLen1(target, nums) << endl;

    return 0;
}