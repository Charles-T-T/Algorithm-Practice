#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

/*
给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。

n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。

示例 1：
输入：root = [1,null,3,2,4,null,5,6]
输出：[1,3,5,6,2,4]

示例 2：
输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
*/

class Solution
{
private:
    vector<int> _res;

public:
    void traversal(Node *curNode){
        if (!curNode)
            return;

        for (Node *childNode : curNode->children){
            if (!childNode)
                return;
            _res.push_back(childNode->val);
            traversal(childNode);
        }
    }
    
    vector<int> preorder(Node *root)
    {
        // 递归实现
        if (!root)
            return _res;

        _res.push_back(root->val);
        traversal(root);

        return _res;
    }
};