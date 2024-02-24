#include <iostream>
#include <unordered_set>

using namespace std;

// ������ 02.07. �����ཻ
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
        // ˼·���Ƚ�������β�����룬��˫ָ������Ƚ�
        int lenA = 0, lenB = 0;
        ListNode *dummyHeadLong = new ListNode(0), *dummyHeadShort = new ListNode(0);
        
        // �ݴ�headA��headB
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

        // ��������β�˶���
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