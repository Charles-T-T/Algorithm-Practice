# 701. 二叉搜索树中的插入操作

[点此跳转题目链接](https://leetcode.cn/problems/insert-into-a-binary-search-tree/description/)

## 题目描述

给定二叉搜索树（BST）的根节点 `root` 和要插入树中的值 `value` ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 **保证** ，新值和原始二叉搜索树中的任意节点值都不同。

**注意**，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 **任意有效的结果** 。

 <br>

**示例 1：**

![img](./insertbst.jpg)

```
输入：root = [4,2,7,1,3], val = 5
输出：[4,2,7,1,3,5]
解释：另一个满足题目要求可以通过的树是：
```

**示例 2：**

```
输入：root = [40,20,60,10,30,50,70], val = 25
输出：[40,20,60,10,30,50,70,null,null,25]
```

**示例 3：**

```
输入：root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
输出：[4,2,7,1,3,5]
```

 <br>

**提示：**

- 树中的节点数将在 `[0, 104]`的范围内。
- `-108 <= Node.val <= 108`
- 所有值 `Node.val` 是 **独一无二** 的。
- `-108 <= val <= 108`
- **保证** `val` 在原始BST中不存在。

<br>

## 题解

最简单直接的方法显然是**将新节点作为叶子节点插入**：从根节点开始搜索，直到空节点，然后将该空节点替换为待插入节点即可。

```cpp
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    // 在叶子节点插入
    if (!root)
        return new TreeNode(val);
    TreeNode *cur = root;
    TreeNode *pre;
    while (cur) {
        pre = cur;
        if (val < cur->val)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (val < pre->val)
        pre->left = new TreeNode(val);
    else 
        pre->right = new TreeNode(val);
    return root;
}
```

> 看了下官方题解也是如此，不知道为啥把这个简单题标记为“中等”难度 :thinking: ​