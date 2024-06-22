#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

示例 1：
输入：root = [3,1,4,null,2], k = 1
输出：1

示例 2：
输入：root = [5,3,6,2,4,null,null,1], k = 3
输出：3
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    priority_queue<int, vector<int>, greater<>> pq;
    int smallest;

public:
    void midTraverse(TreeNode *root)
    {
        if (!root)
            return;
        midTraverse(root->left);
        pq.push(root->val);
        midTraverse(root->right);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        // 思路-暴力版本：
        // 遍历，维护优先队列
        midTraverse(root);
        for (int i = 0; i < k; i++) {
            smallest = pq.top();
            pq.pop();
        }

        return smallest;
    }
};