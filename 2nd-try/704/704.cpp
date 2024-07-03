#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 左闭右闭写法
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int middle;
        while (left <= right) {
            middle = left + (right - left) / 2; // 防溢出的写法
            if (nums[middle] == target) 
                return middle;
            if (nums[middle] < target) {
                left = middle + 1;
                continue;
            }
            if (nums[middle] > target) {
                right = middle - 1;
                continue;
            }
        }
        return -1;
    }

    // 左闭右开写法
    int searchII(vector<int> &nums, int target) {
        int left = 0, right = nums.size(); // 这里体现了“右开”
        int middle;
        while (left < right) {
            middle = left + (right - left) / 2;
            if (nums[middle] == target) 
                return middle;
            if (nums[middle] < target) {
                // “左闭”意味着不用再检查左边界
                left = middle + 1;
                continue;
            }
            if (nums[middle] > target) {
                // “右开”意味着要检查右边界
                right = middle;
                continue;
            }
        }
        return -1;
    }
};