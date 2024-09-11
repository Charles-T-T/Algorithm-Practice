#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution1II // 贪心+二分查找
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int len = 1;
        vector<int> d(nums.size() + 1, 0);
        d[1] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > d[len]) 
                d[++len] = nums[i];
            else {
                // 二分查找：待更新的位置下标pos
                int left = 0;
                int right = len - 1;
                int pos = 1; // 如果找不到，说明d中所有数都比nums[i]大，最后应更新d[1]
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (d[mid] < nums[i]) {
                        pos = mid + 1;
                        left = mid + 1;
                    } else 
                        right = mid - 1;
                }
                d[pos] = nums[i];
            }
        }
        return len;
    }
};