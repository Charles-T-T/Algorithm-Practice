#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 思路：整俩指针，若有循环，则快指针总能遇到慢指针
        if (!head)
            return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        while (1)
        {
            if (!fast->next || !fast->next->next)
                return nullptr;

            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        ListNode *res = head;
        while (res != slow)
        {
            res = res->next;
            slow = slow->next;
        }
        return res;
    }
};