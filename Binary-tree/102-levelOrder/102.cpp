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
         * ����ʹ���������У����ڴ�ŵ�ǰ�����һ��
         * ����ʹ������������ʵ��������
        */
        if (!root)
            return resVec;

        queue<TreeNode *> qt1, qt2;
        TreeNode *curNode;

        qt1.push(root);
        // �ǿն��д浱ǰ��ڵ㣬��һ������׼������һ��ڵ�
        while (!qt1.empty() || !qt2.empty())
        {
            if (!qt1.empty())
            {
                vector<int> curLevVec; // �洢��ǰ��Ľڵ�ֵ
                while (!qt1.empty())
                {
                    curNode = qt1.front();
                    curLevVec.push_back(curNode->val);
                    qt1.pop();

                    // ����һ��ڵ�浽qt2
                    if (curNode->left)
                        qt2.push(curNode->left);
                    if (curNode->right)
                        qt2.push(curNode->right);
                }
                resVec.push_back(curLevVec);
            }
            else
            {
                vector<int> curLevVec; // �洢��ǰ��Ľڵ�ֵ
                while (!qt2.empty())
                {
                    curNode = qt2.front();
                    curLevVec.push_back(curNode->val);
                    qt2.pop();

                    // ����һ��ڵ�浽qt1
                    if (curNode->left)
                        qt1.push(curNode->left);
                    if (curNode->right)
                        qt1.push(curNode->right);
                }
                resVec.push_back(curLevVec);
            }
        }
        

        return resVec;
    }

private:
    vector<vector<int>> resVec;
};