# 98. 验证二叉搜索树

[点此跳转题目链接](https://leetcode.cn/problems/validate-binary-search-tree/description/)

## 题目描述

给你一个二叉树的根节点 `root` ，判断其是否是一个有效的二叉搜索树。

**有效** 二叉搜索树定义如下：

- 节点的左子树只包含 **小于** 当前节点的数。
- 节点的右子树只包含 **大于** 当前节点的数。
- 所有左子树和右子树自身必须也是二叉搜索树。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)

```
输入：root = [2,1,3]
输出：true
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)

```
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。
```

 

**提示：**

- 树中节点数目范围在`[1, 104]` 内
- `-231 <= Node.val <= 231 - 1`



## 题解

显然要用递归，从根节点向下递归判断左右子树是否都满足二叉搜索树的条件。

但是一开始很容易将条件简单化，只考虑到最基本的：

- 当前节点的左孩子值小于当前节点值
- 当前节点的右孩子值大于当前节点值

但是这样就忽视了当前节点 **“上面”** 节点的情况。例如：

```
      8
     / \
    4   12
   / \  / \
  2  6 10 14
```

在上面这棵BST中，第三层的节点 `10` 小于其父节点 `12` ，但是又 **不能太小** ——因为它处于根节点 `8` 的右子树上，所以必须大于 `8` 才行。同理，第三层的节点 `6` 大于父节点 `4` ，但又 **不能太大** 以至于大于 `8` 。

即是说，每个节点都有 **上界** 和 **下界** ，从上面的分析不难发现：

- 当前节点的左子树：
  - 上界为当前节点值
  - 下界与当前节点的下界相同（“不能太小”）
- 当前节点的右子树：
  - 下界为当前节点的值
  - 上界与当前节点的上界相同（“不能太大”）

**代码（C++）**

```cpp
bool testBST(TreeNode *root, long long curMax, long long curMin) {
    if (!root)
        return true;
    if (root->val >= curMax || root->val <= curMin)
        return false;
    return testBST(root->left, root->val, curMin) 
        && testBST(root->right, curMax, root->val);
}

bool isValidBST(TreeNode *root)
{
    return testBST(root, LLONG_MAX, LLONG_MIN);
}
```

