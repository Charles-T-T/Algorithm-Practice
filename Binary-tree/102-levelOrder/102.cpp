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
         * 考虑使用两个队列，便于存放当前层和下一层
         * 交替使用这两个队列实现逐层遍历
        */
        if (!root)
            return resVec;

        queue<TreeNode *> qt1, qt2;
        TreeNode *curNode;

        qt1.push(root);
        // 非空队列存当前层节点，另一个队列准备存下一层节点
        while (!qt1.empty() || !qt2.empty())
        {
            if (!qt1.empty())
            {
                vector<int> curLevVec; // 存储当前层的节点值
                while (!qt1.empty())
                {
                    curNode = qt1.front();
                    curLevVec.push_back(curNode->val);
                    qt1.pop();

                    // 将下一层节点存到qt2
                    if (curNode->left)
                        qt2.push(curNode->left);
                    if (curNode->right)
                        qt2.push(curNode->right);
                }
                resVec.push_back(curLevVec);
            }
            else
            {
                vector<int> curLevVec; // 存储当前层的节点值
                while (!qt2.empty())
                {
                    curNode = qt2.front();
                    curLevVec.push_back(curNode->val);
                    qt2.pop();

                    // 将下一层节点存到qt1
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