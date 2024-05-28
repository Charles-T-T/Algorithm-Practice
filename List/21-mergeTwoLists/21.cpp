#include <iostream>


/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

示例 2：
输入：l1 = [], l2 = []
输出：[]

示例 3：
输入：l1 = [], l2 = [0]
输出：[0]
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 思路：两边同时往前走，小的加入新链表、指针往前走
        ListNode *dummyHead = new ListNode();
        ListNode *cur = dummyHead;
        while (list1 && list2){
            if (list1->val < list2->val){
                cur->next = new ListNode(list1->val);
                cur = cur->next;
                list1 = list1->next;
            }
            else {
                cur->next = new ListNode(list2->val);
                cur = cur->next;
                list2 = list2->next;
            }
        }
        if (list1){
            cur->next = list1;
        }
        else {
            cur->next = list2;
        }

        return dummyHead->next;
    }
};