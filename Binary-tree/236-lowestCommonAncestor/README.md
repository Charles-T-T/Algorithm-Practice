# 236. 二叉树的最近公共祖先

[点此跳转题目链接](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/)

## 题目描述

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

[百度百科](https://baike.baidu.com/item/最近公共祖先/8918834?fr=aladdin)中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）。”

 

**示例 1：**

![img](./binarytree.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
```

**示例 2：**

![img](./binarytree.png)

```
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
```

**示例 3：**

```
输入：root = [1,2], p = 1, q = 2
输出：1
```

 

**提示：**

- 树中节点数目在范围 `[2, 105]` 内。
- `-109 <= Node.val <= 109`
- 所有 `Node.val` `互不相同` 。
- `p != q`
- `p` 和 `q` 均存在于给定的二叉树中。



## 题解

根据题目描述，可以发现，符合直觉的思路是**自底向上**地查找——而这与**后序遍历**的遍历顺序相符。所以，我们考虑基于后序遍历，递归地返回 `p` 和 `q` 的最近公共祖先。

用递归，首先考虑递归出口。我们想要返回的总是一个 `p` 和/或 `q` 的祖宗节点，所以以当前节点 `root` 的左右子树中必须有 `p` 和/或 `q` （自然，也有其祖宗节点），否则返回空节点：

```cpp
if (!left && !right)
    return nullptr;
```

> 按照这种思路，节点不为空即说明该节点是 `p` 或 `q` 或者它们之一/公共的祖宗节点

其余情况，即 `root` 的左右子树不都为空，说明它们之中有 `p` 和/或 `q` 及其祖宗节点：

 :one: 先看看最简单的情况：类似上面的示例1，当前节点 `root` 的左孩子 `left` 和 `right` 恰好就是 `p` 和 `q` （对应关系无所谓），则 `root` 就是它们的最近公共祖先，此时返回 `root` 即可：

```cpp
if (left && right)
    return root;
```

:two: 如果当前节点是 `p` 或 `q` ，也直接返回当前节点即可：题目说了 **一个节点也可以是它自己的祖先** 

```cpp
if (root == p || root == q)
    return root;
```

:three: 如果 `left` 和 `right` 之间有且仅有一个不为空，则返回不为空的那个节点——该节点是 `p` 或 `q` 或它们之一/公共的祖先：

> 相当于上面示例2中的节点 `2` 

```cpp
if (left && !right)
    return left;
if (!left && right)
    return right;
```

整体C++代码如下：

```cpp
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // 基于后序遍历
    if (!root)
        return nullptr;
    if (root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);   // 左
    TreeNode *right = lowestCommonAncestor(root->right, p, q); // 右

    // 中
    if (left && !right)
        return left;
    if (!left && right)
        return right;
    if (left && right)
        return root;
    else // 左右孩子都为空
        return nullptr;
}
```

该算法更详细的讲解参见 [代码随想录的本题题解](https://programmercarl.com/0236.二叉树的最近公共祖先.html#算法公开课) 。

 