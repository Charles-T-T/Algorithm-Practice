# 90. 子集 II

[点此跳转题目链接](https://leetcode.cn/problems/subsets-ii/description/)

## 题目描述

给你一个整数数组 `nums` ，其中可能包含重复元素，请你返回该数组所有可能的子集（即返回其幂集）。



解集 **不能** 包含重复的子集。返回的解集中，子集可以按 **任意顺序** 排列。

 

**示例 1：**

```
输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
```

**示例 2：**

```
输入：nums = [0]
输出：[[],[0]]
```

 

**提示：**

- `1 <= nums.length <= 10`
- `-10 <= nums[i] <= 10`



## 题解

这题在 [78. 子集](https://leetcode.cn/problems/subsets/description/) 的基础上多了一个条件： `nums` 中 **可能包含重复元素** ，这就要求我们对子集结果进行去重。去重需要在搜索过程中解决，具体思路和 [40. 组合总和 II](https://leetcode.cn/problems/combination-sum-ii/description/) 如出一辙，都是采用 `used` 数组解决，可以移步我之前的笔记 [40-题解(github)](https://github.com/Charles-T-T/Algorithm-Practice/tree/master/Back-tracking/40-combinationSum2) 或 [40-题解(CSDN)](https://blog.csdn.net/weixin_54468359/article/details/140798384?spm=1001.2014.3001.5502) 查看。

**代码（C++）**

```cpp
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> used;

public:
    void backTracking(const vector<int> &nums, int start) {
        // 求全部子集：每次都要将path加入结果集res
        res.push_back(path);
        // 递归出口（纵向遍历）
        if (start >= nums.size())
            return;
        // 横向遍历
        for (int i = start; i < nums.size(); ++i) {
            // 去重
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            // 处理
            path.push_back(nums[i]);
            used[i] = 1;
            // 递归
            backTracking(nums, i + 1);
            // 回溯
            path.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        used.resize(nums.size());
        sort(nums.begin(), nums.end()); // 先排序，便于去重
        backTracking(nums, 0);
        return res;
    }
};
```

