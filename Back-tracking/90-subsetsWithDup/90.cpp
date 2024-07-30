#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> used;

public:
    void backTracking(const vector<int> &nums, int start) {
        // 求全部子集：每次都要将path加入结果集res
        res.push_back(path);
        // 递归出口（纵向遍历）
        if (start >= nums.size())
            return;
        // 横向遍历
        for (int i = start; i < nums.size(); ++i) {
            // 去重
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            // 处理
            path.push_back(nums[i]);
            used[i] = 1;
            // 递归
            backTracking(nums, i + 1);
            // 回溯
            path.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        used.resize(nums.size());
        sort(nums.begin(), nums.end()); // 先排序，便于去重
        backTracking(nums, 0);
        return res;
    }
};