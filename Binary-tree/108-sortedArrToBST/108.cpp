#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 
平衡二叉搜索树。

示例 1：
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：

示例 2：
输入：nums = [1,3]
输出：[3,1]
解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
*/

class Solution {
public:
    /**
     * 思路：由于nums是升序的
     * 故可以每次选中间点作为根节点、左右相邻数字为左右子树
     * 递归地实现BST的建立
     */
    TreeNode* helper(const vector<int>& nums, int left, int right){
        if (left > right) 
            return nullptr;
        
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

int main(){
    vector<int> nums = {-10,-3,0,5,9};
    Solution obj;
    TreeNode *res = obj.sortedArrayToBST(nums);

    return 0;
}