#include "../TreeNode.h"

/*
给定二叉树的根节点 root ，返回所有左叶子之和。

示例 1：
输入: root = [3,9,20,null,null,15,7]
输出: 24
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

示例 2:
输入: root = [1]
输出: 0
*/

class Solution
{
public:
    // 递归法
    int sumOfLeftLeaves(TreeNode *root)
    {
        // 递归出口1：当前节点为空
        if (!root)
            return 0;
        int leftSum = sumOfLeftLeaves(root->left);
        // 递归出口2：当前节点的左孩子是左叶子
        if (root->left && !root->left->left && !root->left->right)
            leftSum = root->left->val;
        return leftSum + sumOfLeftLeaves(root->right);
    }

    // 迭代法：基于层序遍历
    int sumOfLeftLeaves_II(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int sum = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *cur = q.front();
                if (cur->left)
                {
                    q.push(cur->left);
                    if (!cur->left->left && !cur->left->right)
                        sum += cur->left->val;
                }
                if (cur->right)
                    q.push(cur->right);
                q.pop();
            }
        }
        return sum;
    }
};

int main()
{
    TreeNode *root = getRootFromStr("1,2,3,4,5");
    Solution obj;
    int res = obj.sumOfLeftLeaves_II(root);
    cout << res << endl;
    return 0;
}