#include <deque>
#include <type_traits>
#include <vector>
#include "../levelOrderTraversal/TreeNode.h"

class Solution
{
public:
    // 递归法
    bool compare(TreeNode *left, TreeNode *right)
    {
        // 首先排除左右有空节点的情况
        if (!left ^ !right)
            return false; // 一个为空、一个不为空，肯定不对称
        else if (!left && !right)
            return true; // 皆为空，对称
        // 然后处理左右都不为空的情况
        if (left->val != right->val)
            return false;
        bool outCmp = compare(left->left, right->right); // 比较外层情况
        bool inCmp = compare(left->right, right->left);  // 比较内层情况
        return outCmp && inCmp;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return false;
        return compare(root->left, root->right);
    }

    // 迭代法
    bool isSymmetric_II(TreeNode *root)
    {
        if (!root)
            return root;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();
            // 左右都为空：对称
            if (!left && !right)
                continue;
            // 左右之一为空，或左右不为空但值不相等：不对称
            if (!left ^ !right || left->val != right->val)
                return false;
            // 处理孩子节点
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};

class Solution_2 {
 public:
  bool isSymmetric(TreeNode *root) {
    if (!root) return false;

    // 利用层序遍历判断
    queue<TreeNode*> qu;
    qu.push(root->left);
    qu.push(root->right);
    while (!qu.empty()) {
      auto left = qu.front();
      qu.pop();
      auto right = qu.front();
      qu.pop();

      // 左右子树都为空：对称
      if (!left && !right) continue;

      // 左右子树一个为空、一个不为空：不对称
      if (static_cast<bool>(left) ^ static_cast<bool>(right)) return false;

      // 左右子树都不为空：看子节点值是否相等
      if (left->val != right->val) return false;

      // 接着处理左右子树（注意“轴对称”的顺序）
      qu.push(left->left);
      qu.push(right->right);
      qu.push(left->right);
      qu.push(right->left); 
    }   

    return true;
  }
};