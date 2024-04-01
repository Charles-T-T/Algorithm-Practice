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
����һ���ǿն������ĸ��ڵ� root , ���������ʽ����ÿһ��ڵ��ƽ��ֵ����ʵ�ʴ���� 10-5 ���ڵĴ𰸿��Ա����ܡ�

ʾ�� 1��
���룺root = [3,9,20,null,null,15,7]
�����[3.00000,14.50000,11.00000]
���ͣ��� 0 ���ƽ��ֵΪ 3,�� 1 ���ƽ��ֵΪ 14.5,�� 2 ���ƽ��ֵΪ 11 ��
��˷��� [3, 14.5, 11] ��

ʾ�� 2:
���룺root = [3,9,20,15,7]
�����[3.00000,14.50000,11.00000]
*/

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;

        queue<TreeNode *> qt;
        qt.push(root);

        while (!qt.empty())
        {
            int curSize = qt.size();
            double curSum = 0;
            for (int i = 0; i < curSize; i++)
            {
                TreeNode *curNode = qt.front();
                curSum += curNode->val;
                
                if (curNode->left)
                    qt.push(curNode->left);
                if (curNode->right)
                    qt.push(curNode->right);
                qt.pop();
            }
            res.push_back(curSum / curSize);
        }

        return res;
    }
};