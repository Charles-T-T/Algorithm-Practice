#include "../levelOrderTraversal/TreeNode.h"

using namespace std;

class Solution
{
public:
    // 递归法
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    // 统一迭代法-基于前序遍历
    TreeNode *invertTree_II(TreeNode *root)
    {
        if (!root)
            return root;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            if (cur)
            {
                if (cur->right)
                    st.push(cur->right); // 右
                if (cur->left)
                    st.push(cur->left); // 左
                st.push(cur);           // 中
                st.push(nullptr);       // 空节点标记
            }
            else
            {
                swap(st.top()->left, st.top()->right);
                st.pop();
            }
        }
        return root;
    }
};

int main()
{
    TreeNode *root = getRootFromStr("4,2,7,1,3,6,9");
    Solution obj;
    TreeNode *newRoot = obj.invertTree_II(root);
    showTree(newRoot);

    return 0;
}