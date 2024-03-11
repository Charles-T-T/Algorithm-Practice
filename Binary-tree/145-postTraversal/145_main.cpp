#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
        // �ݹ鷨
        if (root == nullptr)
            return resVec;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        resVec.push_back(root->val);

        return resVec;
    }

    vector<int> postorderTraversal_II(TreeNode *root)
    {
        /**
         * ������
         * �ο�Q144�������޸�һЩ˳��
         */
        if (!root)
            return resVec;

        stack<TreeNode *> nodeStack;
        TreeNode *curNode;

        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            curNode = nodeStack.top();
            resVec.push_back(curNode->val);
            nodeStack.pop();

            if (curNode->left)
                nodeStack.push(curNode->left);

            if (curNode->right)
                nodeStack.push(curNode->right);
        }
        reverse(resVec.begin(), resVec.end());

        return resVec;
    }

    vector<int> postorderTraversal_II(TreeNode *root)
    {
        /**
         * ͳһ������
         * Ҫ�õ��������С���˳��
         * ���ա������󡱵�˳����ջ
         */
        if (!root)
            return resVec;

        stack<TreeNode *> nodeStack;
        TreeNode *curNode;

        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            curNode = nodeStack.top();
            if (curNode)
            {
                nodeStack.push(nullptr);
                if (curNode->right)
                    nodeStack.push(curNode->right);
                if (curNode->left)
                    nodeStack.push(curNode->left);
            }
            else
            {
                nodeStack.pop();
                resVec.push_back(nodeStack.top()->val);
                nodeStack.pop();
            }
        }

        return resVec;
    }
};