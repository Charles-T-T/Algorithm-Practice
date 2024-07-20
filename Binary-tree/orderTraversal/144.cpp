#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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
    vector<int> res;

public:
    // 递归法
    void Traverse(TreeNode *cur, vector<int> &res)
    {
        if (!cur) // 递归出口
            return;
        // 前序遍历，顺序：中 左 右
        res.push_back(cur->val);   // 中
        Traverse(cur->left, res);  // 左
        Traverse(cur->right, res); // 右
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        Traverse(root, res);
        return res;
    }

    // 迭代法
    vector<int> preorderTraversal_II(TreeNode *root)
    {
        stack<TreeNode *> st;
        if (!root)
            return res;
        st.push(root);
        while (!st.empty())
        {
            // 要让出栈顺序为“中左右”，则入栈顺序应为“右左中”
            TreeNode *mid = st.top();
            st.pop();
            res.push_back(mid->val);
            if (mid->right)
                st.push(mid->right); // 右
            if (mid->left)
                st.push(mid->left); // 左
        }
        return res;
    }

    // 统一迭代法
    vector<int> preorderTraversal_III(TreeNode *root)
    {
        if (!root)
            return res;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop(); // 先从栈中弹出节点，便于后面统一按照“右左中”的顺序入栈
            if (cur)
            {
                if (cur->right)
                    st.push(cur->right); // 右
                if (cur->left)
                    st.push(cur->left); // 左
                st.push(cur);           // 中
                st.push(nullptr);       // 标记，表示当前节点入栈但尚未被访问
            }
            else
            {
                res.push_back(st.top()->val);
                st.pop();
            }
        }
        return res;
    }
};