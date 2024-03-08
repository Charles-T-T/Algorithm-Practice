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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 先将两个链表末端对齐
        int lengthA = 0, lengthB = 0;
        ListNode *curA = headA, *curB = headB;
        while (curA)
        {
            lengthA++;
            curA = curA->next;
        }
        while (curB)
        {
            lengthB++;
            curB = curB->next;
        }

        ListNode *longList = lengthA > lengthB ? headA : headB;
        ListNode *shortList = lengthA <= lengthB ? headA : headB;
        int dist = lengthA > lengthB ? (lengthA - lengthB) : (lengthB - lengthA);

        for (int i = 0; i < dist; i++)
            longList = longList->next;

        while (longList)
        {
            if (longList == shortList)
                return longList;
            longList = longList->next;
            shortList = shortList->next;
        }

        return nullptr;
    }
};