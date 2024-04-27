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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (!root)
            return res;
            
        queue<TreeNode *> qt;
        qt.push(root);
        while (!qt.empty())
        {
            int curLevelSize = qt.size();
            vector<int> curVec;
            for (int i = 0; i < curLevelSize; i++){
                if (qt.front()->left)
                    qt.push(qt.front()->left);
                if (qt.front()->right)
                    qt.push(qt.front()->right);

                curVec.push_back(qt.front()->val);
                qt.pop();
            }
            res.push_back(curVec);
        }

        return res;
    }
};

int main()
{
    cout << "test begins" << endl;

    return 0;
}