# 654. 最大二叉树

[点此跳转题目链接](https://leetcode.cn/problems/maximum-binary-tree/description/)

## 题目描述

给定一个不重复的整数数组 `nums` 。 **最大二叉树** 可以用下面的算法从 `nums` 递归地构建:

1. 创建一个根节点，其值为 `nums` 中的最大值。
2. 递归地在最大值 **左边** 的 **子数组前缀上** 构建左子树。
3. 递归地在最大值 **右边** 的 **子数组后缀上** 构建右子树。

返回 `nums` 构建的 **最大二叉树**  。

 

**示例 1：**

![img](./tree1.jpg)

```
输入：nums = [3,2,1,6,0,5]
输出：[6,3,5,null,2,0,null,null,1]
解释：递归调用如下所示：
- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
        - 空数组，无子节点。
        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
            - 空数组，无子节点。
            - 只有一个元素，所以子节点是一个值为 1 的节点。
    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
        - 只有一个元素，所以子节点是一个值为 0 的节点。
        - 空数组，无子节点。
```

**示例 2：**

![img](./tree2.jpg)

```
输入：nums = [3,2,1]
输出：[3,null,2,null,1]
```

 

**提示：**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 1000`
- `nums` 中的所有整数 **互不相同**



## 题解

题目描述直接说了递归，那就从了它罢：

- 维护左右双指针，用于确定当前生成节点所属的 `nums` 区间
- 从 `nums` 区间中选出最大值，作为当前生成节点的值
- 在其左、右区间递归生成其左、右孩子

递归出口也很显然，即左右指针错开（区间已不存在）。

**代码（C++）**

```cpp
class Solution
{
public:
    // nums中的数字各不相同，故用一个哈希表将其下标先存起来便于使用
    unordered_map<int, int> indexMap;
    void getMap(const vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
            indexMap[nums[i]] = i;
    }

    // 递归法
    TreeNode *getRoot(vector<int> &nums, int left, int right)
    {
        // 递归出口：子数组收缩到没有数字（空节点）
        if (left > right)
            return nullptr;
        int maxNum = INT_MIN; // 当前子数组中的最大值
        for (int i = left; i <= right; ++i)
            maxNum = max(maxNum, nums[i]);
        int mid = indexMap[maxNum]; // 当前子数组中最大值的下标
        TreeNode *root = new TreeNode(maxNum);
        // 递归构建左右子树
        root->left = getRoot(nums, left, mid - 1);
        root->right = getRoot(nums, mid + 1, right);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        getMap(nums);
        return getRoot(nums, 0, nums.size() - 1);
    }
};
```

