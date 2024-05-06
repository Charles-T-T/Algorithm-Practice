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
����һ�� n �����ĸ��ڵ�  root ������ ��ڵ�ֵ�� ǰ����� ��

n ���� �������а���������������л���ʾ��ÿ���ӽڵ��ɿ�ֵ null �ָ�����μ�ʾ������

ʾ�� 1��
���룺root = [1,null,3,2,4,null,5,6]
�����[1,3,5,6,2,4]

ʾ�� 2��
���룺root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
�����[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
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
        // �ݹ�ʵ��
        if (!root)
            return _res;

        _res.push_back(root->val);
        traversal(root);

        return _res;
    }
};