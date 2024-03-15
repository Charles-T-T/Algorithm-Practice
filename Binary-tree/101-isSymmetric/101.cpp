#include <iostream>
#include <queue>

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
����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�
ʾ�� 1��
���룺root = [1,2,2,3,4,4,3]
�����true

ʾ�� 2��
���룺root = [1,2,2,null,3,null,3]
�����false
*/

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        // ˼·�������������ֱ𰴡������ҡ��͡����ҵ��󡱵�˳���������������Ƚ�
        if (!root)
            return false;
        if (!root->left && !root->right)
            return true;
        if (!root->left || !root->right)
            return false;

        queue<TreeNode *> ql, qr; // ���������ڵ����
        ql.push(root->left), qr.push(root->right);
        TreeNode *curLeft, *curRight;
        int curSize;
        int llFlag, lrFlag, rlFlag, rrFlag; // ����������������������Ĵ������
        while (!ql.empty() || !qr.empty())
        {
            if (ql.size() != qr.size()) // ���������ڵ�������һ������϶�������ԳƵ�
                return false;

            curSize = ql.size();
            for (int i = 0; i < curSize; i++)
            {
                curLeft = ql.front(), curRight = qr.front();
                if (curLeft->val != curRight->val)
                    return false;

                if (curLeft->left)
                    llFlag = 1;
                else
                    llFlag = 0;

                if (curLeft->right)
                    lrFlag = 1;
                else
                    lrFlag = 0;

                if (curRight->left)
                    rlFlag = 1;
                else
                    rlFlag = 0;
                
                if (curRight->right)
                    rrFlag = 1;
                else
                    rrFlag = 0;

                if ((llFlag ^ rrFlag) || (lrFlag ^ rlFlag))
                    return false;

                ql.pop(), qr.pop();
                if (curLeft->left)
                    ql.push(curLeft->left);
                if (curLeft->right)
                    ql.push(curLeft->right);

                if (curRight->right)
                    qr.push(curRight->right);
                if (curRight->left)
                    qr.push(curRight->left);
            }
        }

        return true;
    }
};