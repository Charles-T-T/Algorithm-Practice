#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
            return 0;
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int iCount = 1; // 最终的无重叠区间数量
        int curMinRight = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= curMinRight) {
                iCount++;
                curMinRight = intervals[i][1];
            } else 
                curMinRight = min(intervals[i][1], curMinRight);
        }
        return intervals.size() - iCount;
    }
};