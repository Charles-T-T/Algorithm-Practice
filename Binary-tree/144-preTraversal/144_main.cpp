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
    vector<int> preorderTraversal(TreeNode *root)
    {
        // �ݹ鷨
        if (root == nullptr)
            return resVec;

        resVec.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return resVec;
    }

    vector<int> preorderTraversal_II(TreeNode *root)
    {
        /**
         * ������
         * ˼·����ջģ��
         * ����ջ�����ԣ�Ҫ�õ������У����ҡ���ǰ�����˳��
         * ��Ӧ�ð��ա����У����󡱵�˳����ջ
        */
        if (root == nullptr)
            return resVec;

        stack<TreeNode*> nodeStack;
        TreeNode *curNode;
        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            curNode = nodeStack.top();
            nodeStack.pop();
            resVec.push_back(curNode->val);

            if (curNode->right)
                nodeStack.push(curNode->right);
            if (curNode->left)
                nodeStack.push(curNode->left);
        }

        return resVec;
    }

    vector<int> preorderTraversal_III(TreeNode *root)
    {
        /**
         * ͳһ������
         * Ҫ�õ��������ҡ�
         * ���ա������С���ջ
         */
        if (root == nullptr)
            return resVec;

        stack<TreeNode *> nodeStack;
        TreeNode *curNode;
        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            curNode = nodeStack.top();
            if (curNode)
            {
                nodeStack.pop();

                if (curNode->right)
                    nodeStack.push(curNode->right);

                if (curNode->left)
                    nodeStack.push(curNode->left);

                nodeStack.push(curNode);
                nodeStack.push(nullptr);
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