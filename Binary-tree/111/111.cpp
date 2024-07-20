#include "../levelOrderTraversal/TreeNode.h"

class Solution
{
public:
    // 递归法
    int getMin(TreeNode *root) {
        if (!root->left && !root->right)
            return 1;
        else if (root->left && !root->right)
            return getMin(root->left) + 1;
        else if (!root->left && root->right)
            return getMin(root->right) + 1;
        else
            return min(getMin(root->left), getMin(root->right)) + 1;
    }

    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return getMin(root);
    }

    // 迭代法
    int minDepth_II(TreeNode *root) {
        // 层序遍历，期间发现已经遍历到叶子节点就返回当前层数即可
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *cur = q.front();
                q.pop();
                if (!cur->left && !cur->right)
                    return depth;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
};