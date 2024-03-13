#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
����������ĸ��ڵ� root ��������ڵ�ֵ �Ե����ϵĲ������ �� ��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����

ʾ�� 1��
���룺root = [3,9,20,null,null,15,7]
�����[[15,7],[9,20],[3]]

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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        // ˼·����һ��Ĳ������һ����ֻ�����Ѹ���vector��˳��תһ�¼���
        if (!root)
            return resVec;

        queue<TreeNode *> qt;
        TreeNode *curNode;
        int curSize;

        qt.push(root);
        while (!qt.empty())
        {
            vector<int> curLevVec;
            curSize = qt.size();
            for (int i = 0; i < curSize; i++)
            {
                curNode = qt.front();
                qt.pop();
                curLevVec.push_back(curNode->val);

                if (curNode->left)
                    qt.push(curNode->left);
                if (curNode->right)
                    qt.push(curNode->right);
            }
            resVec.push_back(curLevVec);
        }

        reverse(resVec.begin(), resVec.end());
        return resVec;
    }

private:
    vector<vector<int>> resVec;
};