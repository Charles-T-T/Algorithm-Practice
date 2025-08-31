#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> res;
  vector<int> path;

  void backTracking(int n, int k, int start) {
    if (int(path.size()) == k) {
      res.push_back(path);
      return;
    }

    for (int i = start; i <= n; ++i) {
      path.push_back(i);
      backTracking(n, k, i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k) {
    backTracking(n, k, 1);
    return res;
  }
};