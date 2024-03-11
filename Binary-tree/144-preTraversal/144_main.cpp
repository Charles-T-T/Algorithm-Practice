#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

示例 1：
输入：root = [1,null,2,3]
输出：[1,2,3]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：
输入：root = [1,2]
输出：[1,2]

示例 5：
输入：root = [1,null,2]
输出：[1,2]
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    vector<int> resVec;

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // 递归法
        if (root == nullptr)
            return resVec;

        resVec.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return resVec;
    }

    vector<int> preorderTraversal_II(TreeNode *root)
    {
        /**
         * 迭代法
         * 思路：用栈模拟
         * 根据栈的特性，要得到“（中）左右”的前序遍历顺序
         * 则应该按照“（中）右左”的顺序入栈
        */
        if (root == nullptr)
            return resVec;

        stack<TreeNode*> nodeStack;
        TreeNode *curNode;
        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            curNode = nodeStack.top();
            nodeStack.pop();
            resVec.push_back(curNode->val);

            if (curNode->right)
                nodeStack.push(curNode->right);
            if (curNode->left)
                nodeStack.push(curNode->left);
        }

        return resVec;
    }

    vector<int> preorderTraversal_III(TreeNode *root)
    {
        /**
         * 统一迭代法
         * 要得到“中左右”
         * 则按照“右左中”入栈
         */
        if (root == nullptr)
            return resVec;

        stack<TreeNode *> nodeStack;
        TreeNode *curNode;
        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            curNode = nodeStack.top();
            if (curNode)
            {
                nodeStack.pop();

                if (curNode->right)
                    nodeStack.push(curNode->right);

                if (curNode->left)
                    nodeStack.push(curNode->left);

                nodeStack.push(curNode);
                nodeStack.push(nullptr);
            }
            else
            {
                nodeStack.pop();
                resVec.push_back(nodeStack.top()->val);
                nodeStack.pop();
            }
        }

        return resVec;
    }
};