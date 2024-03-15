#include <iostream>
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
给你一个二叉树的根节点 root ， 检查它是否轴对称。
示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false
*/

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        // 思路：让左右子树分别按“从左到右”和“从右到左”的顺序层序遍历，并作比较
        if (!root)
            return false;
        if (!root->left && !root->right)
            return true;
        if (!root->left || !root->right)
            return false;

        queue<TreeNode *> ql, qr; // 左、右子树节点队列
        ql.push(root->left), qr.push(root->right);
        TreeNode *curLeft, *curRight;
        int curSize;
        int llFlag, lrFlag, rlFlag, rrFlag; // 标记左、右子树的左、右子树的存在情况
        while (!ql.empty() || !qr.empty())
        {
            if (ql.size() != qr.size()) // 左右子树节点数都不一样，则肯定不是轴对称的
                return false;

            curSize = ql.size();
            for (int i = 0; i < curSize; i++)
            {
                curLeft = ql.front(), curRight = qr.front();
                if (curLeft->val != curRight->val)
                    return false;

                if (curLeft->left)
                    llFlag = 1;
                else
                    llFlag = 0;

                if (curLeft->right)
                    lrFlag = 1;
                else
                    lrFlag = 0;

                if (curRight->left)
                    rlFlag = 1;
                else
                    rlFlag = 0;
                
                if (curRight->right)
                    rrFlag = 1;
                else
                    rrFlag = 0;

                if ((llFlag ^ rrFlag) || (lrFlag ^ rlFlag))
                    return false;

                ql.pop(), qr.pop();
                if (curLeft->left)
                    ql.push(curLeft->left);
                if (curLeft->right)
                    ql.push(curLeft->right);

                if (curRight->right)
                    qr.push(curRight->right);
                if (curRight->left)
                    qr.push(curRight->left);
            }
        }

        return true;
    }
};