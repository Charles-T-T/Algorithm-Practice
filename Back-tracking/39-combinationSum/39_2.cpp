#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void backTracking(int start, int end, int cur_sum) {
        // 确定递归出口：达到目标和/组合和已经溢出
        if (cur_sum == target) {
            result.push_back(path);
            return;
        } else if (cur_sum >= target - 1) {
            return;
        }

        // 回溯算法
        for (int i = start; i <= end; ++i) {
            path.push_back(candidates[i]);
            cur_sum += candidates[i];
            backTracking(i, end, cur_sum);
            cur_sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates = candidates;
        this->target = target;
        backTracking(0, candidates.size() - 1, 0);
        return result;
    }

private:
    int target;
    vector<int> candidates;
    vector<int> path;
    vector<vector<int>> result;
};

int main() {
    Solution obj;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    auto result = obj.combinationSum(candidates, target);
    cout << result.size() << endl;
    return 0;
}