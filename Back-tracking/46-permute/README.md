# 46. 全排列

[点此跳转题目链接](https://leetcode.cn/problems/permutations/description/)

## 题目描述

给定一个不含重复数字的数组 `nums` ，返回其 *所有可能的全排列* 。你可以 **按任意顺序** 返回答案。

 

**示例 1：**

```
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**示例 2：**

```
输入：nums = [0,1]
输出：[[0,1],[1,0]]
```

**示例 3：**

```
输入：nums = [1]
输出：[[1]]
```

 

**提示：**

- `1 <= nums.length <= 6`
- `-10 <= nums[i] <= 10`
- `nums` 中的所有整数 **互不相同**



## 题解

回溯算法解决。

基本框架采用经典的 **回溯三部曲：处理、递归、回溯** 。

去重用 `used` 数组解决，本题对应的是回溯树形结构中对 **同一个树枝上的节点值** 进行去重。

> 回溯三部曲可参考：[笔记-回溯算法 I](https://blog.csdn.net/weixin_54468359/article/details/140668113?spm=1001.2014.3001.5501)
>
> `used` 数组去重方法可参考：[笔记-回溯算法 II](https://blog.csdn.net/weixin_54468359/article/details/140798384?spm=1001.2014.3001.5501) 中的 **40. 组合总和 II** 

**代码（C++）**

```cpp
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> used; // 记录数字的使用情况，用于去重

public:
    void backTracking(const vector<int> &nums)
    {
        // 递归出口（纵向遍历）
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        // 横向遍历
        for (int i = 0; i < nums.size(); ++i)
        {
            // 去重
            if (used[i])
                continue;
            used[i] = 1;
            path.push_back(nums[i]); // 处理
            backTracking(nums);      // 递归
            path.pop_back();         // 回溯
            used[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        used.resize(nums.size());
        backTracking(nums);
        return res;
    }
};
```

另外这题还有种不用刻意去重的解法：

```cpp
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;

public:
    void backTracking(const vector<int> &nums, int start)
    {
        // 递归出口（纵向遍历）
        if (start >= nums.size())
        {
            res.push_back(path);
            return;
        }
        // 横向遍历
        for (int i = start; i < nums.size(); ++i)
        {
            swap(path[start], path[i]);    // 处理
            backTracking(nums, start + 1); // 递归
            swap(path[start], path[i]);    // 回溯
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        path = nums;
        backTracking(nums, 0);
        return res;
    }
};
```

不过该算法和经典框架有些出入，例如递归时传递的是 `start + 1` 而不是大多数情况下的 `i + 1` 或 `i` 。