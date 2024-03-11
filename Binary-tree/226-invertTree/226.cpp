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
����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣

ʾ�� 1��
���룺root = [4,2,7,1,3,6,9]
�����[4,7,2,9,6,3,1]

ʾ�� 2��
���룺root = [2,1,3]
�����[2,3,1]

ʾ�� 3��
���룺root = []
�����[]
*/

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // ����ʹ�õݹ飬���ڣ�Ҷ�ӽڵ�
        if (!root)
            return nullptr;

        if (!root->left && !root->right) // Ҷ�ӽڵ�
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