#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

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
    vector<int> resVec;

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return resVec;

        stack<TreeNode *> nodeStack;
        TreeNode *curNode = root;

        while (curNode || !nodeStack.empty())
        {
            if (curNode){
                nodeStack.push(curNode);
                curNode = curNode->left;
            }
            else{
                curNode = nodeStack.top();
                nodeStack.pop();
                resVec.push_back(curNode->val);
                curNode = curNode->right;
            }
        }

        return resVec;
    }
};
