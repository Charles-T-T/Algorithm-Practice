# 222. 完全二叉树的节点个数

[点此跳转题目链接](https://leetcode.cn/problems/count-complete-tree-nodes/description/)

## 题目描述

给你一棵 **完全二叉树** 的根节点 `root` ，求出该树的节点个数。

[完全二叉树](https://baike.baidu.com/item/完全二叉树/7773232?fr=aladdin) 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 `h` 层，则该层包含 `1~ 2h` 个节点。

 

**示例 1：**

![img](./complete.jpg)

```
输入：root = [1,2,3,4,5,6]
输出：6
```

**示例 2：**

```
输入：root = []
输出：0
```

**示例 3：**

```
输入：root = [1]
输出：1
```

 

**提示：**

- 树中节点的数目范围是`[0, 5 * 104]`
- `0 <= Node.val <= 5 * 104`
- 题目数据保证输入的树是 **完全二叉树**

 

**进阶：** 遍历树来统计节点是一种时间复杂度为 `O(n)` 的简单解决方案。你可以设计一个更快的算法吗？



## 题解

无脑算法当然就是遍历整棵树，记录节点个数即可（这样应该直接层序遍历最方便），时间复杂度为 $O(n)$ ，不赘述。

考虑利用完全二叉树的性质提升速度。根据其性质，完全二叉树的子树中有很多都是满二叉树，而一个 $n$ 层满二叉树的节点个数为 $2^n - 1$ 。所以我们可以利用这点，进行带剪枝的递归遍历：

- 以当前节点为根，所得子树为满二叉树，则按公式计算节点数
- 否则，递归计算节点数

其中，判断满二叉树的方法也很简单高效：看“最左”枝和“最右”枝的深度是否相同即可。

**代码（C++）**

```cpp
int countNodes(TreeNode *root)
{
    if (!root)
        return 0;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    int leftDepth = 0, rightDepth = 0; // 左、右子树深度
    while (left) {
        left = left->left;
        leftDepth++;
    }
    while (right) {
        right = right->right;
        rightDepth++;
    }
    if (leftDepth == rightDepth) // 满二叉树，直接用公式计算
        return (2 << leftDepth) - 1;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
```

> 这里用位运算， `2 << leftDepth` 相当于 $2^{leftDepth + 1}$ ，其中+1是因为 `leftDepth` 是子树深度，还要加上根节点的1才是相应的树深度 $n$ 。

