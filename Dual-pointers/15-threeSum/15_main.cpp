#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。


示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 思路：有条件的三重循环，对应三个数字
        int n = nums.size();
        sort(nums.begin(), nums.end()); // 先排序，便于之后枚举
        int targetSum;                  // 需要的第二、三个数字之和
        vector<vector<int>> res;

        for (int first = 0; first < n; ++first)
        {
            if (first > 0 && nums[first] == nums[first - 1])
                continue; // 为了避免重复，需与上一次枚举的数不同
            targetSum = -nums[first];

            /**
             * 采用双指针，让third从后往前（从大到小）找
             * 注意这里的third无需每次枚举second时重新赋值为n-1
             */
            int third = n - 1;

            for (int second = first + 1; second < n - 1; ++second)
            {
                if (second > first + 1 && nums[second] == nums[second - 1]) // 避免重复
                    continue;
                while (second < third && nums[second] + nums[third] > targetSum)
                {
                    third--;
                }
                if (second == third) // 之后的second会变大，故二三数之和肯定会更大，不会达到target
                    break;
                if (nums[second] + nums[third] == targetSum)
                    res.push_back({nums[first], nums[second], nums[third]});
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums;
    string line, numStr;
    cout << "please input the nums: ";
    getline(cin, line);
    stringstream ss(line);
    while (ss >> numStr)
    {
        nums.push_back(stoi(numStr));
    }

    Solution obj;
    vector<vector<int>> res = obj.threeSum(nums);
    cout << "result: " << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}