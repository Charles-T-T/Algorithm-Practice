#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 贪心算法：先按左边界排序，再依次合并
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> res;
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] > right) {
                res.emplace_back(vector<int>{left, right});
                left = intervals[i][0], right = intervals[i][1];
            } else 
                right = max(right, intervals[i][1]);

            if (i == intervals.size() - 1)
                res.emplace_back(vector<int>{left, right});
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 4}, {0, 2}, {3, 5}};
    Solution obj;
    vector<vector<int>> res = obj.merge(intervals);

    return 0;
}