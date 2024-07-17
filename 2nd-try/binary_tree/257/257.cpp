#include "../TreeNode.h"

/*
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。

示例 1：
输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]

示例 2：
输入：root = [1]
输出：["1"]
*/

class Solution
{
public:
    // DFS（递归）
    void getPathDFS(TreeNode *root, string path, vector<string> &res)
    {
        if (root)
        {
            path += to_string(root->val);
            // 递归出口：遍历到叶子节点
            if (!root->left && !root->right)
                res.push_back(path);
            else
            {
                path += "->";
                getPathDFS(root->left, path, res);
                getPathDFS(root->right, path, res);
            }
        }
    }

    vector<string> binaryTreePaths_DFS(TreeNode *root)
    {
        vector<string> res;
        getPathDFS(root, "", res);
        return res;
    }

    // 回溯法（递归）
    void traversal(TreeNode *root, vector<int> &paths, vector<string> &res)
    {
        // 由于需要找到所有路径，采用前序遍历实现
        paths.push_back(root->val); // 中
        // 递归出口：遍历到叶子节点
        if (!root->left && !root->right)
        {
            string path = to_string(paths[0]);
            for (int i = 1; i < paths.size(); ++i)
                path += "->" + to_string(paths[i]);
            res.push_back(path);
            return;
        }
        if (root->left)
        {
            traversal(root->left, paths, res); // 左
            paths.pop_back();                  // 回溯
        }
        if (root->right)
        {
            traversal(root->right, paths, res); // 右
            paths.pop_back();                   // 回溯
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res; // 最终的结果集
        vector<int> paths;  // 存储每条路径的数组（按照路径上节点的值）
        if (!root)
            return res;
        traversal(root, paths, res);
        return res;
    }

    // 迭代法
    vector<string> binaryTreePaths_II(TreeNode *root)
    {
        // 基于前序遍历的统一迭代法实现
        vector<string> res;
        stack<string> pathSt;
        stack<TreeNode *> nodeSt;
        if (!root)
            return res;
        nodeSt.push(root);
        pathSt.push(to_string(root->val));
        while (!nodeSt.empty())
        {
            TreeNode *node = nodeSt.top();
            nodeSt.pop();
            string path = pathSt.top();
            pathSt.pop();
            if (node)
            {
                if (node->right)
                {
                    pathSt.push(path + "->" + to_string(node->right->val));
                    nodeSt.push(node->right); // 右
                }
                if (node->left)
                {
                    pathSt.push(path + "->" + to_string(node->left->val));
                    nodeSt.push(node->left); // 左
                }
                nodeSt.push(node);    // 中
                nodeSt.push(nullptr); // 空节点标记
                pathSt.push(path);    // 记录当前路径
            }
            else
            {
                if (!nodeSt.top()->left && !nodeSt.top()->right)
                    res.push_back(path); // 已到叶子节点：当前路径加入结果集
                nodeSt.pop();
            }
        }
        return res;
    }
};

int main()
{
    TreeNode *root = getRoot("1,2,3,null,5");
    Solution obj;
    vector<string> res = obj.binaryTreePaths_II(root);
    for (auto str : res)
        cout << str << endl;

    return 0;
}