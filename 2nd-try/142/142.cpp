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
        // ˼·������ָ�룬����ѭ�������ָ������������ָ��
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