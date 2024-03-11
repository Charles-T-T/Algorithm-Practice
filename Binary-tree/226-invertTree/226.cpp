#include <iostream>

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

/*
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

示例 1：
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]

示例 2：
输入：root = [2,1,3]
输出：[2,3,1]

示例 3：
输入：root = []
输出：[]
*/

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // 尝试使用递归，出口：叶子节点
        if (!root)
            return nullptr;

        if (!root->left && !root->right) // 叶子节点
            return root;

        if (root->left && root->right){
            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = temp;
            invertTree(root->left);
            invertTree(root->right);
        }
        else if (root->left && !root->right){
            root->right = root->left;
            root->left = nullptr;
            invertTree(root->right);
        }
        else if (root->right && !root->left){
            root->left = root->right;
            root->right = nullptr;
            invertTree(root->left);
        }

        return root;
    }
};