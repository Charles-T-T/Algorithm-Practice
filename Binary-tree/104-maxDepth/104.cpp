#include <iostream>
#include <algorithm>
#include <stack>

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
����һ�������� root �������������ȡ�

�������� ������ ��ָ�Ӹ��ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

ʾ�� 1��
���룺root = [3,9,20,null,null,15,7]
�����3

ʾ�� 2��
���룺root = [1,null,2]
�����2
*/

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        /**
         * ���õݹ�
         * �ݹ���ڣ������Һ���
        */
        if (!root)
            return 0;
        TreeNode *leftSub = root->left;
        TreeNode *rightSub = root->right;
        return max(maxDepth(leftSub), maxDepth(rightSub)) + 1;
    }
};
