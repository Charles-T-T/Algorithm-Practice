#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  unordered_map<int, int> inorder_id;  // val -> index (in inorder)

  TreeNode* helpBuild(const vector<int>& preorder, const vector<int>& inorder,
                      int pre_left, int pre_right, int in_left, int in_right) {
    if (pre_left > pre_right) {
      return nullptr;
    }

    int root_v = preorder[pre_left];
    int root_id_inorder = inorder_id[root_v];
    TreeNode* root = new TreeNode(root_v);

    int left_subtree_size = root_id_inorder - in_left;
    root->left =
        helpBuild(preorder, inorder, pre_left + 1, pre_left + left_subtree_size,
                  in_left, root_id_inorder - 1);
    root->right = helpBuild(preorder, inorder, pre_left + left_subtree_size + 1,
                            pre_right, root_id_inorder + 1, in_right);
    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = inorder.size();
    for (int i = 0; i < n; ++i) {
      inorder_id[inorder[i]] = i;
    }
    return helpBuild(preorder, inorder, 0, n - 1, 0, n - 1);
  }
};