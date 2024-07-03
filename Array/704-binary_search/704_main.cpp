#include <iostream>
#include <vector>
#include <sstream>

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
    // 左闭右闭写法
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int middle;
        while (left <= right)
        {
            middle = left + (right - left) / 2; // 防溢出的写法
            if (nums[middle] == target)
                return middle;
            if (nums[middle] < target)
            {
                left = middle + 1;
                continue;
            }
            if (nums[middle] > target)
            {
                right = middle - 1;
                continue;
            }
        }
        return -1; // target不存在于nums中
    }

    // 左闭右开写法
    int searchII(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(); // 这里体现了“右开”
        int middle;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (nums[middle] == target)
                return middle;
            if (nums[middle] < target)
            {
                // “左闭”意味着不用再检查左边界
                left = middle + 1;
                continue;
            }
            if (nums[middle] > target)
            {
                // “右开”意味着要检查右边界
                right = middle;
                continue;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums;
    int target;
    cout << "please input the target: ";
    cin >> target;
    cin.ignore();

    string input;
    cout << "please input the nums, divided by space: ";
    getline(cin, input);
    stringstream ss(input);
    int num;
    while (ss >> num)
    {
        nums.push_back(num);
    }

    Solution obj;
    cout << "location: " << obj.search(nums, target);
    return 0;
}