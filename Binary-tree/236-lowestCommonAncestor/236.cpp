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

        TreeNode *left = lowestCommonAncestor(root->left, p, q);   // 左
        TreeNode *right = lowestCommonAncestor(root->right, p, q); // 右

        // 中
        // 当前节点为p, q之一
        if (root == p || root == q)
            return root;
        // 否则，看左右孩子节点的情况
        else if (left && right)
            return root;
        else if (left && !right)
            return left;
        else if (!left && right)
            return right;
        else // 左右都为空
            return nullptr;
    }
};
