#include <iostream>
#include <vector>

using namespace std;

/*
����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������

ʾ�� 1��
���룺head = [1,2,3,4]
�����[2,1,4,3]

ʾ�� 2��
���룺head = []
�����[]

ʾ�� 3��
���룺head = [1]
�����[1]
*/
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *curNode = dummyNode;
        while (curNode->next && curNode->next->next)
        {
            // �ݴ���Ҫ�õ��Ľڵ�
            ListNode *temp1st = curNode->next;
            ListNode *temp3rd = curNode->next->next->next;

            // �����ڵ�
            curNode->next = curNode->next->next;
            curNode->next->next = temp1st;
            curNode->next->next->next = temp3rd;

            // �ƶ�curNode
            curNode = curNode->next->next;
        }

        return dummyNode->next;
    }
};