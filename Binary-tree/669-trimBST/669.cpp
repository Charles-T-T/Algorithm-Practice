#include "../TreeNode.h"

class Solution1
{
public:
    // 递归法
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        // 空节点直接返回
        if (!root)
            return nullptr;
        // 节点值不在目标区间
        if (root->val < low)
        {
            TreeNode *right = trimBST(root->right, low, high);
            return right;
        }
        if (root->val > high)
        {
            TreeNode *left = trimBST(root->left, low, high);
            return left;
        }
        // 节点值在目标区间
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

class Solution2
{
public:
    // 迭代法
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        // 先让root指针走到目标区间内的值
        while (root && (root->val < low || root->val > high))
        {
            if (root->val < low)
                root = root->right;
            if (root->val > high)
                root = root->left;
        }
        // 此时的root已经处于目标区间内了，处理其左子树
        TreeNode *cur = root;
        while (cur)
        {
            while (cur->left && cur->left->val < low) // 注意此处要用while判断
                cur->left = cur->left->right;
            cur = cur->left;
        }
        // 此时的root已经处于目标区间内了，处理其右子树
        cur = root;
        while (cur)
        {
            while (cur->right && cur->right->val > high) // 注意此处要用while判断
                cur->right = cur->right->left;
            cur = cur->right;
        }
        return root;
    }
};

int main()
{
    TreeNode *root = getRootFromStr("3,1,4,null,2");
    Solution2 obj;
    TreeNode *res = obj.trimBST(root, 3, 4);
    showTree(res);

    return 0;
}