#include "../TreeNode.h"

// 适用于普通二叉树
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return nullptr;
        if (root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && !right)
            return left;
        if (!left && right)
            return right;
        if (left && right)
            return root;
        else
            return nullptr;
    }
};

// 结合BST的特点
class Solution2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 层序遍历，第一次遇到p，q节点值区间内的节点即为它们的最近公共祖先
        queue<TreeNode*> que;
        que.push(root); // 题目确定了树不为空
        int big = p->val > q->val ? p->val : q->val;
        int small = p->val > q->val ? q->val : p->val;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                if (que.front()->val >= small && que.front()->val <= big)
                    return que.front();
                if (que.front()->left)
                    que.push(que.front()->left);
                if (que.front()->right)
                    que.push(que.front()->right);
                que.pop();
            }
        }
        return nullptr;
    }
};