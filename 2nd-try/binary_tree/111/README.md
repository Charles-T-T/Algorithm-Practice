# 111. 二叉树的最小深度

[点此跳转题目链接](https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/)

## 题目描述

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

**说明：** 叶子节点是指没有子节点的节点。

 

**示例 1：**

![img](./ex_depth.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：2
```

**示例 2：**

```
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
```

 

**提示：**

- 树中节点数的范围在 `[0, 105]` 内
- `-1000 <= Node.val <= 1000`



## 题解

基本思路和 [104. 二叉树的最大深度](https://github.com/Charles-T-T/Algorithm-Practice/tree/master/2nd-try/binary_tree/104) 一样，递归解决需要注意对左右孩子有空节点的情况分类讨论：
```cpp
int getMin(TreeNode *root) {
    if (!root->left && !root->right)
        return 1;
    else if (root->left && !root->right)
        return getMin(root->left) + 1;
    else if (!root->left && root->right)
        return getMin(root->right) + 1;
    else
        return min(getMin(root->left), getMin(root->right)) + 1;
}

int minDepth(TreeNode *root)
{
    if (!root)
        return 0;
    return getMin(root);
}
```

迭代法也是在层序遍历的基础上实现，当发现当前层的某个节点已经是叶子节点时，该层的层数自然就是最小深度了：
```cpp
int minDepth(TreeNode *root) {
    // 层序遍历，期间发现已经遍历到叶子节点就返回当前层数即可
    if (!root)
        return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth = 1;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *cur = q.front();
            q.pop();
            if (!cur->left && !cur->right)
                return depth;
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        depth++;
    }
    return depth;
}
```





