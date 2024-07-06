# 19. 删除链表的倒数第N个节点

[点此跳转题目链接](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/)

## 题目描述

给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

 

**示例 1：**

![img](./remove_ex1.jpg)

```
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

**示例 2：**

```
输入：head = [1], n = 1
输出：[]
```

**示例 3：**

```
输入：head = [1,2], n = 1
输出：[1]
```

 

**提示：**

- 链表中结点的数目为 `sz`
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

 

**进阶：**你能尝试使用一趟扫描实现吗？



## 题解

最简单直接的思路显然是：先遍历一次，得出链表长度，再从头节点开始走（总长-倒数位置）的长度即可。这样相当于要扫描两遍，下面给出一趟扫描的解法：

采用**前后双指针**，前指针先走 n + 1 步，然后两个指针开始以单位速度前进，前指针走到链表结尾空节点时，后指针恰好指向待删除节点的前驱节点，于是可以进行删除。

> 前指针先走n步的话，后指针会恰停在待删除节点上，则无法删除。

**代码（C++）**

```cpp
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // 思路：双指针，快指针先走 n + 1 步，然后快慢指针一起走
    // 快指针走到链表末尾空指针处时，慢指针恰好位于倒数第n个节点的前驱
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *fast = dummyHead, *slow = dummyHead;
    for (int i = 0; i < n + 1; i++)
        fast = fast->next;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummyHead->next;
}
```

更详细的讲解参见[代码随想录 (programmercarl.com)](https://programmercarl.com/0019.删除链表的倒数第N个节点.html#算法公开课)。

