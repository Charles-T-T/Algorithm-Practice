#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    void show(){
        cout << "[ ";
        ListNode *cur = this;
        while (cur){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << "]";
    }
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 思路：先尝试暴力，求总长再删掉倒数第n个
        if (!head->next){
            head = nullptr;
            return head;
        }

        int len = 1;
        ListNode* testNode = head;
        while (testNode->next)
        {
            testNode = testNode->next;
            len++;
        }
        int target = len - n;
        ListNode *dummyNode = new ListNode(0, head);
        ListNode *del = dummyNode;
        for (int i = 0; i < target; i++)
            del = del->next;
        del->next = del->next->next;

        return dummyNode->next;
    }
};

int main(){
    ListNode *dummyHead = new ListNode(0);
    ListNode *cur = dummyHead;
    int len;
    cout << "input len of nums: ";
    cin >> len;

    cout << "input nums: ";
    for (int i = 0; i < len; i++){
        int num;
        cin >> num;
        cur->next = new ListNode(num);
        cur = cur->next;
    }

    Solution obj;
    int loc;
    cout << "input loc: ";
    cin >> loc;
    ListNode *res = obj.removeNthFromEnd(dummyHead->next, loc);
    res->show();

    

    return 0;
}

// [1 2 3 4 5]