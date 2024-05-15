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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *dummyHead = new ListNode();
        while (head){
            ListNode *newHead = new ListNode(head->val, dummyHead->next);
            dummyHead->next = newHead;
            head = head->next;
        }
        return dummyHead->next;
    }
};