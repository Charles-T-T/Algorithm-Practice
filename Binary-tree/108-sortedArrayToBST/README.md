# 108. 将有序数组转换为二叉搜索树

[点此跳转题目链接](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/)

## 题目描述

给你一个整数数组 `nums` ，其中元素已经按 **升序** 排列，请你将其转换为一棵平衡二叉搜索树。

> **平衡二叉树** 是指该树所有节点的左右子树的深度相差不超过 1。



**示例 1：**

![img](./btree1.jpg)

![img](./btree2.jpg)

```
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案
```

**示例 2：**

![img](./btree.jpg)

```
输入：nums = [1,3]
输出：[3,1]
解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
```

 

**提示：**

- `1 <= nums.length <= 104`
- `-104 <= nums[i] <= 104`
- `nums` 按 **严格递增** 顺序排列



## 题解

题目要求生成的BST是 **平衡** 的，即要尽量让各节点的左右子树高度相同，故联想到 **二分** 的思想：

- 每次取当前数组的中位数作为根节点
- 其左边部分的子数组递归生成其左子树
- 其右边部分的子数组递归生成其右子树

>  可以任意写一个简单的递增序列，模拟一下，就理解了。

**代码（C++）**

```cpp
TreeNode *getRoot(const auto &nums, int left, int right) {
    // 递归出口：左右指针错开
    if (left > right)
        return nullptr;
    // 当前数组切片的中位数作为根节点
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = getRoot(nums, left, mid - 1);
    root->right = getRoot(nums, mid + 1, right);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return getRoot(nums, 0, nums.size() - 1);
}
```

也可以考虑迭代法，但是需要用多个数据结构存储子数组的左右指针和树节点等，代码复杂不少，这里参考 [代码随想录](https://programmercarl.com/0108.将有序数组转换为二叉搜索树.html#思路) 上Carl的解法：

```cpp
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) return nullptr;

    TreeNode* root = new TreeNode(0);   // 初始根节点
    queue<TreeNode*> nodeQue;           // 放遍历的节点
    queue<int> leftQue;                 // 保存左区间下标
    queue<int> rightQue;                // 保存右区间下标
    nodeQue.push(root);                 // 根节点入队列
    leftQue.push(0);                    // 0为左区间下标初始位置
    rightQue.push(nums.size() - 1);     // nums.size() - 1为右区间下标初始位置

    while (!nodeQue.empty()) {
        TreeNode* curNode = nodeQue.front();
        nodeQue.pop();
        int left = leftQue.front(); leftQue.pop();
        int right = rightQue.front(); rightQue.pop();
        int mid = left + ((right - left) / 2);

        curNode->val = nums[mid];       // 将mid对应的元素给中间节点

        if (left <= mid - 1) {          // 处理左区间
            curNode->left = new TreeNode(0);
            nodeQue.push(curNode->left);
            leftQue.push(left);
            rightQue.push(mid - 1);
        }

        if (right >= mid + 1) {         // 处理右区间
            curNode->right = new TreeNode(0);
            nodeQue.push(curNode->right);
            leftQue.push(mid + 1);
            rightQue.push(right);
        }
    }
    return root;
}
```

