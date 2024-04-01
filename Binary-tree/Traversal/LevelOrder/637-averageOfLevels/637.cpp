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
给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[3.00000,14.50000,11.00000]
解释：第 0 层的平均值为 3,第 1 层的平均值为 14.5,第 2 层的平均值为 11 。
因此返回 [3, 14.5, 11] 。

示例 2:
输入：root = [3,9,20,15,7]
输出：[3.00000,14.50000,11.00000]
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