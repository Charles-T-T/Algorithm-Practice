#include <vector>
#include "TreeNode.h"

class Solution
{
public:
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode*> qu;
    if (root) qu.push(root);
    
    while (!qu.empty()) {
      vector<TreeNode*> cur_lev_node;
      vector<int> cur_lev_val;
      while (!qu.empty()) {
        cur_lev_node.emplace_back(qu.front());
        qu.pop();
      }
      for (const auto& node : cur_lev_node) {
        cur_lev_val.emplace_back(node->val);
        if (node->left) qu.push(node->left);
        if (node->right) qu.push(node->right);
      }
      res.emplace_back(cur_lev_val);
    }

    return res;
  }
};