# 39. 组合总和

[点此跳转题目链接](https://leetcode.cn/problems/combination-sum/description/)

## 题目描述

给你一个 **无重复元素** 的整数数组 `candidates` 和一个目标整数 `target` ，找出 `candidates` 中可以使数字和为目标数 `target` 的 所有 **不同组合** ，并以列表形式返回。你可以按 **任意顺序** 返回这些组合。

`candidates` 中的 **同一个** 数字可以 **无限制重复被选取** 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 `target` 的不同组合数少于 `150` 个。



**示例 1：**

```
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
```

**示例 2：**

```
输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]
```

**示例 3：**

```
输入: candidates = [2], target = 1
输出: []
```



**提示：**

- `1 <= candidates.length <= 30`
- `2 <= candidates[i] <= 40`
- `candidates` 的所有元素 **互不相同**
- `1 <= target <= 40`



## 题解

经典的回溯算法题目，和 [打卡-回溯算法 I](https://blog.csdn.net/weixin_54468359/article/details/140668113?spm=1001.2014.3001.5501) 中的几道题的差不多，直接按照 **回溯三部曲——处理、递归、回溯** 来解决即可：

```cpp
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;

public:
    void backTracking(const vector<int> &candidates, int target, int curSum, int start)
    {
        // 递归出口（纵向遍历）
        if (curSum == target)
        {
            res.push_back(path);
            return;
        }

        // 剪枝
        if (curSum > target)
            return;

        // 横向遍历
        for (int i = start; i < candidates.size(); ++i)
        {
            path.push_back(candidates[i]);
            curSum += candidates[i];                     // 处理
            backTracking(candidates, target, curSum, i); // 递归
            path.pop_back();                             // 回溯
            curSum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backTracking(candidates, target, 0, 0);
        return res;
    }
};
```

注意一下题目说“ `candidates` 中的 **同一个** 数字可以 **无限制重复被选取** ”，所以递归时：

```cpp
backTracking(candidates, target, curSum, i); // 递归
```

最后一个参数传的还是 `i` ，而不是许多类似题目中的 `i + 1` 。