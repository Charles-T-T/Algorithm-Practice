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
*/

class Solution
{
public:
    vector<int> sortedSquares1(vector<int> &nums)
    {
        // 暴力解法：先平方，再用sort函数排个序
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = pow(nums[i], 2);
        }
        sort(nums.begin(), nums.end());
        return nums;
    }

    vector<int> sortedSquares2(vector<int> &nums)
    {
        // 双指针法：从两边向中间比较
        int max = nums.size() - 1;
        int left = 0, right = max;
        int leftNum, rightNum;
        vector<int> newVec(max + 1);
        while (left <= right)
        {
            leftNum = pow(nums[left], 2),  rightNum = pow(nums[right], 2);
            if (leftNum >= rightNum){
                newVec[max--] = leftNum;
                left++;
                continue;
            }
            else{
                newVec[max--] = rightNum;
                right--;
                continue;
            }
        }

        return newVec;
    }
};

int main(){
    vector<int> nums;
    int target, size, num;
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
    nums = solution.sortedSquares2(nums);

    cout << "[ ";
    for (i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}