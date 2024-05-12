#include <iostream>
#include <vector>

using namespace std;

/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的
子集
（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

示例 2：
输入：nums = [0]
输出：[[],[0]]
*/

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

public:
    void BackTracking(const vector<int> &nums, int len, int start)
    {
        // 确定递归出口
        if (start == len)
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);            // 处理
            BackTracking(nums, len, i + 1); // 递归
            path.pop_back();                    // 回溯
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        for (int i = 0; i <= nums.size(); i++)
        {
            BackTracking(nums, i, 0);
        }
        return res;
    }
};

void Display(vector<vector<int>> nums)
{
    cout << "[ ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < nums[i].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution obj;
    vector<vector<int>> res = obj.subsets(nums);
    Display(res);

    return 0;
}
