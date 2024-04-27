#include <iostream>
#include <vector>
#include <queue>

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
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;

        if (!root)
            return res;

        queue<TreeNode *> qt;
        qt.push(root);
        while (!empty(qt))
        {
            int curLevelSize = qt.size();
            for (int i = 0; i < curLevelSize - 1; i++){
                if (qt.front()->left)
                    qt.push(qt.front()->left);
                if (qt.front()->right)
                    qt.push(qt.front()->right);
                qt.pop();
            }
            if (qt.front()->left)
                qt.push(qt.front()->left);
            if (qt.front()->right)
                qt.push(qt.front()->right);
            res.push_back(qt.front()->val);
            qt.pop();
        }
        return res;
    }
};
