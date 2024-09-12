#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node*, Node*> nodeMap; // {原节点：新节点}
        Node *dummyHead = new Node(0);
        Node *cur = dummyHead;
        Node *old = head;

        // 复制原普通链表
        while (old) {
            cur->next = new Node(old->val);
            cur = cur->next;
            nodeMap[old] = cur;
            old = old->next;
        }

        // 复制原随机链表
        cur = dummyHead->next;
        old = head;
        while (cur) {
            cur->random = nodeMap[old->random];
            cur = cur->next;
            old = old->next;
        }

        return dummyHead->next;
    }

    Node *copyRandomListII(Node *head) // 迭代+节点拆分
    {
        if (head == nullptr)
            return nullptr;
        
        // 将复制节点插入到原节点后
        Node *old = head;
        while (old) {
            Node *copyNode = new Node(old->val);
            copyNode->next = old->next;
            old->next = copyNode;
            old = copyNode->next;
        }

        // 连接random节点
        Node *cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        // 取出新节点
        Node *newHead = head->next;
        old = head;
        while (old) {
            Node *newNode = old->next;
            old->next = old->next->next; // 记得恢复原链
            old = old->next;
            if (newNode->next)
                newNode->next = newNode->next->next;
        }
        
        return newHead;
    }
};

int main() {

}