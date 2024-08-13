# 416. 分割等和子集

[点此跳转题目链接](https://leetcode.cn/problems/partition-equal-subset-sum/description/)

## 题目描述

给你一个 **只包含正整数** 的 **非空** 数组 `nums` 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 

**示例 1：**

```
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
```

**示例 2：**

```
输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
```

 

**提示：**

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 100`



## 题解

根据题目要求，首先不难想到一个基本目标：每个子集的元素之和应该恰为 `nums` 所有元素之和的 **一半** 。自然，我们可以先找到这个目标和：

```cpp
// 先求出每个子集的元素和
int sum = 0;
for (int num : nums)
    sum += num;
if (sum % 2 == 1)
    return false; // 目标和为奇数肯定无法实现
sum /= 2;
```

接下来就是看 `nums` 中能不能找一堆元素“凑”出 `sum` 。这样考虑似乎和 [组合问题](https://blog.csdn.net/weixin_54468359/article/details/140668113?spm=1001.2014.3001.5501)类似，于是尝试回溯算法解决：

```cpp
class Solution // 回溯算法：超时
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
```

经检验，回溯算法可行但是数据规模大的时候会超时——毕竟回溯本质上是穷举。

于是我们考虑更优雅的算法：动态规划。有一定 [01背包问题基础](https://programmercarl.com/背包理论基础01背包-1.html#思路) 的话可以发现，本题其实可以转化为一个01背包问题：

**能否将一个容量为 `sum` 的背包，用 `weights` 和 `values` 均为 `nums` 的物品恰好装满？**

> “恰好装满容量为 `sum` 的背包”对应“找到一个元素和为 `sum` 的子集”，“ `weights` 和 `values` 均为 `nums` ”对应“从 `nums` 中取子集”。

那么就按经典的01背包问题套路解决即可：

```cpp
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
```

当然也可以将 `dp` 数组从二维降为一维（ [滚动数组](https://programmercarl.com/背包理论基础01背包-2.html#算法公开课) ）：

```cpp
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
    vector<int> dp(sum + 1, 0);
    for (int j = nums[0]; j <= sum; ++j)
        dp[j] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = sum; j >= nums[i]; --j)  // 注意：一维dp要倒着遍历容量j
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
    }
    return dp[sum] == sum;
}
```

