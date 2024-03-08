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
        // 思路：遍历，在新链表采用头插法得到反转后的链表
        ListNode *dummyNode = new ListNode();
        while (head)
        {
            ListNode *newNode = new ListNode(head->val);
            newNode->next = dummyNode->next;
            dummyNode->next = newNode;
            head = head->next;
        }
        return dummyNode->next;
    }
};