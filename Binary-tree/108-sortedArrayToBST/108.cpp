#include "../TreeNode.h"

class Solution
{
public:
    // 递归法
    TreeNode *getRoot(const auto &nums, int left, int right) {
        // 递归出口：左右指针错开
        if (left > right)
            return nullptr;
        // 当前数组切片的中位数作为根节点
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = getRoot(nums, left, mid - 1);
        root->right = getRoot(nums, mid + 1, right);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return getRoot(nums, 0, nums.size() - 1);
    }
};
