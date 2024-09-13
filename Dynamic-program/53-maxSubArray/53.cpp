#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution1II // 分治法
{
private:
    struct Status {
        int lSum;
        int rSum;
        int mSum;
        int iSum;    
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, l.rSum + r.iSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return Status{lSum, rSum, mSum, iSum};
    }

    Status get(const vector<int>& a, int l, int r) {
        if (l == r)
            return Status{a[l], a[l], a[l], a[l]};

        int m = l + (r - l) / 2;
        Status left = get(a, l, m);
        Status right = get(a, m + 1, r);
        return pushUp(left, right);
    }

public:
    int maxSubArray(vector<int> &nums)
    {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};