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
给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]

示例 2：
输入：root = [1]
输出：[[1]]

示例 3：
输入：root = []
输出：[]
*/

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        // 思路：和一般的层序遍历一样，只是最后把各层vector的顺序反转一下即可
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