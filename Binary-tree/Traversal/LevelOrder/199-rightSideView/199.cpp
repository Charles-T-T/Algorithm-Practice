#include <iostream>
#include <vector>
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
����һ���������� ���ڵ� root�������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��

ʾ�� 1:
����: [1,2,3,null,5,null,4]
���: [1,3,4]

ʾ�� 2:
����: [1,null,3]
���: [1,3]

ʾ�� 3:
����: []
���: []
*/

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        /**
         * ˼·�����ǲ������������ֻ�������Һ���
         * �Բ��ö��У����������Һ�����������
         */
        vector<int> resVec;
        if (!root)
            return resVec;

        queue<TreeNode *> qt;
        TreeNode *curNode;
        int curSize;
        qt.push(root);
        while (!qt.empty())
        {
            curNode = qt.front();
            curSize = qt.size();
            qt.pop();
            resVec.push_back(curNode->val); // ��ʱ��curNode�������ұߵ�
            if (curNode->right)
                qt.push(curNode->right);
            if (curNode->left)
                qt.push(curNode->left);

            for (int i = 0; i < curSize - 1; i++){
                curNode = qt.front();
                qt.pop();
                if (curNode->right)
                    qt.push(curNode->right);
                if (curNode->left)
                    qt.push(curNode->left);
            }
        }

        return resVec;
    }
};