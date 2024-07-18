# 112. 路径总合

[点此跳转题目链接](https://leetcode.cn/problems/path-sum/description/)

## 题目描述

给你二叉树的根节点 `root` 和一个表示目标和的整数 `targetSum` 。判断该树中是否存在 **根节点到叶子节点** 的路径，这条路径上所有节点值相加等于目标和 `targetSum` 。如果存在，返回 `true` ；否则，返回 `false` 。

**叶子节点** 是指没有子节点的节点。

 

**示例 1：**

![img](./pathsum1.jpg)

```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
解释：等于目标和的根节点到叶节点路径如上图所示。
```

**示例 2：**

![img](./pathsum2.jpg)

```
输入：root = [1,2,3], targetSum = 5
输出：false
解释：树中存在两条根节点到叶子节点的路径：
(1 --> 2): 和为 3
(1 --> 3): 和为 4
不存在 sum = 5 的根节点到叶子节点的路径。
```

**示例 3：**

```
输入：root = [], targetSum = 0
输出：false
解释：由于树是空的，所以不存在根节点到叶子节点的路径。
```

 

**提示：**

- 树中节点的数目在范围 `[0, 5000]` 内
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`



## 题解

首先可以用DFS递归秒杀：

```cpp
bool hasPathSum(TreeNode *root, int targetSum)
{
    // 递归出口1：空节点
    if (!root)
        return false;
    // 递归出口2：加上当前节点值求和等于targetSum，且当前节点为叶子节点
    if (root->val == targetSum && !root->left && !root->right)
        return true;
    // 递归探索左右子树
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}
```

然后再想想迭代法，发现这题和 [257. 二叉树的所有路径](https://github.com/Charles-T-T/Algorithm-Practice/tree/master/2nd-try/binary_tree/257) 其实如出一辙（具体思路和注意细节见那篇题解），只需要将其中记录路径的逻辑替换成计算路径节点值之和就行了：

```cpp
bool hasPathSum_II(TreeNode *root, int targetSum) {
    // 基于前序遍历的统一迭代法实现
    if (!root)
        return false;
    stack<TreeNode*> nodeSt;
    nodeSt.push(root);
    stack<int> sumSt;
    sumSt.push(root->val);
    while (!nodeSt.empty()) {
        TreeNode *node = nodeSt.top();
        nodeSt.pop();
        int sum = sumSt.top(); 
        sumSt.pop();
        if (node) {
            if (node->right) {
                nodeSt.push(node->right); // 右
                sumSt.push(sum + node->right->val);
            }
            if (node->left) {
                nodeSt.push(node->left); // 左
                sumSt.push(sum + node->left->val);
            }
            nodeSt.push(node); // 中
            nodeSt.push(nullptr); // 空指针标记
            sumSt.push(sum);
        }
        else {
            if (sum == targetSum && !nodeSt.top()->left && !nodeSt.top()->right)
                return true;
            nodeSt.pop();
        }
    }
    return false;
}
```

