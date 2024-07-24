# 216. 组合总和 III

[点此跳转题目链接](https://leetcode.cn/problems/combination-sum-iii/description/)

## 题目描述

找出所有相加之和为 `n` 的 `k` 个数的组合，且满足下列条件：

- 只使用数字1到9
- 每个数字 **最多使用一次** 

返回 *所有可能的有效组合的列表* 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

 

**示例 1:**

```
输入: k = 3, n = 7
输出: [[1,2,4]]
解释:
1 + 2 + 4 = 7
没有其他符合的组合了。
```

**示例 2:**

```
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
解释:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
没有其他符合的组合了。
```

**示例 3:**

```
输入: k = 4, n = 1
输出: []
解释: 不存在有效的组合。
在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
```

 

**提示:**

- `2 <= k <= 9`
- `1 <= n <= 60`



## 题解

> 参考：[代码随想录-216](https://programmercarl.com/0216.组合总和III.html#思路)

回溯算法解决。首先想清楚回溯的树形结构图：

![img](./20201123195717975.png)

然后走**回溯三部曲** :sparkles: 

- **处理：** 将当前处理的数字加入当前组合 `path` ，并求此时组合中的数字和

  > 进行这一步**之前**可以**剪枝**：由于是从1到9（从小到大）横向遍历，如果 目标和 与 当前和 的差小于即将加入的数字，说明再加数字必将导致组合总和过大，故没必要在此基础上往后遍历处理了。

- **递归：** 递归地尝试将后面的数字加入组合；递归出口： `path` 的大小达到目标大小 `k` ，且其中数字和等于目标和，则将 `path` 加入结果集
- **回溯：** 弹出当前组合的最后一个数，以便探索该位置放其他数的可能

代码如下：

```cpp
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;

public:
    void backTracking(int start, int end, int maxPathSize, int targetSum, int curSum)
    {
        // 递归出口（纵向遍历）
        if (path.size() == maxPathSize)
        {
            if (curSum == targetSum)
                res.push_back(path);
            return;
        }
        // 剪枝
        if (targetSum - curSum < start)
            return;
        // 横向遍历
        for (int i = start; i <= end; i++)
        {
            curSum += i;
            path.push_back(i);                                        // 处理
            backTracking(i + 1, end, maxPathSize, targetSum, curSum); // 递归
            curSum -= i;
            path.pop_back(); // 回溯
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backTracking(1, 9, k, n, 0);
        return res;
    }
};
```

