#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        // �ݹ鷨
        if (root == nullptr)
            return resVec;

        inorderTraversal(root->left);
        resVec.push_back(root->val);
        inorderTraversal(root->right);

        return resVec;
    }

    vector<int> inorderTraversal_II(TreeNode *root)
    {
        /**
         * ���õ�����
         * ��ջʵ��
        */
        if (root == nullptr)
            return resVec;

        stack<TreeNode *> nodeStack;
        TreeNode *curNode = root;

        while (curNode || !nodeStack.empty())
        {
            if (curNode) // �ҵ���ǰ�ڵ�������ӽڵ�
            {
                nodeStack.push(curNode);
                curNode = curNode->left;
            }
            else
            {
                curNode = nodeStack.top();
                nodeStack.pop();
                resVec.push_back(curNode->val); // ���ڵ�
                curNode = curNode->right; // �Һ���
            }
        }

        return resVec;
    }
};