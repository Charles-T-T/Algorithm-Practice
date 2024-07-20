# 513. 找树左下角的值

[点此跳转题目链接](https://leetcode.cn/problems/find-bottom-left-tree-value/description/)

## 题目描述

给定一个二叉树的 **根节点** `root`，请找出该二叉树的 **最底层 最左边** 节点的值。

假设二叉树中至少有一个节点。

 

**示例 1:**

![img](./tree1.jpg)

```
输入: root = [2,1,3]
输出: 1
```

**示例 2:**

![img](./tree2.jpg)

```
输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
```

 

**提示:**

- 二叉树的节点个数的范围是 `[1,104]`
- `-231 <= Node.val <= 231 - 1` 



## 题解

题目说的很清楚了，目标先是 **“最底层”** ，再是 **“最左边”** ，所以考虑先用层序遍历得到最底层的节点值数组，然后返回数组第一个值，即为“左下角”的值了：

```cpp
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

int findBottomLeftValue(TreeNode *root)
{
    vector<vector<int>> levels = levelOrder(root); // 偷个懒，直接调用之前写过的层序遍历函数
    return levels[levels.size() - 1][0];
}
```

此外，我们还是可以考虑一下递归法，逐步递归到左下角。递归出口的判断也比较简单，即：若当前节点的左孩子是叶子节点，则根据其深度判断是否要更新左下角值：

```cpp
int maxDepth = -1;
int leftBottonVal = 0;

void traversal(TreeNode *root, int depth)
{
    // 递归出口：叶子节点
    if (!root->left && !root->right && depth > maxDepth)
    {
        leftBottonVal = root->val; // 更新当前探索到的左下角值
        maxDepth = depth;          // 更新当前探索到的最大深度
        return;
    }
    // 先处理左孩子，这样保证同一层记录最左节点
    if (root->left)
        traversal(root->left, depth + 1);
    // 再处理右孩子
    if (root->right)
        traversal(root->right, depth + 1);
}

int findBottomLeftValue_II(TreeNode *root)
{
    traversal(root, 0);
    return leftBottonVal;
}
```

