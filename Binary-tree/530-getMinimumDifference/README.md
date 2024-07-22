# 530. 二叉搜索树的最小绝对差

[点此跳转题目链接](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/)

## 题目描述

给你一个二叉搜索树的根节点 `root` ，返回 **树中任意两不同节点值之间的最小差值** 。

差值是一个正数，其数值等于两值之差的绝对值。

 

**示例 1：**

![img](./bst1.jpg)

```
输入：root = [4,2,6,1,3]
输出：1
```

**示例 2：**

![img](./bst2.jpg)

```
输入：root = [1,0,48,null,null,12,49]
输出：1
```

 

**提示：**

- 树中节点的数目范围是 `[2, 104]`
- `0 <= Node.val <= 105`

 

## 题解

暴力解法把所有节点两两相减、求绝对值最小的差即可，时间复杂度为 $O(n^2)$ 。

我们可以利用二叉搜索树的一个重要性质来优化算法：

- **二叉搜索树的中序遍历结果是一个从小到大的有序数列**

> 此处默认节点左子树中各节点值小于节点、右子树中各节点值大于节点，则上面的性质是显然的。

也就是说，如果我们先获得中序遍历结果，再从头到尾依次两两相减，只需要遍历一次就可以得出最小绝对差。

> 由于中序遍历结果是递增序列，最小的任意两数之差肯定出现在相邻的两数之间；且后一个数大于前一个数，所以总让后一个数减去前一个数，所得结果必为正数，不必再求绝对值。

显然，这一算法可以直接在中序遍历的过程中运行，C++代码如下：
```cpp
int res = INT_MAX;
TreeNode *pre; // 暂存中序遍历时前一个节点的指针

void traversal(TreeNode *root)
{
    if (root->left)
        traversal(root->left); // 左
    if (pre)
        res = min(res, root->val - pre->val); // 中
    pre = root;                               // 更新前指针
    if (root->right)
        traversal(root->right); // 右
}

int getMinimumDifference(TreeNode *root)
{
    traversal(root);
    return res;
}
```

