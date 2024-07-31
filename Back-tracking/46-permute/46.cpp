#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

示例 2：
输入：nums = [0,1]
输出：[[0,1],[1,0]]

示例 3：
输入：nums = [1]
输出：[[1]]
*/

class Solution
{
private:
    vector<vector<int>> res;

public:
    void BackTracking(vector<int> &temp, int startIndex)
    {
        // 确定递归出口
        if (startIndex == temp.size())
        {
            res.push_back(temp);
            return;
        }

        for (int i = startIndex; i < temp.size(); i++)
        {
            swap(temp[startIndex], temp[i]);    // 处理
            BackTracking(temp, startIndex + 1); // 递归
            swap(temp[startIndex], temp[i]);    // 回溯
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> temp = nums;
        BackTracking(temp, 0);
        return res;
    }
};

class Solution2 // 二刷
{
private:
    vector<int> path;
    vector<vector<int>> res;

public:
    void backTracking(const vector<int> &nums, int start)
    {
        // 递归出口（纵向遍历）
        if (start >= nums.size())
        {
            res.push_back(path);
            return;
        }
        // 横向遍历
        for (int i = start; i < nums.size(); ++i)
        {
            swap(path[start], path[i]);    // 处理
            backTracking(nums, start + 1); // 递归
            swap(path[start], path[i]);    // 回溯
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        path = nums;
        backTracking(nums, 0);
        return res;
    }
};

class Solution2_2 // 二刷，标准三部曲解法
{
private:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> used; // 记录数字的使用情况，用于去重

public:
    void backTracking(const vector<int> &nums)
    {
        // 递归出口（纵向遍历）
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        // 横向遍历
        for (int i = 0; i < nums.size(); ++i)
        {
            // 去重
            if (used[i])
                continue;
            used[i] = 1;
            path.push_back(nums[i]); // 处理
            backTracking(nums);      // 递归
            path.pop_back();         // 回溯
            used[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        used.resize(nums.size());
        backTracking(nums);
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution2_2 obj;
    vector<vector<int>> res = obj.permute(nums);

    cout << "res: ";
    cout << "[ ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]" << endl;

    return 0;
}