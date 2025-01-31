#include <iostream>
#include <algorithm>
#include <vector>

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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 暴力解法
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> elements;
        while (head)
        {
            elements.push_back(head->val);
            head = head->next;
        }
        sort(elements.begin(), elements.end());
        ListNode *dummyHead = new ListNode();
        ListNode *cur = dummyHead;
        for (int element : elements) {
            cur->next = new ListNode(element);
            cur = cur->next;
        }
        return dummyHead->next;
    }
};


/// @brief 归并排序(自顶向下)
class Solution2 {
public:
    ListNode* merge(ListNode* L, ListNode* R) {
        ListNode dummyHead;
        ListNode *cur = &dummyHead;
        while (L && R)
        {
            if (L->val < R->val) {
                cur->next = L;
                L = L->next;
            } else {
                cur->next = R;
                R = R->next;
            }
            cur = cur->next;   
        }
        if (L) cur->next = L;
        else if (R) cur->next = R;
        return dummyHead.next;
    }

    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (!head || head == tail) return head;

        // 用快慢指针法获取链表中点节点
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        } // 完成后慢指针slow指向链表中点

        ListNode *mid = slow->next;
        slow->next = nullptr;
        
        return merge(sortList(head, slow), sortList(mid, tail));
    }

    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
};

class Solution3 {
public:
    ListNode* merge(ListNode* L, ListNode* R) {
        ListNode dummyHead;
        ListNode *cur = &dummyHead;
        while (L && R) {
            if (L->val < R->val) {
                cur->next = L;
                L = L->next;
            } else {
                cur->next = R;
                R = R->next;
            }
            cur = cur->next;
        }
        cur->next = L ? L : R;
        return dummyHead.next;
    }

    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (!head || head == tail) return head;

        // 快慢指针找到链表中点
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;  // 断开链表

        return merge(sortList(head, slow), sortList(mid, tail));
    }

    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
};


int main() {
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution2 obj;
    ListNode *result = obj.sortList(head);

    return 0;
}