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
    vector<int> inorderTraversal(TreeNode *root)
    {
        // 递归法
        if (root == nullptr)
            return resVec;

        inorderTraversal(root->left);
        resVec.push_back(root->val);
        inorderTraversal(root->right);

        return resVec;
    }

    vector<int> inorderTraversal_II(TreeNode *root)
    {
        /**
         * 采用迭代法
         * 用栈实现
        */
        if (root == nullptr)
            return resVec;

        stack<TreeNode *> nodeStack;
        TreeNode *curNode = root;

        while (curNode || !nodeStack.empty())
        {
            if (curNode) // 找到当前节点的最左子节点
            {
                nodeStack.push(curNode);
                curNode = curNode->left;
            }
            else
            {
                curNode = nodeStack.top();
                nodeStack.pop();
                resVec.push_back(curNode->val); // 根节点
                curNode = curNode->right; // 右孩子
            }
        }

        return resVec;
    }

    vector<int> inorderTraversal_III(TreeNode *root)
    {
        /**
         * 采用统一的迭代法
         * 仍用栈实现，但是用nullptr作为标记
         * 记录访问了但是尚未加入答案的节点
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
                /**
                 * 中序遍历顺序为“左中右”
                 * 所以入栈顺序应为“右中左”
                */
                nodeStack.pop();
                if (curNode->right) // 右节点（有的话）入栈
                    nodeStack.push(curNode->right);

                nodeStack.push(curNode);
                nodeStack.push(nullptr); // 中节点入栈，并用nullptr标记
                if (curNode->left)       // 左节点（有的话）入栈
                    nodeStack.push(curNode->left); 
            }
            else
            {
                // 遇到空节点，说明可以将上一个节点加入答案了
                nodeStack.pop(); // 弹出空节点
                resVec.push_back(nodeStack.top()->val);
                nodeStack.pop(); // 弹出加入答案了的节点
            }
        }

        return resVec;
    }
};