# 226. 翻转二叉树

[点此跳转题目链接](https://leetcode.cn/problems/invert-binary-tree/description/)

## 题目描述

给你一棵二叉树的根节点 `root` ，翻转这棵二叉树，并返回其根节点。

 

**示例 1：**

![img](./invert1-tree.jpg)

```
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
```

**示例 2：**

![img](./invert2-tree.jpg)

```
输入：root = [2,1,3]
输出：[2,3,1]
```

**示例 3：**

```
输入：root = []
输出：[]
```

 

**提示：**

- 树中节点数目范围在 `[0, 100]` 内
- `-100 <= Node.val <= 100`



## 题解

不难看出，要翻转整棵二叉树，就要将其 **每一个节点的左右孩子节点都交换** 。所以首先想到用递归秒杀：

```cpp
TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
```

进一步考虑用迭代法解决，则迭代顺序应该是“从根节点起，先翻转当前节点的孩子节点，再翻转当前节点的孩子节点的孩子节点，向下类推...”——这其实就是**前序遍历**的逻辑。因此，可以在前序遍历的 [统一迭代法](https://github.com/Charles-T-T/Algorithm-Practice/tree/master/2nd-try/binary_tree/orderTraversal) 基础上，将“节点加入结果集”的操作替换成“交换节点的左右孩子节点”即可：
```cpp
TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return root;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();
        if (cur)
        {
            if (cur->right)
                st.push(cur->right); // 右
            if (cur->left)
                st.push(cur->left); // 左
            st.push(cur);           // 中
            st.push(nullptr);       // 空节点标记
        }
        else
        {
            swap(st.top()->left, st.top()->right);
            st.pop();
        }
    }
    return root;
}
```

