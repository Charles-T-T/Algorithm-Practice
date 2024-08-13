#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。

示例 2：
输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
*/

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        /**
         * 思路：
         * 确定了分割出去的一部分，剩下的自然就是另一部分
         * 只要分割部分之和为总和的一半即可
         *
         * 转化为背包问题：
         * 容量为target的背包，能否恰好装下target价值的物品
         */
        int sum = 0, target;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false; // 总和不是偶数，必然不可能分割等和子集
        else
            target = sum / 2;

        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if (dp[target] == target)
            return true;
        else
            return false;
    }
};

class Solution2I // 二刷，回溯算法：超时
{
private:
    int curSum = 0;
    bool flag = false;
    void backTracking(const vector<int> &nums, int target, int start) {
        // 剪枝
        if (curSum > target)
            return;
        // 递归出口：子集元素和达到目标值
        if (curSum == target) {
            flag = true;
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            curSum += nums[i]; // 处理
            backTracking(nums, target, i + 1); // 递归
            curSum -= nums[i]; // 回溯
        }
    }

public:
    bool canPartition(vector<int> &nums)
    {
        // 先求出每个子集的元素和
        int sum = 0; 
        for (int num : nums)
            sum += num;
        if (sum % 2 == 1)
            return false; // 目标和为奇数肯定无法实现
        sum /= 2;

        // 回溯算法
        sort(nums.begin(), nums.end());
        backTracking(nums, sum, 0);
        return flag;
    }
};

class Solution2II // 二刷，动态规划（背包问题）
{
public:
    bool canPartition(vector<int> &nums)
    {
        // 先求出每个子集的元素和
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % 2 == 1)
            return false; // 目标和为奇数肯定无法实现
        sum /= 2;

        // 背包问题：能否将weights和values都为nums、容量为sum的背包恰好装满
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, 0));
        for (int j = nums[0]; j <= sum; ++j)
            dp[0][j] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= sum; ++j) {
                if (nums[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
            }
        }
        return dp[dp.size() - 1][sum] == sum;
    }

    // 一维dp版本
    bool canPartitionII(vector<int> &nums)
    {
        // 先求出每个子集的元素和
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % 2 == 1)
            return false; // 目标和为奇数肯定无法实现
        sum /= 2;

        // 背包问题：能否将weights和values都为nums、容量为sum的背包恰好装满
        vector<int> dp(sum + 1, 0);
        for (int j = nums[0]; j <= sum; ++j)
            dp[j] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = sum; j >= nums[i]; --j)  // 注意：一维dp要倒着遍历容量j
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
        return dp[sum] == sum;
    }
};

int main()
{
    vector<int> nums = {1, 2, 5};
    Solution2II obj;
    if (obj.canPartitionII(nums))
        cout << "True!" << endl;
    else
        cout << "False!" << endl;

    return 0;
}