#include <iostream>

using namespace std;

class MyLinkedList
{
public:
    // 定义链表节点
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    MyLinkedList()
    {
        dummyNode = new ListNode(0);
        size = 0;
    }

    int get(int index)
    {
        if (index >= size || index < 0)
            return -1; // 下标无效，返回-1

        ListNode *cur = dummyNode;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        newNode->next = dummyNode->next;
        dummyNode->next = newNode;
        size++;
    }

    void addAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);
        ListNode *cur = dummyNode->next;
        if (cur == nullptr)
            dummyNode->next = newNode;
        else
        {
            while (cur->next)
                cur = cur->next;
            cur->next = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val)
    {

        if (index == size)
            addAtTail(val); // index等于链表长度，直接加到末尾
        else if (index <= 0)
            addAtHead(val); // index为0，直接加到开头
        else if (index < size)
        {
            ListNode *cur = dummyNode->next;
            int i = 0;
            while (cur && i < index - 1)
            {
                cur = cur->next;
                i++;
            }
            ListNode *temp = new ListNode(val);
            temp->next = cur->next;
            cur->next = temp;
            size++;
        }
        else
            return;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        else
        {
            ListNode *cur = dummyNode;
            while (index--)
            {
                cur = cur->next;
            }
            ListNode *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            temp = nullptr;
            size--;
        }
    }

    void printList()
    {
        ListNode *cur = dummyNode->next;
        cout << "[ ";
        while (cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << "]" << endl;
    }

    int getSize()
    {
        return size;
    }

private:
    ListNode *dummyNode;
    int size;
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
int main()
{
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    int p1 = obj->get(1);
    obj->deleteAtIndex(0);
    int p2 = obj->get(0);
    obj->printList();
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "size: " << obj->getSize() << endl;

    return 0;
}