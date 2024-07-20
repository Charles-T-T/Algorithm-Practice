#include "../TreeNode.h"

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        // 递归秒了
        // 递归出口：至少一个为空节点
        if (root1 && !root2)
            return root1;
        if (!root1 && root2)
            return root2;
        if (!root1 && !root2)
            return nullptr;
        // 合并节点
        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};