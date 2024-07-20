#include <iostream>
#include <vector>
#include <stack>
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

class Solution
{
private:
    vector<int> res;

public:
    // 递归法
    void Traverse(TreeNode *cur, vector<int> &res) {
        if (!cur) // 递归出口
            return;
        // 后序遍历，顺序：左 右 中
        Traverse(cur->left, res); // 左
        Traverse(cur->right, res); // 右
        res.push_back(cur->val); // 中
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        Traverse(root, res);
        return res;
    }

    // 迭代法
    vector<int> postorderTraversal_II(TreeNode *root) {
        if (!root)
            return res;
        stack<TreeNode*> st;
        st.push(root);
        // 最终目标是“左右中”，那么先按“中右左”遍历，最后反转结果即可
        while (!st.empty()) {
            // 现在要得到“中右左”的出栈顺序，则按“左右中”入栈
            TreeNode *mid = st.top();
            st.pop();
            res.push_back(mid->val);
            if (mid->left) st.push(mid->left); // 左
            if (mid->right) st.push(mid->right); // 右
        }
        reverse(res.begin(), res.end()); // 反转结果
        return res;
    }

    // 统一迭代法
    vector<int> postorderTraversal_III(TreeNode *root) {
        if (!root)
            return res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop(); // 先从栈中弹出节点，便于后面统一按照“中右左”顺序入栈
            if (cur) {
                st.push(cur); // 中
                st.push(nullptr); // 标记，表示当前节点入栈但尚未被访问
                if (cur->right)
                    st.push(cur->right);
                if (cur->left)
                    st.push(cur->left);
            } else {
                // 遇到空指针标记
                res.push_back(st.top()->val);
                st.pop();
            }
        }
        return res;
    }
};