# 213. 打家劫舍 II

[点此跳转题目链接](https://leetcode.cn/problems/house-robber-ii/description/)

## 题目描述

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 **围成一圈** ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，**如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警** 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 **在不触动警报装置的情况下** ，今晚能够偷窃到的最高金额。

 

**示例 1：**

```
输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
```

**示例 2：**

```
输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
```

**示例 3：**

```
输入：nums = [1,2,3]
输出：3
```

 

**提示：**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 1000`



## 题解

这题和 [198. 打家劫舍](https://leetcode.cn/problems/house-robber/description/) 差不多，只不过数组变成了循环结构。所以最大的变化就是“首尾相连”了，而根据题目，每次要考虑的仍然是“相邻两家”不能同时抢，即数组的一头一尾不能一起抢，其他的其实和原版一致。

因此，既然首尾不能同时出现，我们不妨直接分别考虑 **“有头无尾”** 和 **“无头有尾”** 两种情况，再取其中较大的结果即可。

**代码（C++）**

```cpp
class Solution
{
private:
    // 普通的打家劫舍
    int robRange(const vector<int> &nums, int start, int end)
    {
        if (end == start)
            return nums[start];
        vector<int> dp(end - start + 1);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i < dp.size(); ++i)
            dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]);
        return dp[end - start];
    }

public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        return max(robRange(nums, 0, nums.size() - 2), 
                   robRange(nums, 1, nums.size() - 1));
    }
};
```



