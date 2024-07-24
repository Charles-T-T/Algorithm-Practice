# 538. 把二叉搜索树转换为累加树

[点此跳转题目链接](https://leetcode.cn/problems/convert-bst-to-greater-tree/description/)

## 题目描述

给出二叉 **搜索** 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 `node` 的新值等于原树中大于或等于 `node.val` 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

- 节点的左子树仅包含键 **小于** 节点键的节点。
- 节点的右子树仅包含键 **大于** 节点键的节点。
- 左右子树也必须是二叉搜索树。

**注意：** 本题和 1038: https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同

 

**示例 1：**

<img src="./tree.png" alt="img" width="600" />

```
输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
```

**示例 2：**

```
输入：root = [0,null,1]
输出：[1,null,1]
```

**示例 3：**

```
输入：root = [1,0,2]
输出：[3,3,2]
```

**示例 4：**

```
输入：root = [3,2,4,1]
输出：[7,9,4,10]
```

 

**提示：**

- 树中的节点数介于 `0` 和 `104` 之间。
- 每个节点的值介于 `-104` 和 `104` 之间。
- 树中的所有值 **互不相同** 。
- 给定的树为二叉搜索树。



## 题解

首先明确一下累加思路：

由于大于等于最大节点的累计值，就是该节点的值本身，所以应该**从最大的数开始累加**，同时维护一个累计值——每次将累计值加上当前节点值。

比如之后，大于等于第二大节点值的累计值，就是第一次的累计值，加上第二大节点的值。以此类推，就能得到所有节点的新值。

> 可以结合题目描述中示例1的图进行模拟，便于理解

那么我们自然需要按照节点值的大小，从大到小处理。可以考虑用一个优先队列，按照节点值从大到小存储各节点，然后依次取出队头元素处理：

```cpp
TreeNode *convertBST(TreeNode *root)
{
    if (!root)
        return nullptr;
    // 用一个优先队列，按原节点值从大到小存储所有节点
    auto cmp = [](TreeNode *a, TreeNode *b) {
        return a->val < b->val;
    };
    priority_queue<TreeNode *, vector<TreeNode *>, decltype(cmp)> pq(cmp);
    // 层序遍历
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *cur = q.front();
            q.pop();
            pq.push(cur); // 将节点加入优先队列
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }
    // 按原节点值从大到小更新节点值
    int biggerSum = 0; // 大于等于当前节点值的所有节点值之和
    while (!pq.empty())
    {
        biggerSum += pq.top()->val;
        pq.top()->val = biggerSum;
        pq.pop();
    }
    return root;
}
```

不过上述算法实际上可以应用于任意二叉树，也就是说它并没有利用二叉搜索树的性质特点。我们知道，**二叉搜索树的中序遍历结果是一个递增序列**，那么将它**反过来**，不就是我们需要的节点值递减序列了吗？

所以，我们可以采取**逆中序遍历**，在遍历的过程中完成累计和更新操作。代码和中序遍历差不多，调整一下顺序即可。若采用递归：

```cpp
int biggerSum = 0;
TreeNode *convertBST(TreeNode *root)
{
    // 逆中序遍历——右中左
    if (!root)
        return nullptr;

    root->right = convertBST(root->right); // 右
    biggerSum += root->val;                // 更新节点值之和
    root->val = biggerSum;                 // 中
    root->left = convertBST(root->left);   // 左

    return root;
}
```

若采用迭代：

```cpp
TreeNode *convertBST(TreeNode *root)
{
    // 基于统一迭代法
    if (!root)
        return nullptr;
    int biggerSum = 0;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();
        if (cur)
        {
            // 要得到“右中左”的逆中序遍历结果，则应按照“左中右”入栈
            if (cur->left)
                st.push(cur->left); // 左
            st.push(cur);           // 中
            st.push(nullptr);       // 空节点标记
            if (cur->right)
                st.push(cur->right); // 右
        }
        else
        {
            biggerSum += st.top()->val;
            st.top()->val = biggerSum; // 更新节点值
            st.pop();
        }
    }
    return root;
}
```



