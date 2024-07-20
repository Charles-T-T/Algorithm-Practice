# 110. 平衡二叉树

[点此跳转题目链接](https://leetcode.cn/problems/balanced-binary-tree/description/)

## 题目描述

给定一个二叉树，判断它是否是平衡二叉树

> **平衡二叉树** 是指该树所有节点的左右子树的深度相差不超过 1。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg)

```
输入：root = [3,9,20,null,null,15,7]
输出：true
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg)

```
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
```

**示例 3：**

```
输入：root = []
输出：true
```

 

**提示：**

- 树中的节点数在范围 `[0, 5000]` 内
- `-104 <= Node.val <= 104`



## 题解

显然，一个二叉树是平衡的，**当且仅当它的所有子树都是平衡的**。听起来就很适合递归秒了：

```cpp
int getDepth(TreeNode *root)
{
    if (!root)
        return 0;
    return max(getDepth(root->left), getDepth(root->right)) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (!root)
        return true; // 空树是平衡树
    return abs(getDepth(root->left) - getDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
```

相应地，考虑一下迭代法。由于需要判断各节点“左右子树的深度差”是否大于1，联想到基于**后序遍历**实现本题：因为后序遍历处理某一节点时，总是已经访问过其左右子树节点了。

```cpp
// 基于层序遍历获取某个节点的深度
int getDepth(TreeNode *root)
{
    if (!root)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            if (q.front()->left)
                q.push(q.front()->left);
            if (q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        depth++;
    }
    return depth;
}

// 基于后序遍历检验平衡树
bool isBalanced(TreeNode *root)
{
    if (!root)
        return true;
    // 统一迭代法的后序遍历
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();
        if (cur)
        {
            st.push(cur);     // 中
            st.push(nullptr); // 空节点标记
            if (cur->left)
                st.push(cur->left); // 左
            if (cur->right)
                st.push(cur->right); // 右
        }
        else
        {
            if (abs(getDepth_II(st.top()->left) - getDepth_II(st.top()->right)) > 1)
                return false;
            st.pop();
        }
    }
    return true;
}
```

