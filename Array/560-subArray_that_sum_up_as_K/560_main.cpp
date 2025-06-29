#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
����һ���������� nums ��һ������ k ������ͳ�Ʋ����� �������к�Ϊ k
��������ĸ��� ��

��������������Ԫ�ص������ǿ����С�

ʾ�� 1��
���룺nums = [1,1,1], k = 2
�����2

ʾ�� 2��
���룺nums = [1,2,3], k = 3
�����2
*/

class Solution {
 public:
  int subarraySum(vector<int> &nums, int k) {
    // ˼·��˫ָ������ѭ����lp��rp��ʼ��ǰ�ܣ�����ѭ�����в���Ҫ���ظ�����
    // �������Ȼ��ʱ
    int lp = 0, rp = 0;
    int n = nums.size();
    int sum = 0, count = 0;
    int lsum = 0, rsum = 0;  // (0, lp)��(0, rp)��͵Ĵ�С

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
    // ˼·�������ϣ���¼ǰ׺��
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
    unordered_map<int, int> prefix_sum_count;  // ĳ��ǰ׺�ͳ����˶��ٴ�
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