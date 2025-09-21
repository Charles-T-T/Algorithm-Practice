#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int farest_dist = 0;
    int cover_dist = 0;
    int hop_cnt = 0;
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      farest_dist = max(farest_dist, i + nums[i]);
      if (i >= cover_dist) {
        ++hop_cnt;
        cover_dist = farest_dist;
      }
      if (cover_dist >= n - 1) {
        break;
      }
    }
    return hop_cnt;
  }
};