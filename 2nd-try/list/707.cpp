#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *n) : val(x), next(n) {}
};


class MyLinkedList
{
private:
    int size;
    ListNode *dummyHead;

public:
    MyLinkedList()
    {
        size = 0;
        dummyHead = new ListNode(0, nullptr);
    }

    int get(int index)
    {
        if (index >= size || index < 0)
            return -1;

        ListNode *cur = dummyHead;
        for (int i = 0; i <= index; i++){
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        ListNode *newHead = new ListNode(val, dummyHead->next);
        dummyHead->next = newHead;
        size++;
    }

    void addAtTail(int val)
    {
        ListNode *cur = dummyHead;
        for (int i = 0; i < size; i++)
            cur = cur->next;
        cur->next = new ListNode(val);
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0){
            addAtHead(val);
            return;
        }
        
        if (index == size)
        {
            addAtTail(val);
            return;
        }   

        if (index > size || index < 0)
            return;

        ListNode *cur = dummyHead;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        ListNode *newNode = new ListNode(val, cur->next);
        cur->next = newNode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;

        size--;
        ListNode *cur = dummyHead;
        for (int i = 0; i < index; i++){
            cur = cur->next;
        }
        ListNode *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
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

// [1 3 ]
// 2 3

int main(){
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(7);
    obj->addAtHead(2);
    obj->addAtHead(1);
    obj->addAtIndex(3, 0);
    obj->deleteAtIndex(2);
    obj->addAtHead(6);
    obj->addAtTail(4);
    cout << obj->get(4) << endl;
    obj->addAtHead(4);
    obj->addAtIndex(5, 0);
    obj->addAtHead(6);
    

    return 0;
}