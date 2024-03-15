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
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例 1:
输入: [1,2,3,null,5,null,4]
输出: [1,3,4]

示例 2:
输入: [1,null,3]
输出: [1,3]

示例 3:
输入: []
输出: []
*/

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        /**
         * 思路：仍是层序遍历，但是只返回最右孩子
         * 仍采用队列，但是让最右孩子入结果数组
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
            resVec.push_back(curNode->val); // 此时的curNode必是最右边的
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