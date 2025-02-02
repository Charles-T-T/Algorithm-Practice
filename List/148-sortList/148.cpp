#include <algorithm>
#include <iostream>
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/// @brief 暴力解法
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        vector<int> elements;
        while (head) {
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
    ListNode *merge(ListNode *L, ListNode *R) {
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

    ListNode *sortList(ListNode *head, ListNode *tail) {
        if (!head || head == tail)
            return head;

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

    ListNode *sortList(ListNode *head) { return sortList(head, nullptr); }
};

/// @brief 归并算法（自底向上）
class Solution3 {
public:
    ListNode *merge(ListNode *L, ListNode *R) {
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

    ListNode *sortList(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        // 获取链表长度
        int length = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            length++;
            cur = cur->next;
        }

        // 自底向上，两两合并长度为subLength的子链表
        ListNode *dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode *prev = dummyHead;
            cur = prev->next;
            while (cur != nullptr) {
                // 获取第一个子链表
                ListNode *head1 = cur;
                for (int i = 1; i < subLength && cur->next != nullptr; ++i) {
                    cur = cur->next;
                }

                // 获取第二个子链表
                ListNode *head2 = cur->next;
                cur->next = nullptr;  // 断开第一个子链表结尾
                cur = head2;
                for (int i = 1; i < subLength && cur && cur->next; ++i) {
                    cur = cur->next;
                }

                // 预存第三个子链表（即下一轮的第一个子链表）的头节点
                // 即第二个子链表结尾节点的next节点
                ListNode *nextHead = nullptr;
                if (cur != nullptr) {
                    nextHead = cur->next;
                    cur->next = nullptr;  // 断开第二个子链表结尾
                }

                // 合并第一、二个子链表
                ListNode *merged = merge(head1, head2);
                
                // 更新prev、cur指针
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                cur = nextHead;
            }
        }
        return dummyHead->next;
    }
};

int main() {
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution3 obj;
    ListNode *result = obj.sortList(head);

    return 0;
}