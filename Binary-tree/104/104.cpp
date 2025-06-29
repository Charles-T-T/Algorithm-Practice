#include "../levelOrderTraversal/TreeNode.h"

class Solution
{
public:
    // 递归法
    int maxDepth(TreeNode *root)
    {
        if (!root) 
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    // 迭代法
    int maxDepth_II(TreeNode *root) {
        // 层序遍历，返回层数即可
        return levelOrder(root).size();
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (!root)
            return res;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size(); // 注意！先记录当前队长，因为之后会变
            vector<int> level;   // 当前这一层的节点值
            for (int i = 0; i < size; ++i)
            {
                level.push_back(q.front()->val);
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            res.push_back(level);
        }
        return res;
    }
};

class Solution_2 {
 public:
  // 递归：最大深度=左右子树的最大深度+1
  int maxDepth(TreeNode *root) {
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }

  // 迭代：利用层序遍历
  int maxDepthIter(TreeNode *root) {
    queue<TreeNode*> qu;
    int level = 0;
    
    if (root) qu.push(root);
    while (!qu.empty()) {
      vector<TreeNode*> cur_lev;
      while (!qu.empty()) {
        cur_lev.push_back(qu.front());
        qu.pop();
      }
      for (const auto& node : cur_lev) {
        if (node->left) qu.push(node->left);
        if (node->right) qu.push(node->right);
      }
      ++level;
    }

    return level;
  }
};
