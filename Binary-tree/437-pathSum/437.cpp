#include <cstdint>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// 暴力：DFS+递归
class Solution {
 public:
  int rootSum(TreeNode* root, int64_t targetSum) {
    if (!root) {
      return 0;
    }

    int pathCnt = 0;
    if (root->val == targetSum) {
      ++pathCnt;
    }
    pathCnt += rootSum(root->left, targetSum - root->val);
    pathCnt += rootSum(root->right, targetSum - root->val);
    return pathCnt;
  }

  int pathSum(TreeNode* root, int targetSum) {
    if (!root) {
      return 0;
    }
    int res = rootSum(root, targetSum);
    res += pathSum(root->left, targetSum);
    res += pathSum(root->right, targetSum);
    return res;
  }
};