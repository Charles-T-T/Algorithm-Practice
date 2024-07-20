# 700. 二叉搜索树中的搜索

[点此跳转题目链接](https://leetcode.cn/problems/search-in-a-binary-search-tree/description/)

## 题目描述

给定二叉搜索树（BST）的根节点 `root` 和一个整数值 `val`。

你需要在 BST 中找到节点值等于 `val` 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 `null` 。

 

**示例 1:**

![img](./tree1.jpg)

```
输入：root = [4,2,7,1,3], val = 2
输出：[2,1,3]
```

**示例 2:**

![img](./tree2.jpg)

```
输入：root = [4,2,7,1,3], val = 5
输出：[]
```

 

**提示：**

- 树中节点数在 `[1, 5000]` 范围内
- `1 <= Node.val <= 107`
- `root` 是二叉搜索树
- `1 <= val <= 107`



## 题解

二叉搜索树的基本使用。由于二叉搜索树满足：

- 当前节点的左子树中的值一定小于当前节点值
- 当前节点的右子树中的值一定大于当前节点值

故可以从根节点起，按照目标值与节点值的大小关系决定向左子树还是右子树搜索，若搜索到空节点还没找到目标值则返回空节点。

**代码（C++）**

```cpp
TreeNode *searchBST(TreeNode *root, int val)
{
    // 递归出口：空节点或找到目标值
    if (!root)
        return nullptr;
    if (root->val == val)   
        return root;
    // 根据二叉搜索树的性质搜索
    if (root->val > val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}
```

