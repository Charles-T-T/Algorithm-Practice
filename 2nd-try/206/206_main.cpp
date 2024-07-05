#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // 思路：开一个新链表，采用头插法依次插入原来链表的节点
        ListNode *dummyHead = new ListNode();
        while (head) {
            dummyHead->next = new ListNode(head->val, dummyHead->next);
            head = head->next;
        }
        return dummyHead->next;
    }
};