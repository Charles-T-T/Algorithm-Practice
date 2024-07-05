# 206. 反转链表

[点此跳转题目链接](https://leetcode.cn/problems/reverse-linked-list/description/)

## 题目描述

给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表。

 

**示例 1：**

![img](./rev1ex1.jpg)

```sh
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
```

**示例 2：**

![img](./rev1ex2.jpg)

```sh
输入：head = [1,2]
输出：[2,1]
```

**示例 3：**

```sh
输入：head = []
输出：[]
```

 

**提示：**

- 链表中节点的数目范围是 `[0, 5000]`
- `-5000 <= Node.val <= 5000`

 

**进阶：**链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？



## 题解

我的思路是用一个新链表存储反转后的结果，然后遍历原链表，将遍历到的节点依次插入新链表的**头部**，结束后新链表自然就是反转后的样子了。这样写下来的代码我感觉也比较简洁优雅。

**代码（C++）**

```cpp
ListNode *reverseList(ListNode *head)
{
    // 思路：开一个新链表，采用头插法依次插入原来链表的节点
    ListNode *dummyHead = new ListNode();
    while (head) {
        dummyHead->next = new ListNode(head->val, dummyHead->next);
        head = head->next;
    }
    return dummyHead->next;
}
```

看了下 [卡哥的解法](https://programmercarl.com/0206.翻转链表.html#思路) ，也mark在此以供参考：

**双指针解法**

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* temp; // 保存cur的下一个节点
    ListNode* cur = head;
    ListNode* pre = NULL;
    while(cur) {
        temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
        cur->next = pre; // 翻转操作
        // 更新pre 和 cur指针
        pre = cur;
        cur = temp;
    }
    return pre;
}
```

**递归法**

```cpp
ListNode* reverse(ListNode* pre,ListNode* cur){
    if(cur == NULL) return pre;
    ListNode* temp = cur->next;
    cur->next = pre;
    // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
    // pre = cur;
    // cur = temp;
    return reverse(cur,temp);
}
ListNode* reverseList(ListNode* head) {
    // 和双指针法初始化是一样的逻辑
    // ListNode* cur = head;
    // ListNode* pre = NULL;
    return reverse(NULL, head);
}
```

递归法没什么好说的了，我的写法时空复杂度都是 $O(n)$ ，但是双指针可以原地修改，空间复杂度为 $O(1)$ 。

> 又想了一下，我的写法其实每次遍历过后把原来链表节点的空间释放掉，一抵消，空间复杂度是不是也算 $O(1)$ 哈哈哈哈哈 :laughing: 
>
> anyway其实根据实际情况决定要不要保留原链表就好。