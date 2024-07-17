# 404. 左叶子之和

[点此跳转题目链接](https://leetcode.cn/problems/sum-of-left-leaves/description/)

## 题目描述

给定二叉树的根节点 `root` ，返回所有左叶子之和。

 

**示例 1：**

![img](./leftsum-tree.jpg)

```
输入: root = [3,9,20,null,null,15,7] 
输出: 24 
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
```

**示例 2:**

```
输入: root = [1]
输出: 0
```

 

**提示:**

- 节点数在 `[1, 1000]` 范围内
- `-1000 <= Node.val <= 1000`



## 题解

比较简单，还是可以递归和迭代实现。要注意的就是判断左叶子只能通过其父节点判断：
```cpp
root->left && !root->left->left && !root->left->right
```

即父节点有左孩子、且这个左孩子无左右孩子，则这个左孩子是左叶子。

**递归法**

```cpp
int sumOfLeftLeaves(TreeNode *root)
{
    // 递归出口1：当前节点为空
    if (!root)
        return 0;
    int leftSum = sumOfLeftLeaves(root->left);
    // 递归出口2：当前节点的左孩子是左叶子
    if (root->left && !root->left->left && !root->left->right)
        leftSum = root->left->val;
    return leftSum + sumOfLeftLeaves(root->right);
}
```

**迭代法**

```cpp
int sumOfLeftLeaves_II(TreeNode *root) {
    if (!root)
        return 0;
    queue<TreeNode*> q;
    q.push(root);
    int sum = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *cur = q.front();
            if (cur->left) {
                q.push(cur->left);
                if (!cur->left->left && !cur->left->right)
                    sum += cur->left->val;
            }
            if (cur->right)
                q.push(cur->right);
            q.pop();
        }
    }
    return sum;
}
```

