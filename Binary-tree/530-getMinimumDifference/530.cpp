#include "../TreeNode.h"

class Solution
{
public:
    int res = INT_MAX;
    TreeNode *pre; // 暂存中序遍历时前一个节点的指针
    void traversal(TreeNode *root)
    {
        if (root->left)
            traversal(root->left); // 左
        if (pre)
            res = min(res, root->val - pre->val); // 中
        pre = root;                               // 更新前指针
        if (root->right)
            traversal(root->right); // 右
    }

    int getMinimumDifference(TreeNode *root)
    {
        traversal(root);
        return res;
    }
};