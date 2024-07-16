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
};