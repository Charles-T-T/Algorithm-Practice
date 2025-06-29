#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k
的子数组的个数 。

子数组是数组中元素的连续非空序列。

示例 1：
输入：nums = [1,1,1], k = 2
输出：2

示例 2：
输入：nums = [1,2,3], k = 3
输出：2
*/

class Solution {
 public:
  int subarraySum(vector<int> &nums, int k) {
    // 思路：双指针两重循环，lp从rp开始向前跑，减少循环体中不必要的重复计算
    // 但最后仍然超时
    int lp = 0, rp = 0;
    int n = nums.size();
    int sum = 0, count = 0;
    int lsum = 0, rsum = 0;  // (0, lp)和(0, rp)求和的大小

    for (rp = 0; rp < n; rp++) {
      sum = 0;
      for (lp = rp; lp >= 0; lp--) {
        sum += nums[lp];
        if (sum == k) count++;
      }
    }

    return count;
  }

  int subarraySumFast(vector<int> &nums, int k) {
    // 思路：引入哈希表记录前缀和
    int sum = 0, count = 0;
    unordered_map<int, int> sumMap;
    int len = nums.size();
    int curMinusK;
    sumMap[0] = 1;
    for (int i = 0; i < len; i++) {
      sum += nums[i];
      curMinusK = sum - k;
      auto it = sumMap.find(curMinusK);
      if (it != sumMap.end()) count += it->second;

      sumMap[sum]++;
    }

    return count;
  }
};

class Solution_2 {
 public:
  int subarraySum(vector<int> &nums, int k) {
    int res = 0;
    int n = nums.size();
    int cur_sum = 0;
    unordered_map<int, int> prefix_sum_count;  // 某个前缀和出现了多少次
    prefix_sum_count[0] = 1;

    for (int i = 0; i < n; ++i) {
      cur_sum += nums[i];
      int need = cur_sum - k;
      if (prefix_sum_count.find(need) != prefix_sum_count.end()) {
        res += prefix_sum_count[need];
      }
      ++prefix_sum_count[cur_sum];
    }

    return res;
  }
};

int main() {
  int len, num, target;
  vector<int> nums;
  cout << "please input the target: ";
  cin >> target;
  cout << "please input the length of nums: ";
  cin >> len;
  cout << "please input the nums, divided by space: " << endl;
  for (int i = 0; i < len; i++) {
    cin >> num;
    nums.push_back(num);
  }

  Solution obj;
  int count = obj.subarraySumFast(nums, target);
  cout << "result: " << count << endl;
}