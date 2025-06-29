#include <iostream>
#include <vector>

using namespace std;

// NOTE: 会超时
class Solution_0 {
 public:
  int trap(vector<int>& height) {
    int res = 0;

    int highest = 0;
    int n = height.size();
    for (int h : height) {
      highest = max(highest, h);
    }

    for (int h = 0; h <= highest; ++h) {
      int left = 0;
      while (height[left] < h) {
        ++left;
      }
      
      int right = left;
      while (right < n) {
        ++right;
        if (right < n && height[right] >= h) {
          res += right - left - 1;
          left = right;
        }
      }
    }

    return res;
  }
};

// [NOTE] 动态规划
class Solution {
 public:
  int trap(vector<int>& height) {
    int res = 0;
    int n = height.size();
    
    vector<int> highest_left(n, 0);
    vector<int> highest_right(n, 0);

    for (int i = 0; i < n - 1; ++i) {
      highest_left[i + 1] = max(highest_left[i], height[i]);
    }
    for (int i = n - 1; i > 0; --i) {
      highest_right[i - 1] = max(highest_right[i], height[i]);
    }

    for (int i = 0; i < n; ++i) {
      int delta = min(highest_left[i], highest_right[i]) - height[i];
      if (delta > 0) {
        res += delta;
      }
    }
    
    return res;
  }
};

int main() {
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  Solution obj;
  int res = obj.trap(height);

  cout << res << endl;

  return 0;
}