#include <iostream>
#include <vector>

using namespace std;

/*
����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣

ʾ�� 1��
���룺head = [1,2,3,4,5], n = 2
�����[1,2,3,5]

ʾ�� 2��
���룺head = [1], n = 1
�����[]

ʾ�� 3��
���룺head = [1,2], n = 1
�����[1]
*/

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
        // ˼·��������ָ�룬���n����㣬��һ�������ǰ�桰̽·��
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *ahead = dummyNode;
        ListNode *later = dummyNode;

        for (int i = 0; i < n; i++)
        {
            ahead = ahead->next;
        }

        while (ahead->next)
        {
            ahead = ahead->next;
            later = later->next;
        }

        later->next = later->next->next;
        return dummyNode->next;
    }
};
