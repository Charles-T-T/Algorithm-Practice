#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> branchUsed; // 记录当前树枝中使用过的元素

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
        unordered_set<int> layerUsed; // 记录当前层中使用过的元素
        for (int i = 0; i < nums.size(); ++i)
        {
            // 去重
            if (layerUsed.find(nums[i]) != layerUsed.end())
                continue; // 同一层中去重
            if (branchUsed[i])
                continue; // 同一树枝中去重
            layerUsed.insert(nums[i]);
            branchUsed[i] = 1;
            path.push_back(nums[i]); // 处理
            backTracking(nums);      // 递归
            path.pop_back();         // 回溯
            branchUsed[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        branchUsed.resize(nums.size());
        backTracking(nums);
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2};
    Solution obj;
    vector<vector<int>> res = obj.permuteUnique(nums);

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