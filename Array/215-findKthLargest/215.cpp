#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  // 利用快速排序，找到升序排列下 nums 的第 k 个元素
  int findSeqKth(vector<int>& nums, int l, int r, int k) {
    if (l == r) {
      return nums[k];
    }

    int pivot_id = l + rand() % (r - l);
    int pivot = nums[pivot_id];
    int i = l - 1, j = r + 1;
    while (i < j) {
      do {
        ++i;
      } while (nums[i] < pivot);
      do {
        --j;
      } while (nums[j] > pivot);
      if (i < j) {
        swap(nums[i], nums[j]);
      }
    }

    if (k <= j) {
      return findSeqKth(nums, l, j, k);
    } else {
      return findSeqKth(nums, j + 1, r, k);
    }
  }
  int findKthLargest(vector<int>& nums, int k) {
    return findSeqKth(nums, 0, nums.size() - 1, nums.size() - k);
  }
};

int main() {
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  Solution obj;
  cout << obj.findKthLargest(nums, 2) << endl;
  return 0;
}

// pivot = 4, nums = [8, 3, 2, 9, 7, 4]
