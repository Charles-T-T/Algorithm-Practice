#include "../TreeNode.h"

class Solution
{
public:
    // nums中的数字各不相同，故用一个哈希表将其下标先存起来便于使用
    unordered_map<int, int> indexMap;
    void getMap(const vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
            indexMap[nums[i]] = i;
    }

    // 递归法
    TreeNode *getRoot(vector<int> &nums, int left, int right)
    {
        // 递归出口：子数组收缩到没有数字（空节点）
        if (left > right)
            return nullptr;
        int maxNum = INT_MIN; // 当前子数组中的最大值
        for (int i = left; i <= right; ++i)
            maxNum = max(maxNum, nums[i]);
        int mid = indexMap[maxNum]; // 当前子数组中最大值的下标
        TreeNode *root = new TreeNode(maxNum);
        // 递归构建左右子树
        root->left = getRoot(nums, left, mid - 1);
        root->right = getRoot(nums, mid + 1, right);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        getMap(nums);
        return getRoot(nums, 0, nums.size() - 1);
    }
};

int main()
{
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    Solution obj;
    TreeNode *root = obj.constructMaximumBinaryTree(nums);
    showTree(root);

    return 0;
}