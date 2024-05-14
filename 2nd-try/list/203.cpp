#include <iostream>

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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return head;

        // ����ͷ���Ϊval�����
        while (head && head->val == val){
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }

        // �����ͷ���Ϊval�����
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur = dummyHead;
        while (cur && cur->next){
            if (cur->next->val == val){
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else {
                cur = cur->next;
            }
        }

        return dummyHead->next;
    }
};