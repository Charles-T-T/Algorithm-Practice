#include "../TreeNode.h"

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // 在叶子节点插入
        if (!root)
            return new TreeNode(val);
        TreeNode *cur = root;
        TreeNode *pre;
        while (cur) {
            pre = cur;
            if (val < cur->val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if (val < pre->val)
            pre->left = new TreeNode(val);
        else 
            pre->right = new TreeNode(val);
        return root;
    }
};