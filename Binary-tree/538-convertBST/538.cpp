#include "../TreeNode.h"

class Solution1
{
public:
    TreeNode *convertBST(TreeNode *root)
    {
        if (!root)
            return nullptr;
        // 用一个优先队列，按原节点值从大到小存储所有节点
        auto cmp = [](TreeNode *a, TreeNode *b)
        {
            return a->val < b->val;
        };
        priority_queue<TreeNode *, vector<TreeNode *>, decltype(cmp)> pq(cmp);
        // 层序遍历
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                pq.push(cur);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        // 按原节点值从大到小更新节点值
        int biggerSum = 0; // 大于等于当前节点值的所有节点值之和
        while (!pq.empty())
        {
            biggerSum += pq.top()->val;
            pq.top()->val = biggerSum;
            pq.pop();
        }
        return root;
    }
};

class Solution2 // 利用BST的性质，递归
{
public:
    int biggerSum = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        // 逆中序遍历——右中左
        if (!root)
            return nullptr;

        root->right = convertBST(root->right); // 右
        biggerSum += root->val;                // 更新节点值之和
        root->val = biggerSum;                 // 中
        root->left = convertBST(root->left);   // 左

        return root;
    }
};

class Solution3 // 利用BST的性质，迭代
{
public:
    TreeNode *convertBST(TreeNode *root)
    {
        // 基于统一迭代法
        if (!root)
            return nullptr;
        int biggerSum = 0;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();
            if (cur)
            {
                // 要得到“右中左”的逆中序遍历结果，则应按照“左中右”入栈
                if (cur->left)
                    st.push(cur->left); // 左
                st.push(cur);           // 中
                st.push(nullptr);       // 空节点标记
                if (cur->right)
                    st.push(cur->right); // 右
            }
            else
            {
                biggerSum += st.top()->val;
                st.top()->val = biggerSum; // 更新节点值
                st.pop();
            }
        }
        return root;
    }
};

int main()
{
    TreeNode *root = getRootFromStr("4,1,6,0,2,5,7,null,null,null,3,null,null,null,8");
    Solution1 obj;
    TreeNode *res = obj.convertBST(root);
    showTree(res);
    return 0;
}