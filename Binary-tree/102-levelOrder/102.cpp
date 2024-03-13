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
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        /**
         * 思路：用队列实现
         * 每层按照从左往右遍历，自然按照从左往右入队列
        */
        if (!root)
            return resVec;

        queue<TreeNode *> qt;
        TreeNode *curNode;
        int curSize; // 每一层的节点数
        qt.push(root);
        while (!qt.empty())
        {
            curSize = qt.size(); // 后续qt的大小会变化，所以要先记录
            vector<int> curLevVec; // 当前层的节点值的数组
            for (int i = 0; i < curSize; i++)
            {
                curNode = qt.front();
                curLevVec.push_back(curNode->val);
                qt.pop();

                // 左右孩子入队列
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