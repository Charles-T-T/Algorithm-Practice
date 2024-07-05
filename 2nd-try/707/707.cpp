#include <iostream>

using namespace std;

class MyLinkedList
{
private:
    // 链表节点
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    int len;             // 当前链表长度
    ListNode *dummyHead; // 链表虚头节点

public:
    MyLinkedList()
    {
        dummyHead = new ListNode();
        len = 0;
    }

    int get(int index)
    {
        if (index >= len || index < 0)
            return -1;

        ListNode *cur = dummyHead;
        for (int i = 0; i <= index; i++)
            cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val)
    {
        ListNode *newHead = new ListNode(val, dummyHead->next);
        dummyHead->next = newHead;
        len++;
    }

    void addAtTail(int val)
    {
        addAtIndex(len, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > len)
            return;

        ListNode *cur = dummyHead;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        ListNode *newNode = new ListNode(val, cur->next);
        cur->next = newNode;
        len++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= len)
            return;

        ListNode *cur = dummyHead;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        cur->next = cur->next->next;
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    MyLinkedList *ls = new MyLinkedList();
    ls->addAtHead(2);
    ls->deleteAtIndex(1);
    ls->addAtHead(2);
    ls->addAtHead(7);
    ls->addAtHead(3);
    ls->addAtHead(2);
    ls->addAtHead(5);
    ls->addAtTail(5);
    ls->get(5);
    ls->deleteAtIndex(6);
    ls->deleteAtIndex(4);

    return 0;
    
}