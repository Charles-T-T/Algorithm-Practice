#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <functional>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> used;

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
            // 去重
            if (i > start && candidates[i] == candidates[i - 1] && !used[i - 1])
                continue;
            // 处理
            path.push_back(candidates[i]);
            curSum += candidates[i];       
            used[i] = 1;
            // 递归
            backTracking(candidates, target, curSum, i + 1); 
            // 回溯
            path.pop_back();                                 
            curSum -= candidates[i];
            used[i] = 0;
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        used.resize(candidates.size());
        sort(candidates.begin(), candidates.end()); // 先排序，便于搜索过程中去重
        backTracking(candidates, target, 0, 0);
        return res;
    }
};

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    Solution obj;
    vector<vector<int>> res = obj.combinationSum2(candidates, 8);
    
    cout << "[ ";
    for (auto vec : res) {
        cout << "[ ";
        for (int num : vec)
            cout << num << " ";
        cout << "]";
    }
    cout << "]" << endl;

    return 0;
}