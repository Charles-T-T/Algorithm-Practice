#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // 思路：双指针
        if (!head || !head->next)
            return head;

        ListNode *dummyHead = new ListNode(0, head);
        ListNode *former = head->next, *later = head;
        swap(former->val, later->val);
        while (former->next && former->next->next) {
            former = former->next->next;
            later = later->next->next;
            swap(former->val, later->val);
        }
        return dummyHead->next;
    }
};