#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;

public:
    void backTracking(const vector<int> &nums, int start)
    {
        // 每次将当前非递减子序列加入结果集
        if (path.size() > 1)
            res.push_back(path);
        // 递归出口（纵向遍历）
        if (start >= nums.size())
            return;
        // 横向遍历
        unordered_set<int> used; // 记录本层节点用过的值
        for (int i = start; i < nums.size(); ++i)
        {
            // 去重
            if (used.find(nums[i]) != used.end())
                continue;
            used.insert(nums[i]);
            // 处理
            if (path.empty() || nums[i] >= path.back())
                path.push_back(nums[i]);
            else
                continue;
            backTracking(nums, i + 1); // 递归
            path.pop_back();           // 回溯
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backTracking(nums, 0);
        return res;
    }
};

int main()
{
    vector<int> nums = {4, 6, 7, 7};
    Solution obj;
    vector<vector<int>> res = obj.findSubsequences(nums);

    cout << "[ ";
    for (auto vec : res)
    {
        cout << "[";
        for (int i = 0; i < vec.size(); ++i)
        {
            cout << vec[i];
            if (i < vec.size() - 1)
                cout << ", ";
        }
        cout << "] ";
    }
    cout << "]";

    return 0;
}