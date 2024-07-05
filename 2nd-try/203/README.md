# 203. 移除链表元素

[点此跳转题目链接](https://leetcode.cn/problems/remove-linked-list-elements/description/)

## 题目描述

给你一个链表的头节点 `head` 和一个整数 `val` ，请你删除链表中所有满足 `Node.val == val` 的节点，并返回 **新的头节点** 。

 

**示例 1：**

![img](./removelinked-list.jpg)

```sh
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
```

**示例 2：**

```sh
输入：head = [], val = 1
输出：[]
```

**示例 3：**

```sh
输入：head = [7,7,7,7], val = 7
输出：[]
```

 

**提示：**

- 列表中的节点数目在范围 `[0, 104]` 内
- `1 <= Node.val <= 50`
- `0 <= val <= 50`



## 题解

链表入门题目。 :warning: 注意

:one: 虚拟头节点 `dummyHead` 的运用（便于统一操作）

:two: **每次删除节点后，下一个节点可能还是要删除的**，所以应该检测到下一个不是要删除的节点后，再将指针移动、指向下一个节点。

**代码（C++）**

```cpp
ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *cur = dummyHead;
    while (cur->next) {
        if (cur->next->val == val) 
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }
    return dummyHead->next;
}
```

无链表基础的同学建议移步 [代码随想录 (programmercarl.com)](https://programmercarl.com/0203.移除链表元素.html#思路) 看这题的详解。
