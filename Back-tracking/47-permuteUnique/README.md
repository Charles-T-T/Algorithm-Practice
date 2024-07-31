# 47. 全排列 II

[点此跳转题目链接](https://leetcode.cn/problems/permutations-ii/description/)

## 题目描述

给定一个可包含重复数字的序列 `nums` ，***按任意顺序*** 返回所有不重复的全排列。

 

**示例 1：**

```
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

**示例 2：**

```
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

 

**提示：**

- `1 <= nums.length <= 8`
- `-10 <= nums[i] <= 10`



## 题解

回溯算法解决。这题在 [46. 全排列](https://leetcode.cn/problems/permutations/description/) 的基础上，增加了一个条件： `nums` 中 **可包含重复数字** 。于是为了得到 **不重复** 的全排列结果，在对应的回溯树形结构上， **横向纵向都要去重** ：

- 同一树枝上要去重（不能重复使用 `nums` 相同下标的元素，但是下标不同、值相同是可以的）
- 同一父节点下的同一层要去重（不能重复使用相同的节点值，无论该值在 `nums` 中是否本来就不止一个）

可以说是回溯算法两种常见去重的缝合怪了 ( :dog: )

本题回溯树形结构见 [代码随想录](https://programmercarl.com/0047.全排列II.html#思路) 中这张图：

![img](./20201124201331223.png)

>回溯算法基础可参考：[笔记-回溯算法 I](https://blog.csdn.net/weixin_54468359/article/details/140668113?spm=1001.2014.3001.5501) 

**代码（C++）**

```cpp
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;
    vector<int> branchUsed; // 记录当前树枝中使用过的元素

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
        unordered_set<int> layerUsed; // 记录当前层中使用过的元素
        for (int i = 0; i < nums.size(); ++i)
        {
            // 去重
            if (layerUsed.find(nums[i]) != layerUsed.end())
                continue; // 同一层中去重
            if (branchUsed[i])
                continue; // 同一树枝中去重
            layerUsed.insert(nums[i]);
            branchUsed[i] = 1;
            path.push_back(nums[i]); // 处理
            backTracking(nums);      // 递归
            path.pop_back();         // 回溯
            branchUsed[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        branchUsed.resize(nums.size());
        backTracking(nums);
        return res;
    }
};
```

