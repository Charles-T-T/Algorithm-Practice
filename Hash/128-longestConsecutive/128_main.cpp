#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>


using namespace std;

/*
给定一个未排序的整数数组 nums
，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

示例 2：
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
*/

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    // 思路：暴力搜索，但是通过判断起始数字是否已经被包含在之前的尝试中，减少不必要的尝试
    int maxLength = 0, tempLength = 0;
    int curNum;
    unordered_set<int> numSet;
    for (const int& num : nums) numSet.insert(num);

    // 尝试以每一个num作为序列的起点
    for (const int& num : nums) {
      if (!numSet.count(num - 1)) {
        curNum = num;
        tempLength = 1;
        while (numSet.count(++curNum)) tempLength++;
      }

      maxLength = max(maxLength, tempLength);
    }

    return maxLength;
  }
};

class Solution_2 {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set(nums.begin(), nums.end());

    int cur_longest = 0;
    int cur_len = 0;
    int cur_need;
    for (int num : num_set) {
      if (num_set.find(num - 1) != num_set.end()) {
        continue;
      }
      cur_need = num + 1;
      cur_len = 1;
      while (num_set.find(cur_need) != num_set.end()) {
        ++cur_len;
        ++cur_need;
      }
      cur_longest = max(cur_longest, cur_len);
    }

    return cur_longest;
  }
};

int main() {
  vector<int> nums;
  cout << "please input the nums: ";
  string line, token;
  getline(cin, line);
  stringstream ss(line);
  while (ss >> token) nums.push_back(stoi(token));

  Solution obj;
  int maxLength = obj.longestConsecutive(nums);
  cout << "res: " << maxLength << endl;

  return 0;
}