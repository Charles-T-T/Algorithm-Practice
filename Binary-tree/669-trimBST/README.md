# 669. 修剪二叉搜索树

[点此跳转题目链接](https://leetcode.cn/problems/trim-a-binary-search-tree/description/)

## 题目描述

给你二叉搜索树的根节点 `root` ，同时给定最小边界`low` 和最大边界 `high`。通过修剪二叉搜索树，使得所有节点的值在`[low, high]`中。修剪树 **不应该** 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 **唯一的答案** 。

所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

 

**示例 1：**

![img](./trim1.jpg)

```
输入：root = [1,0,2], low = 1, high = 2
输出：[1,null,2]
```

**示例 2：**

![img](./trim2.jpg)

```
输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
输出：[3,2,null,1]
```

 

**提示：**

- 树中节点数在范围 `[1, 104]` 内
- `0 <= Node.val <= 104`
- 树中每个节点的值都是 **唯一** 的
- 题目数据保证输入是一棵有效的二叉搜索树
- `0 <= low <= high <= 104`



## 题解

首先试试递归。第一步考虑递归出口，对于当前正在处理的节点：

- 若为空节点，直接返回

- 若节点值小于 `low` ，返回其右节点

  > 此时，当前节点的左子树中的值，全都小于当前节点值，自然也全都小于 `low` ，故可以直接修剪掉左子树，用右子树取代当前（根）节点。下面情况同理。

- 若节点值大于 `high` ，返回其左节点

否则，当前节点处于目标区间内，递归处理其左右子树即可。整体代码如下：

```cpp
TreeNode *trimBST(TreeNode *root, int low, int high)
{
    // 空节点直接返回
    if (!root)
        return nullptr;
    // 节点值不在目标区间
    if (root->val < low) {
        TreeNode *right = trimBST(root->right, low, high);
        return right;
    }
    if (root->val > high) {
        TreeNode *left = trimBST(root->left, low, high);
        return left;
    }
    // 节点值在目标区间
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}
```

接下来再试试迭代法，需要注意的是 :warning: 

- 一开始就要让 `root` 指针先走到目标区间内
- 迭代时注意，修剪掉某棵子树后，新接过来的子树可能还是不满足条件，故此处的逻辑判断不能只用一个 `if` ，而要用 `while` 

整体代码如下：

```cpp
TreeNode *trimBST(TreeNode *root, int low, int high)
{
    // 先让root指针走到目标区间内的值
    while (root && (root->val < low || root->val > high)) {
        if (root->val < low)
            root = root->right;
        if (root->val > high)
            root = root->left;
    }
    // 此时的root已经处于目标区间内了，处理其左子树
    TreeNode *cur = root;
    while (cur) {
        while (cur->left && cur->left->val < low) // 注意此处要用while判断
            cur->left = cur->left->right;
        cur = cur->left;
    }
    // 此时的root已经处于目标区间内了，处理其右子树
    cur = root;
    while (cur) {
        while (cur->right && cur->right->val > high) // 注意此处要用while判断
            cur->right = cur->right->left;
        cur = cur->right;
    }
    return root;
}
```

