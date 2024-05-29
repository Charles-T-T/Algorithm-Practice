#include <iostream>
#include <limits>

using namespace std;

/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
 
示例 1：
输入：root = [2,1,3]
输出：true

示例 2：
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int flag = 1;
    long long maxVal = numeric_limits<long long>::max();
    long long minVal = numeric_limits<long long>::min();
public:
    bool Test(TreeNode *root, int maxVal, int minVal){
        /**
         * 每个结点都应该有个上下界
         * 对于root的左孩子left，其上界就是root，下届和root的相同
         * 对于root的右孩子right，其上界和root的相同，下届就是root
        */
        if (!root)
            return true;
        
        if (root->val >= maxVal || root->val <= minVal)
            return false;

        return (Test(root->right, maxVal, root->val) && Test(root->left, root->val, minVal));
    }
    bool isValidBST(TreeNode* root) {
        // 思路：递归检查，遇到不符合的直接return false
        return Test(root, maxVal, minVal);
    }
};

int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6, new TreeNode(3), new TreeNode(7));

    Solution obj;
    if (obj.isValidBST(root))
        cout << "true" << endl;
    else    
        cout << "false" << endl;

    return 0;
}
