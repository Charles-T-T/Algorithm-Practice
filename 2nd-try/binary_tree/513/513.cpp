#include "../TreeNode.h"

/*
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

示例 1:
输入: root = [2,1,3]
输出: 1

示例 2:
输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
*/

class Solution
{
public:
    // 迭代法：层序遍历到底层，返回底层第一个节点的值
    int findBottomLeftValue(TreeNode *root)
    {
        vector<vector<int>> levels = levelOrder(root);
        return levels[levels.size() - 1][0];
    }

    // 递归法
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
};