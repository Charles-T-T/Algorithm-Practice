#include <iostream>
#include <vector>
#include <stack>
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
����������ĸ��ڵ� root ��������ڵ�ֵ�� ������� �� �������أ������ҷ������нڵ㣩��

ʾ�� 1��
���룺root = [3,9,20,null,null,15,7]
�����[[3],[9,20],[15,7]]

ʾ�� 2��
���룺root = [1]
�����[[1]]

ʾ�� 3��
���룺root = []
�����[]
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        /**
         * ˼·���ö���ʵ��
         * ÿ�㰴�մ������ұ�������Ȼ���մ������������
        */
        if (!root)
            return resVec;

        queue<TreeNode *> qt;
        TreeNode *curNode;
        int curSize; // ÿһ��Ľڵ���
        qt.push(root);
        while (!qt.empty())
        {
            curSize = qt.size(); // ����qt�Ĵ�С��仯������Ҫ�ȼ�¼
            vector<int> curLevVec; // ��ǰ��Ľڵ�ֵ������
            for (int i = 0; i < curSize; i++)
            {
                curNode = qt.front();
                curLevVec.push_back(curNode->val);
                qt.pop();

                // ���Һ��������
                if (curNode->left)
                    qt.push(curNode->left);
                if (curNode->right)
                    qt.push(curNode->right);
            }
            resVec.push_back(curLevVec);
        }

        return resVec;
    }

private:
    vector<vector<int>> resVec;
};