# 235. 二叉搜索树的最近公共祖先

[点此跳转题目链接](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/)

## 题目描述

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

[百度百科](https://baike.baidu.com/item/最近公共祖先/8918834?fr=aladdin)中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）。”

例如，给定如下二叉搜索树: root = [6,2,8,0,4,7,9,null,null,3,5]

![img](./binarysearchtree_improved.png)

 

**示例 1:**

```
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。
```

**示例 2:**

```
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
```

 

**说明:**

- 所有节点的值都是唯一的。
- p、q 为不同节点且均存在于给定的二叉搜索树中。



## 题解

这题是 [236. 二叉树的最近公共祖先](https://github.com/Charles-T-T/Algorithm-Practice/tree/master/Binary-tree/236-lowestCommonAncestor) 的特殊情况，所以也可以采取通用解法：

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

但是这样就没有利用二叉搜索树的性质特点了。由于二叉搜索树是**有序的**，我们可以发现：

**从根节点开始搜索，第一次出现值处于 $[p, q]$ 区间的节点，就是 `p` 和 `q` 的最近公共祖先。**

> 此处不失一般性，假设 $p < q$ ，下同

以下图为例：

<img src="./20220926164214.png" alt="img" width="700" />

> 图片来源：[代码随想录](https://programmercarl.com/0235.二叉搜索树的最近公共祖先.html#算法公开课)

可以看到，节点 `5` 是第一次出现在目标区间 $[1, 9]$ 中的节点。此时，

- 如果再向左搜索 `q` ，就必然错过 `p`
- 如果再向右搜索 `p` ，就必然错过 `q` 

所以， `5` 就是它们的最近公共节点了。利用这一性质，我们可以直接采用层序遍历，找到第一个处于 $[p, q]$ 区间的节点即可：

```cpp
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // 层序遍历，第一次遇到p，q节点值区间内的节点即为它们的最近公共祖先
    queue<TreeNode*> que;
    que.push(root); // 题目确定了树不为空
    int big = p->val > q->val ? p->val : q->val;
    int small = p->val > q->val ? q->val : p->val;
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; ++i) {
            if (que.front()->val >= small && que.front()->val <= big)
                return que.front();
            if (que.front()->left)
                que.push(que.front()->left);
            if (que.front()->right)
                que.push(que.front()->right);
            que.pop();
        }
    }
    return nullptr;
}
```

