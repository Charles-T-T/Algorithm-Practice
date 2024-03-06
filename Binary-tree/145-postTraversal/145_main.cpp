#include <iostream>
#include <vector>

using namespace std;

/*
����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������

ʾ�� 1��
���룺root = [1,null,2,3]
�����[1,2,3]

ʾ�� 2��
���룺root = []
�����[]

ʾ�� 3��
���룺root = [1]
�����[1]

ʾ�� 4��
���룺root = [1,2]
�����[1,2]

ʾ�� 5��
���룺root = [1,null,2]
�����[1,2]
*/

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
private:
    vector<int> resVec;

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return resVec;
        
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        resVec.push_back(root->val);

        return resVec;
    }
};