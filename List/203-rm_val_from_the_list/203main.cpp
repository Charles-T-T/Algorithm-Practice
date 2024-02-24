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

#include <iostream>
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *curNode = dummyHead;
        while (curNode->next)
        {
            if (curNode->next->val == val)
            {
                ListNode *temp = curNode->next;
                curNode->next = curNode->next->next;
                delete temp;
            }
            else
                curNode = curNode->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main()
{
    cout << "please input the head, divided by space and ended with -1: " << endl;
    ListNode *head = new ListNode();
    ListNode *p = head;
    int val;

    int i = 0;
    while (cin >> val)
    {
        if (val == -1)
            break;
        p->next = new ListNode(val);
        p = p->next;
    }
    cout << "please input the value to be removed: ";
    int valRM;
    cin >> valRM;
    Solution solution;
    ListNode *newHead = solution.removeElements(head->next, valRM);
    ListNode *newP = newHead;
    cout << "[";
    while (newP)
    {
        cout << newP->val << " ";
        newP = newP->next;
    }
    cout << "]" << endl;

    return 0;
}