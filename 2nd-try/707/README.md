# 707. 设计链表

[点此跳转题目链接](https://leetcode.cn/problems/design-linked-list/description/)

## 题目描述

你可以选择使用单链表或者双链表，设计并实现自己的链表。

单链表中的节点应该具备两个属性：`val` 和 `next` 。`val` 是当前节点的值，`next` 是指向下一个节点的指针/引用。

如果是双向链表，则还需要属性 `prev` 以指示链表中的上一个节点。假设链表中的所有节点下标从 **0** 开始。

实现 `MyLinkedList` 类：

- `MyLinkedList()` 初始化 `MyLinkedList` 对象。
- `int get(int index)` 获取链表中下标为 `index` 的节点的值。如果下标无效，则返回 `-1` 。
- `void addAtHead(int val)` 将一个值为 `val` 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
- `void addAtTail(int val)` 将一个值为 `val` 的节点追加到链表中作为链表的最后一个元素。
- `void addAtIndex(int index, int val)` 将一个值为 `val` 的节点插入到链表中下标为 `index` 的节点之前。如果 `index` 等于链表的长度，那么该节点会被追加到链表的末尾。如果 `index` 比长度更大，该节点将 **不会插入** 到链表中。
- `void deleteAtIndex(int index)` 如果下标有效，则删除链表中下标为 `index` 的节点。

 

**示例：**

```sh
输入
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
输出
[null, null, null, null, 2, null, 3]

解释
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
myLinkedList.get(1);              // 返回 2
myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
myLinkedList.get(1);              // 返回 3
```

 

**提示：**

- `0 <= index, val <= 1000`
- 请不要使用内置的 LinkedList 库。
- 调用 `get`、`addAtHead`、`addAtTail`、`addAtIndex` 和 `deleteAtIndex` 的次数不超过 `2000` 。



## 题解

本身没什么难度，但是可以较完整地过一遍链表的各项操作设计，非常有助于加深理解。

代码上要注意的可能就是**下标的合法判断**和**防止指针越界**。个人经验是利用虚头节点，带入第一个真实节点（下标为0的节点）考虑，有助于快速判断。例如，取指定下标节点的值时：

```cpp
ListNode *cur = dummyHead;
for (int i = 0; i <= index; i++)
    cur = cur->next;
```

这里for循环终止判断是 `<=` ，比如考虑取下标为0的节点，即 `dummyHead->next` ，如果用 `<` 终止for循环， `cur` 都无法移动、最终还是指向虚头节点。所以为了让 `cur` 进for循环走一次也得用 `<=` ( :dog: )。

而在删除指定下标的节点时：

```cpp
ListNode *cur = dummyHead;
for (int i = 0; i < index; i++)
    cur = cur->next;
cur->next = cur->next->next;
```

由于我们需要定位到待删除节点的**前驱节点**，还是用删除下标为0的节点考虑，那么 `cur` 应该不需要往前走、直接保持指向 `dummyHead` 就好了，所以不用它进for循环，条件判断用 `<` 。

**代码（C++）**

```cpp
class MyLinkedList
{
private:
    // 链表节点
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    int len;             // 当前链表长度
    ListNode *dummyHead; // 链表虚头节点

public:
    MyLinkedList()
    {
        dummyHead = new ListNode();
        len = 0;
    }

    int get(int index)
    {
        if (index >= len || index < 0)
            return -1;

        ListNode *cur = dummyHead;
        for (int i = 0; i <= index; i++)
            cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val)
    {
        ListNode *newHead = new ListNode(val, dummyHead->next);
        dummyHead->next = newHead;
        len++;
    }

    void addAtTail(int val)
    {
        addAtIndex(len, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > len)
            return;

        ListNode *cur = dummyHead;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        ListNode *newNode = new ListNode(val, cur->next);
        cur->next = newNode;
        len++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= len)
            return;

        ListNode *cur = dummyHead;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        cur->next = cur->next->next;
        len--;
    }
};
```

