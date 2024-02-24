#include <iostream>
#include <unordered_set>

using namespace std;

// 面试题 02.07. 链表相交
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
        // 思路：先将两链表尾部对齐，在双指针逐个比较
        int lenA = 0, lenB = 0;
        ListNode *dummyHeadLong = new ListNode(0), *dummyHeadShort = new ListNode(0);
        
        // 暂存headA和headB
        ListNode *tempA = headA, *tempB = headB;
        while (headA)
        {
            headA = headA->next;
            lenA++;
        }
        while (headB)
        {
            headB = headB->next;
            lenB++;
        }

        int lenDist = lenA > lenB ? lenA - lenB : lenB - lenA;
        if (lenA > lenB)
        {
            dummyHeadLong->next = tempA;
            dummyHeadShort->next = tempB;
        }
        else
        {
            dummyHeadLong->next = tempB;
            dummyHeadShort->next = tempA;
        }

        // 让两链表尾端对齐
        for (int i = 0; i < lenDist; i++)
            dummyHeadLong = dummyHeadLong->next;
        
        while (dummyHeadLong->next && dummyHeadShort->next)
        {
            dummyHeadLong = dummyHeadLong->next;
            dummyHeadShort = dummyHeadShort->next;
            if (dummyHeadLong == dummyHeadShort)
                return dummyHeadLong;
        }

        return nullptr;
    }
};