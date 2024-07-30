#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

示例 1：
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。

示例 2：
输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]

示例 3：
输入: candidates = [2], target = 1
输出: []
*/

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> curComb;

public:
    void backTracking(const vector<int> &candidates, int target, int sum, int startIndex)
    {
        // 确定递归出口
        if (sum == target)
        {
            res.push_back(curComb);
            return;
        }
        if (sum > target)
            return;

        for (int i = startIndex; i < candidates.size(); i++)
        {
            // 处理
            sum += candidates[i];
            curComb.push_back(candidates[i]);

            // 递归
            backTracking(candidates, target, sum, i); // 注意这里不用i+1

            // 回溯
            sum -= candidates[i];
            curComb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backTracking(candidates, target, 0, 0);
        return res;
    }
};

// 二刷
class Solution2
{
private:
    vector<int> path;
    vector<vector<int>> res;

public:
    void backTracking(const vector<int> &candidates, int target, int curSum, int start)
    {
        // 递归出口（纵向遍历）
        if (curSum == target)
        {
            res.push_back(path);
            return;
        }

        // 剪枝
        if (curSum > target)
            return;

        // 横向遍历
        for (int i = start; i < candidates.size(); ++i)
        {
            path.push_back(candidates[i]);
            curSum += candidates[i];                     // 处理
            backTracking(candidates, target, curSum, i); // 递归
            path.pop_back();                             // 回溯
            curSum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backTracking(candidates, target, 0, 0);
        return res;
    }
};

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution2 obj;
    vector<vector<int>> res = obj.combinationSum(candidates, target);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "]";
    }
    cout << "]";

    return 0;
}
