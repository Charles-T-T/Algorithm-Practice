#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
        bool inCmp = compare(left->right, right->left); // 比较内层情况
        return outCmp && inCmp; 
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return false;
        return compare(root->left, root->right);
    }
};