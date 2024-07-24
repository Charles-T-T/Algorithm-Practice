#include "../TreeNode.h"

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *d = root; // 待删除节点d
        TreeNode *pre = new TreeNode(INT_MAX, d, nullptr);
        TreeNode *dummyRoot = pre; // 虚拟根节点
        while (d)
        {
            if (d->val == key)
                break;
            pre = d;
            if (key < d->val)
                d = d->left;
            else
                d = d->right;
        }
        if (!d) // 没找到要删除的节点
            return root;
        else
        {
            // 待删除节点是叶子节点的情况
            if (!d->left && !d->right)
            {
                if (d->val < pre->val) // 待删除节点是其父节点的左孩子
                    pre->left = nullptr;
                else // 待删除节点是其父节点的右孩子
                    pre->right = nullptr;
            }
            // 待删除节点只有单侧子树的情况
            else if (d->left && !d->right)
            {
                if (d->val < pre->val)
                    pre->left = d->left;
                else
                    pre->right = d->left;
            }
            else if (!d->left && d->right)
            {
                if (d->val < pre->val)
                    pre->left = d->right;
                else
                    pre->right = d->right;
            }
            // 待删除节点左右孩子都不为空
            else
            {
                // 找到待删除节点右孩子的最左下节点（右子树中的最小节点）
                TreeNode *mostLeft = d->right;
                // 特殊情况：待删除节点的右孩子无左孩子（自身就是最小节点）
                if (!mostLeft->left)
                {
                    if (!mostLeft->right)
                        d->right = nullptr;
                    else
                        d->right = mostLeft->right;
                }
                else
                {
                    TreeNode *preMostLeft = d; // 最左节点的父节点
                    while (mostLeft->left)
                    {
                        preMostLeft = mostLeft;
                        mostLeft = mostLeft->left;
                    }
                    // 将最左节点从原来的位置移除
                    if (mostLeft->right)
                        preMostLeft->left = mostLeft->right;
                    else
                        preMostLeft->left = nullptr;
                }
                // 将待删除节点替换为该最左节点
                mostLeft->left = d->left;
                mostLeft->right = d->right;
                if (d->val < pre->val)
                    pre->left = mostLeft;
                else
                    pre->right = mostLeft;
            }
            delete d; // 释放删除节点的空间
        }
        return dummyRoot->left;
    }
};

int main()
{
    TreeNode *root = getRootFromStr("37,20,49,3,25,41,null,2,12,21,26,38,46,0,null,7,19,null,24,null,35,null,40,43,48,null,1,4,9,17,null,23,null,34,36,39,null,42,44,47,null,null,null,null,6,8,10,14,18,22,null,31,null,null,null,null,null,null,null,null,45,null,null,5,null,null,null,null,11,13,16,null,null,null,null,27,33,null,null,null,null,null,null,null,null,15,null,null,29,32,null,null,null,28,30");
    Solution obj;
    TreeNode *res = obj.deleteNode(root, 10);
    showTree(res);

    return 0;
}