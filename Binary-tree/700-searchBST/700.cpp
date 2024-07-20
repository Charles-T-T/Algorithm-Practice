#include "../TreeNode.h"

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // 递归出口：空节点或找到目标值
        if (!root)
            return nullptr;
        if (root->val == val)   
            return root;
        // 根据二叉搜索树的性质搜索
        if (root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};