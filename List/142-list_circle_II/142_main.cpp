#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：
输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public: 
    // 暴力：用集合存节点
    ListNode *detectCycle_BySet(ListNode *head)
    {
        // 思路：利用哈希集合，遇到重复结点则返回
        unordered_set<ListNode*> nodeSet;
        while (head) {
            if (nodeSet.find(head) != nodeSet.end())
                return head;
            nodeSet.insert(head);
            head = head->next;
        }
        return nullptr;
    }

    // 优雅：推导法
    ListNode *detectCycle(ListNode *head)
    {
        // 思路：双指针，快指针一次走两个节点，慢指针一次走一个节点
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                // 相遇后，慢指针回到链表起点，两个指针以单位速度前进
                // 再次相遇位置就是环的起点（推导过程详见README.md）
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};