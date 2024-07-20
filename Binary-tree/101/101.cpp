#include "../levelOrderTraversal/TreeNode.h"

class Solution
{
public:
    // 递归法
    bool compare(TreeNode *left, TreeNode *right)
    {
        // 首先排除左右有空节点的情况
        if (!left ^ !right)
            return false; // 一个为空、一个不为空，肯定不对称
        else if (!left && !right)
            return true; // 皆为空，对称
        // 然后处理左右都不为空的情况
        if (left->val != right->val)
            return false;
        bool outCmp = compare(left->left, right->right); // 比较外层情况
        bool inCmp = compare(left->right, right->left);  // 比较内层情况
        return outCmp && inCmp;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return false;
        return compare(root->left, root->right);
    }

    // 迭代法
    bool isSymmetric_II(TreeNode *root)
    {
        if (!root)
            return root;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();
            // 左右都为空：对称
            if (!left && !right)
                continue;
            // 左右之一为空，或左右不为空但值不相等：不对称
            if (!left ^ !right || left->val != right->val)
                return false;
            // 处理孩子节点
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};