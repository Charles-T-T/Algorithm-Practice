#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

/*
������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti,
endi] ������ϲ������ص������䣬������
һ�����ص����������飬��������ǡ�ø��������е��������� ��

ʾ�� 1��
���룺intervals = [[1,3],[2,6],[8,10],[15,18]]
�����[[1,6],[8,10],[15,18]]
���ͣ����� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].

ʾ�� 2��
���룺intervals = [[1,4],[4,5]]
�����[[1,5]]
���ͣ����� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣
*/

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // ˼·���������������Ժϲ��ĺϲ��ͺ���
    vector<vector<int>> resIV;
    vector<int> newIV(2);

    // �Ƚ�ԭintervals����ÿ���������߽��С��������
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