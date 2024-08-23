#include "../../Binary-tree/TreeNode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution1I // 记忆化的递归暴力搜索
{
private:
    unordered_map<TreeNode*, int> valueMap; // 记忆化：记录搜索过的节点

public:
    int rob(TreeNode *root)
    {
        if (!root)
            return 0; // 空节点，没法抢
        if (!root->left && !root->right)
            return root->val; // 没有左右孩子，直接抢当前节点
        
        // 有记忆：直接采用求过的该节点能偷的最大金额
        if (valueMap.find(root) != valueMap.end())
            return valueMap[root];

        // 偷当前节点（父节点），则不能偷左右孩子，但考虑孙子节点
        int v1 = root->val;
        if (root->left)
            v1 += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            v1 += rob(root->right->left) + rob(root->right->right);

        // 不偷当前节点（父节点），则可以考虑左右孩子节点
        int v2 = rob(root->left) + rob(root->right);
        
        valueMap[root] = max(v1, v2); // 记录当前节点能偷的最大金额
        return valueMap[root];
    }
};

class Solution1II // 动态规划
{
private:
    /// @brief 抢或不抢当前节点root，在以root为根的子树中能获得的最大金额
    /// @param root（当前节点）
    /// @return 大小为2的数组dp，dp[0]表示不抢root能得最大金额，dp[1]表示抢
    vector<int> tryRob(TreeNode *root) {
        vector<int> dp(2, 0);
        if (!root)
            return dp; // 空节点，抢不抢都没钱

        vector<int> left = tryRob(root->left); // 抢或不抢左孩子
        vector<int> right = tryRob(root->right); // 抢或不抢右孩子

        // 不抢当前节点，则其子节点可抢可不抢
        dp[0] = max(left[0], left[1]) + max(right[0], right[1]);

        // 抢当前节点，则其子节点绝对不能抢
        dp[1] = root->val + left[0] + right[0];

        return dp;
    }

public:
    int rob(TreeNode *root)
    {
        vector<int> dp = tryRob(root);
        return max(dp[0], dp[1]);
    }
};