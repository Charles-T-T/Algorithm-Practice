# 24. 两两交换链表中的节点

[点此跳转题目链接](https://leetcode.cn/problems/swap-nodes-in-pairs/description/)

## 题目描述

给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

 

**示例 1：**

![img](./swap_ex1.jpg)

```sh
输入：head = [1,2,3,4]
输出：[2,1,4,3]
```

**示例 2：**

```sh
输入：head = []
输出：[]
```

**示例 3：**

```sh                                  
输入：head = [1]
输出：[1]
```

 

**提示：**

- 链表中节点的数目在范围 `[0, 100]` 内
- `0 <= Node.val <= 100`



## 题解

采用**前后双指针**解决：前指针在后指针的下一个位置，每次交换两个指针的值、两个指针同时前进两位，直到链表结尾。

**代码（C++）**

```cpp
ListNode *swapPairs(ListNode *head)
{
    // 思路：双指针
    if (!head || !head->next)
        return head;
    
    ListNode *former = head->next, *later = head;
    swap(former->val, later->val);
    while (former->next && former->next->next) {
        former = former->next->next;
        later = later->next->next;
        swap(former->val, later->val);
    }
    return head;
}
```