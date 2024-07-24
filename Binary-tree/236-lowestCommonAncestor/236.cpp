#include "../TreeNode.h"

class Solution
{
public:
    // 递归法（回溯）
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 基于后序遍历
        if (!root)
            return nullptr;
        if (root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);   // 左
        TreeNode *right = lowestCommonAncestor(root->right, p, q); // 右

        // 中
        if (left && !right)
            return left;
        if (!left && right)
            return right;
        if (left && right)
            return root;
        else // 左右孩子都为空
            return nullptr;
    }
};
