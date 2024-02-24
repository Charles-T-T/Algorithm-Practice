#include <iostream>
#include <vector>

using namespace std;

/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：
输入：head = [1], n = 1
输出：[]

示例 3：
输入：head = [1,2], n = 1
输出：[1]
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
        // 思路：用两个指针，间隔n个结点，第一个结点在前面“探路”
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
