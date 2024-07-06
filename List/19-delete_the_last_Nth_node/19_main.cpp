#include <iostream>
#include <vector>

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 思路：双指针，快指针先走 n + 1 步，然后快慢指针一起走
        // 快指针走到链表末尾空指针处时，慢指针恰好位于倒数第n个节点的前驱
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *fast = dummyHead, *slow = dummyHead;
        for (int i = 0; i < n + 1; i++)
            fast = fast->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};
