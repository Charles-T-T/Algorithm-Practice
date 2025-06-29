#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti,
endi] 。请你合并所有重叠的区间，并返回
一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2：
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // 思路：遍历，遇到可以合并的合并就好了
    vector<vector<int>> resIV;
    vector<int> newIV(2);

    // 先将原intervals按照每个区间的左边界从小到大排序
    sort(intervals.begin(), intervals.end());

    int n = intervals.size();
    for (int i = 0; i < n; i++) {
      if (i > 0 && intervals[i][0] <= resIV.back()[1]) {
        newIV[0] = resIV.back()[0];
        newIV[1] = max(resIV.back()[1], intervals[i][1]);
        resIV.pop_back();
        resIV.push_back(newIV);
        continue;
      }
      resIV.push_back(intervals[i]);
    }

    return resIV;
  }
};

class Solution_2 {
 public:
  bool canMerge(const vector<int>&a , const vector<int>& b) {
    return b[0] <= a[1];
  }

  vector<int> mergeTwoVec(const vector<int>& a, const vector<int>& b) {
    return {a[0], max(a[1], b[1])};
  }

  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0]; 
    });

    int cur_idx = 1;
    int n = intervals.size();
    vector<vector<int>> res;
    vector<int> cur_merged = intervals[0];

    while (cur_idx < n) {
      if (canMerge(cur_merged, intervals[cur_idx])) {
        cur_merged = mergeTwoVec(cur_merged, intervals[cur_idx]);
      } else {
        res.push_back(cur_merged);
        cur_merged = intervals[cur_idx];
      }
      ++cur_idx;
    }

    res.push_back(cur_merged);

    return res;
  }
};



int main() {
  vector<vector<int>> intervals, resIV;
  intervals = {
    {1, 3},
    {2, 6},
    {8 ,10},
    {15, 18}
  };

  Solution_2 obj;
  resIV = obj.merge(intervals);
  cout << "result: "
       << "[";
  for (const vector<int>& vec : resIV) {
    cout << "[" << vec[0] << ", " << vec[1] << "]";
  }
  cout << "]";

  return 0;
}