#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *initList()
    {
        ListNode *dummyNode = new ListNode();
        return dummyNode;
    }

    ListNode *reverseList1(ListNode *head)
    {
        // ˼·1������ԭ������ͷ�巨�γɷ�ת���������
        ListNode *dummyNode = new ListNode();
        while (head)
        {
            ListNode *temp = new ListNode(head->val);
            temp->next = dummyNode->next;
            dummyNode->next = temp;
            head = head->next;
        }
        return dummyNode->next;
    }

    ListNode *reverseList2(ListNode *head)
    {
        // ˼·2��˫ָ�뷨�����ΰ�ָ�롰�۹�ȥ��
        ListNode *temp = new ListNode();
        ListNode *pre;
        pre = nullptr;
        ListNode *cur = head;

        while (cur)
        {
            temp = cur->next; // �ȴ�cur����һ���ڵ����֮��ʹ��
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main()
{
    Solution obj;
    Solution::ListNode *dummyNode = obj.initList();
    Solution::ListNode *cur = dummyNode;
    int val;
    cout << "please input the list, divided by space and ended by -1: ";
    while (cin >> val)
    {
        if (val == -1)
            break;
        cur->next = new Solution::ListNode(val);
        cur = cur->next;
    }
    Solution::ListNode *head = dummyNode->next;
    Solution::ListNode *reverseHead = obj.reverseList2(head);
    cur = reverseHead;
    cout << "after reversing: [ ";
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "]";

    return 0;
}