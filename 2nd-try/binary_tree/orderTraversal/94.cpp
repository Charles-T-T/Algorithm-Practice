#include <iostream>
#include <vector>
#include <stack>

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
    void Traverse(TreeNode *cur, vector<int> &res)
    {
        if (!cur) // 递归出口
            return;
        // 中序遍历，顺序：左 中 右
        Traverse(cur->left, res);  // 左
        res.push_back(cur->val);   // 中
        Traverse(cur->right, res); // 右
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        Traverse(root, res);
        return res;
    }

    // 迭代法
    vector<int> inorderTraversal_II(TreeNode *root)
    {
        if (!root)
            return res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur || !st.empty())
        {
            // 中序遍历特点：每次都要从当前节点的“最左”节点开始遍历
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                res.push_back(cur->val); // 左
                cur = cur->right;        // 右
            }
        }
        return res;
    }

    // 统一迭代法
    vector<int> inorderTraversal_III(TreeNode *root)
    {
        if (!root)
            return res;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop(); // 先从栈中弹出节点，便于后面统一按照“右中左”入栈
            if (cur)
            {
                if (cur->right)
                    st.push(cur->right); // 右
                st.push(cur);            // 中
                st.push(nullptr);        // 标记，表示当前节点入栈但尚未访问
                if (cur->left)
                    st.push(cur->left); // 左
            }
            else
            {
                // 遇到空指针标记
                res.push_back(st.top()->val); // 该访问的节点值计入结果集
                st.pop();                     // 弹出访问完毕的节点
            }
        }
        return res;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = nullptr;
    root->right = new TreeNode(2, new TreeNode(3), nullptr);

    Solution obj;
    vector<int> res = obj.inorderTraversal_III(root);
    for (int num : res) 
        cout << num << " ";

    return 0;
}