#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    // 1 2 3
    // 1 3 2
    // 2 1 3

    // 1 2 5 4 3 0
    // (1 3 5 4 2 0)
    // 1 3 0 2 4 5
    int n = nums.size();
    int i = n - 1;
    for (; i >= 1; --i) {
      if (nums[i] > nums[i - 1]) {
        // 找到第一个“较小数”：nums[i-1]
        for (int j = n - 1; j > i - 1; --j) {
          // 找到第一个小于 nums[i-1] 的“较大数”：nums[j]
          if (nums[j] > nums[i - 1]) {
            swap(nums[i - 1], nums[j]);  // 交换“较小数”和“较大数”
            break;
          }
        }
        break;
      }
    }
    // 此时 nums[i:n] 必为降序，需将其反转为升序。
    reverse(nums.begin() + i, nums.end());
  }
};

int main() {
  vector<int> test = {4, 3, 1, 2};
  Solution obj;
  obj.nextPermutation(test);
  for (int n : test) {
    cout << n << " ";
  }
  return 0;
}