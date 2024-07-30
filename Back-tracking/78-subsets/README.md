# 78. 子集

[点此跳转题目链接](https://leetcode.cn/problems/subsets/description/)

## 题目描述

给你一个整数数组 `nums` ，数组中的元素 **互不相同** 。返回该数组所有可能的子集（即返回其幂集）。



解集 **不能** 包含重复的子集。你可以按 **任意顺序** 返回解集。

 

**示例 1：**

```
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

**示例 2：**

```
输入：nums = [0]
输出：[[],[0]]
```

 

**提示：**

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`
- `nums` 中的所有元素 **互不相同**



## 题解

用回溯算法解决，和基本的 [组合问题](https://blog.csdn.net/weixin_54468359/article/details/140668113?spm=1001.2014.3001.5501) 框架差不多，还是 **处理、递归、回溯** 的三部曲框架，要注意的是 :warning: ：

由于需要获得 **所有** 子集，不用像一般组合问题那样，在递归出口才将组合加入结果集，而是每次递归过程中都将当前组合加入结果集。

**代码（C++）**

```cpp
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;

public:
    void backTracking(const vector<int> &nums, int start)
    {
        // 要求所有子集，故每次都要将path加入结果集
        res.push_back(path);
        // 递归出口（纵向遍历）
        if (start >= nums.size())
            return;
        // 横向遍历
        for (int i = start; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);   // 处理
            backTracking(nums, i + 1); // 递归
            path.pop_back();           // 回溯
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        backTracking(nums, 0);
        return res;
    }
};
```

