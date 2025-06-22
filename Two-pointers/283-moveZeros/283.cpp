#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    if (nums.size() <= 1) {
      return;
    }

    int slow = 0;
    int fast = 1;
    while (fast == 0 && fast < nums.size()) {
      ++fast;
    }

    while (fast < nums.size()) {
      if (nums[slow] == 0) {
        if (nums[fast] != 0) {
          swap(nums[slow], nums[fast]);
          ++slow;
          ++fast;
        } else {
          ++fast;
        }
      } else {
        ++slow;
        ++fast;
      }
    }
  }
};

class Solution_2 {
 public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size(), left = 0, right = 0;
    while (right < n) {
      if (nums[right]) {
        swap(nums[left], nums[right]);
        left++;
      }
      right++;
    }
  }
};

int main() {
  Solution_2 obj;
  vector<int> nums = {1, 3, 12, 0, 0};
  obj.moveZeroes(nums);

  cout << "done" << endl;
  return 0;
}

/*
[0,1,0,3,12]
1, 0, 0, 3, 12
1, 3, 2, 0, 12

*/