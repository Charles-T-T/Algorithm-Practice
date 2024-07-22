# 501. 二叉搜索树中的众数

[点此跳转题目链接](https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/)

## 题目描述

给你一个含重复值的二叉搜索树（BST）的根节点 `root` ，找出并返回 BST 中的所有 [众数](https://baike.baidu.com/item/众数/44796)（即，出现频率最高的元素）。

如果树中有不止一个众数，可以按 **任意顺序** 返回。

假定 BST 满足如下定义：

- 结点左子树中所含节点的值 **小于等于** 当前节点的值
- 结点右子树中所含节点的值 **大于等于** 当前节点的值
- 左子树和右子树都是二叉搜索树

 

**示例 1：**

![img](./mode-tree.jpg)

```
输入：root = [1,null,2,2]
输出：[2]
```

**示例 2：**

```
输入：root = [0]
输出：[0]
```

 

**提示：**

- 树中节点的数目在范围 `[1, 104]` 内
- `-105 <= Node.val <= 105`

 

**进阶：** 你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）



## 题解

既然是找众数，那么将二叉树遍历一遍、记录每个数出现的频率，是必不可少的了。常规思路应该是：

- 遍历该树，同时记录节点值的出现频率

- 找到最大的出现频率

- 将出现频率最大的数加入结果集

  > :warning: 注意题目说了，众数可能不止一个

当然，后两步可以合并：当发现更大的频率的时候，先将现有结果集清空，再加入新的最高频数字。这种方法的C++代码如下：
```cpp
class Solution
{
public:
    unordered_map<int, int> freqMap; // 用一个哈希表记录每个数值出现的频率
    int maxShowTime = -1;
    
    // 中序遍历
    void traversal(TreeNode *cur)
    {
        if (cur->left)
            traversal(cur->left); // 左
        freqMap[cur->val]++;      // 中
        if (cur->right)
            traversal(cur->right); // 右
    }

    vector<int> findMode(TreeNode *root)
    {
        traversal(root);
        vector<int> res;
        for (const auto &pair : freqMap)
        {
            if (pair.second > maxShowTime)
            {
                maxShowTime = pair.second;
                res.clear(); // 出现更高频的元素，将原来的结果集清空
                res.push_back(pair.first);
            }
            else if (pair.second == maxShowTime)
                res.push_back(pair.first); // 众数可能不止一个
        }
        return res;
    }
};
```

不过，上述方法显然对任意树是通用的，意味着我们并没有利用到二叉搜索树的独特性质。同时，题目进阶要求也说了，可以不使用额外空间解决此题（上面的算法有个额外的哈希表空间开销）。

即是二叉搜索树，又要遍历之，自然联想到性质：

- **二叉搜索树的中序遍历结果是一个从小到大的有序数列** 

所以，我们可以采用中序遍历的方法：

- 如果当前节点值和上一个节点值相同，则当前频率加1；否则，说明遍历到一个新数值的节点，将当前频率重置为1
- 如果当前频率等于最大频率，则将当前节点值加入结果集
- 如果当前频率大于最大频率，则更新最大频率，清空原来结果集，将当前节点值接入结果集

这样，就避免了额外的空间开销：

```cpp
class Solution
{
public:
    int maxShowTime = -1;
    int curShowTime = 0;
    TreeNode *pre = nullptr; // 中序遍历序列中，当前节点的前一个节点
    vector<int> res;
    // 中序遍历
    void traversal(TreeNode *cur)
    {
        // 左
        if (cur->left)
            traversal(cur->left); 
        
        // 中
        if (!pre)
            curShowTime = 1; // 第一个节点
        else if (cur->val == pre->val)
            curShowTime++; // 相同的节点值
        else
            curShowTime = 1; // 新的节点值
        
        pre = cur; // 更新前节点指针

        if (curShowTime == maxShowTime)
            res.push_back(cur->val);
        
        if (curShowTime > maxShowTime) {
            maxShowTime = curShowTime; // 更新最大出现频率
            res.clear();               // 清除之前的结果
            res.push_back(cur->val);
        }

        // 右
        if (cur->right)
            traversal(cur->right);
    }

    vector<int> findMode(TreeNode *root)
    {
       traversal(root);
       return res;
    }
};
```

