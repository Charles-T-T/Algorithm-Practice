# 494. 目标和

[点此跳转题目链接](https://leetcode.cn/problems/target-sum/description/)

## 题目描述

给你一个非负整数数组 `nums` 和一个整数 `target` 。

向数组中的每个整数前添加 `'+'` 或 `'-'` ，然后串联起所有整数，可以构造一个 **表达式** ：

- 例如，`nums = [2, 1]` ，可以在 `2` 之前添加 `'+'` ，在 `1` 之前添加 `'-'` ，然后串联起来得到表达式 `"+2-1"` 。

返回可以通过上述方法构造的、运算结果等于 `target` 的不同 **表达式** 的数目。

 

**示例 1：**

```
输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

**示例 2：**

```
输入：nums = [1], target = 1
输出：1
```

 

**提示：**

- `1 <= nums.length <= 20`
- `0 <= nums[i] <= 1000`
- `0 <= sum(nums[i]) <= 1000`
- `-1000 <= target <= 1000`



## 题解

这题乍一看就是个 [组合问题](https://blog.csdn.net/weixin_54468359/article/details/140668113?spm=1001.2014.3001.5501) ，所以首先无脑尝试了一下**回溯算法**：

```cpp
class Solution // 回溯算法
{
private:
    int count = 0;
    void backTracking(const vector<int> &nums, int target, int curSum, int index) {
        // 递归出口：数组中各数都用到了（遍历结束）
        if (index == nums.size()) {
            if (curSum == target) 
                count++;
            return;
        }
        // 添加 "+"
        curSum += nums[index]; // 处理
        backTracking(nums, target, curSum, index + 1); // 递归
        curSum -= nums[index]; // 回溯
        // 添加 "-"
        curSum -= nums[index];
        backTracking(nums, target, curSum, index + 1);
        curSum += nums[index];
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        backTracking(nums, target, 0, 0);
        return count;
    }
};
```

在LeetCode上通过了，但是慢得无与伦比：

<img src="./image-20240813183721128.png" alt="img1" width="400" />

（疑似在超时边缘疯狂试探 可能换个配置不太好的机器就超时了 :dizzy_face: ）

考虑其他更优雅高效的算法。根据题目要求，我们最终要将数组中的数一部分取正、另一部分取负。

> 这里的“取正”和“取负”就是题目中的添加"+"和"-"，所以也要考虑0——虽然给它加"+"还是"-"得到的数值一样，但是组合方式不同

记原数组之和为 $sum$ ，最终的所有取正的数字之和为 $add$ ，则所有取负的数字之和为 $-(sum - add)$ 。二者之和即为 $target$ ，即

$$
add - (sum - add) = target
$$

所以

$$
add = (target + sum) / 2
$$

于是，问题变成了 **从 `nums` 中找若干数字、使其和为 $add$ 有多少种方法** 。根据上面的公式可知， $add$ 不能为负数或奇数。

进一步，可以发现这其实能转化为 **01背包问题** ：

**`nums` 相当于物品的 `weights` ，求用这些物品将容量为 `add` 的背包恰好装满有多少种方法？**

那么按照01背包问题的常规动态规划解法就能搞定了，其中

- `dp` 数组的含义： `dp[j]` 表示恰好装满容量为 `j` 的背包有 `dp[j]` 种方法
- 状态转移方程：对于容量为 `j` 的背包，现考虑一个新的物品 `i` ，若把它放进背包能恰好装满，则放之前的背包状态的实现方法有 `dp[j - weights[i]]` （即 `dp[j - nums[i]]` ）种。所以，此时就新增了这么多种方法，即 `dp[j] += dp[j - nums[i]]` 

**代码（C++）**

```cpp
int findTargetSumWays(vector<int> &nums, int target)
{
    int sum = 0;
    for (int num : nums)
        sum += num;
    if ((target + sum) < 0 || (target + sum) % 2 == 1)
        return 0;
    int add = (target + sum) / 2;
    // 背包问题：nums相当于weights，求装满容量为add的背包有多少种方法
    vector<int> dp(add + 1);
    dp[0] = 1;
    // 若有新的物品i，要装满容量为j的背包，则又新增dp[j - nums[i]]中方法
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = add; j >= nums[i]; --j)
            dp[j] += dp[j - nums[i]];
    }
    return dp[add];
}
```

这个算法就高效多了：

<img src="./img2.png" alt="img2" width="400" />

