#include <cstdint>
#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// 技巧：回溯+前缀和
class Solution {
 public:
  unordered_map<int64_t, int> prefix_cnt;  // prefix sum -> its count
  int target_sum;
  int64_t cur_prefix = 0;
  int path_cnt = 0;

  void backtracking(TreeNode* node) {
    if (!node) {
      return;
    }

    cur_prefix += node->val;
    // curPrefix - certain earlier prefix = targetSum
    // => certain earlier prefix = curPrefix - targetSum
    int64_t need = cur_prefix - target_sum;
    if (prefix_cnt.count(need)) {
      path_cnt += prefix_cnt[need];
    }

    // backtracking
    ++prefix_cnt[cur_prefix];
    backtracking(node->left);
    backtracking(node->right);
    --prefix_cnt[cur_prefix];
    cur_prefix -= node->val;
  }

  int pathSum(TreeNode* root, int targetSum) {
    prefix_cnt[0] = 1;  // for empty path
    target_sum = targetSum;
    backtracking(root);
    return path_cnt;
  }
};