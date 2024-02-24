#include <iostream>
#include <vector>

using namespace std;

/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
*/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid; // 左右和中间下标
        while (left <= right)
        {
            mid = left + (right - left) / 2; // 为了防止left + right溢出的写法，实际等同于(left + right) / 2
            if (nums[mid] == target)
                return mid;
            else
            {
                if (nums[mid] < target)
                {
                    left = mid + 1;
                    continue;
                }
                else
                {
                    right = mid - 1;
                    continue;
                }
            }
        }
        return -1; // nums中不存在target
    }
};

int main()
{
    vector<int> nums;
    int target, size, num;
    cout << "please input the target: ";
    cin >> target;
    cout << "please input the size of nums: ";
    cin >> size;
    cout << "please input the nums, divided by space: ";
    int i = 0;
    while (i < size)
    {
        cin >> num;
        nums.push_back(num);
        i++;
    }

    Solution solution;
    cout << "location: " << solution.search(nums, target);
    return 0;
}