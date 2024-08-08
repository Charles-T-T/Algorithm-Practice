#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        auto cmp = [](const vector<int> &a, const vector<int> &b) {return a[0] < b[0];};
        sort(points.begin(), points.end(), cmp); // 先对points排序
        int count = 1;
        int curMin = points[0][0], curMax = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > curMax) {
                curMin = points[i][0], curMax = points[i][1];
                count++;
            } else 
                curMin = points[i][0], curMax = min(curMax, points[i][1]); // 更新左右边界
        }
        return count;
    }
};

int main() {
    vector<vector<int>> points = {{3, 9}, {7, 12}, {3, 8}, {6, 8}, {9, 10}, {2, 9}, {0, 9}, {3, 9}, {0, 6}, {2, 8}};
    Solution obj;
    cout << obj.findMinArrowShots(points) << endl;
    return 0;
}