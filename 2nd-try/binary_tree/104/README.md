# 104. 二叉树的最大深度

[点此跳转题目链接](https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/)

## 题目描述

给定一个二叉树 `root` ，返回其最大深度。

二叉树的 **最大深度** 是指从根节点到最远叶子节点的最长路径上的节点数。

 

**示例 1：**

![img](./tmp-tree.jpg)

 

```
输入：root = [3,9,20,null,null,15,7]
输出：3
```

**示例 2：**

```
输入：root = [1,null,2]
输出：2
```

 

**提示：**

- 树中节点的数量在 `[0, 104]` 区间内。
- `-100 <= Node.val <= 100`



## 题解

首先考虑递归解决：显然，当前节点的深度 = 左、右孩子节点的深度最大值 + 1。

```cpp
int maxDepth(TreeNode *root)
{
    if (!root) 
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
```

非常简单。

然后考虑迭代法，由于为了找到最深的一支，不得不遍历整个二叉树，所以联想到利用层序遍历，返回其层数即可。偷个懒，直接搬层序遍历代码调用，不在其内部修改了：
```cpp
int maxDepth_II(TreeNode *root) {
    // 层序遍历，返回层数即可
    return levelOrder(root).size();
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    queue<TreeNode *> q;
    if (!root)
        return res;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size(); // 注意！先记录当前队长，因为之后会变
        vector<int> level;   // 当前这一层的节点值
        for (int i = 0; i < size; ++i)
        {
            level.push_back(q.front()->val);
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        res.push_back(level);
    }
    return res;
}
```

