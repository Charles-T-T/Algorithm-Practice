# 面试题 02.07. 链表相交

[点此跳转题目链接](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/)

## 题目描述

给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 `null` 。

图示两个链表在节点 `c1` 开始相交：

[![img](./160_statement.png)](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)

题目数据 **保证** 整个链式结构中不存在环。

**注意**，函数返回结果后，链表必须 **保持其原始结构** 。

 

**示例 1：**

[![img](./160_example_1.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_1.png)

```
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
```

**示例 2：**

[![img](./160_example_2.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_2.png)

```
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Intersected at '2'
解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。
在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
```

**示例 3：**

[![img](./160_example_3.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_3.png)

```
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
这两个链表不相交，因此返回 null 。
```

 

**提示：**

- `listA` 中节点数目为 `m`
- `listB` 中节点数目为 `n`
- `0 <= m, n <= 3 * 104`
- `1 <= Node.val <= 105`
- `0 <= skipA <= m`
- `0 <= skipB <= n`
- 如果 `listA` 和 `listB` 没有交点，`intersectVal` 为 `0`
- 如果 `listA` 和 `listB` 有交点，`intersectVal == listA[skipA + 1] == listB[skipB + 1]`

 

**进阶：**  你能否设计一个时间复杂度 `O(n)` 、仅用 `O(1)` 内存的解决方案？



## 题解

一个简单的思路是用哈希集合，把两条链的节点逐个加入，直到遇到已存在的，则说明是相交节点：
```cpp
ListNode *getIntersectionNode_BySet(ListNode *headA, ListNode *headB)
{
    // 用一个set存储a链节点
    set<ListNode *> nodeSet;
    while (headA || headB)
    {
        if (headA)
        {
            if (nodeSet.find(headA) != nodeSet.end())
                return headA;
            nodeSet.insert(headA);
            headA = headA->next;
        }
        if (headB)
        { // 检查b链节点是否已在集合（a链）中出现过
            if (nodeSet.find(headB) != nodeSet.end())
                return headB;
            nodeSet.insert(headB);
            headB = headB->next;
        }
    }
    return nullptr;
}
```

下面考虑不用其他容器的方法。受到题目示例图的影响可以发现，由于相交节点之后的链表是公共的，所以若有相交，则应该先把两条链的**尾端对齐**。然后再各用一个指针同步向后遍历，遇到相同的指针则是相交节点。

**代码（C++）**

```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // 先找出长链
    ListNode *curA = headA, *curB = headB;
    int lenA = 0, lenB = 0;
    while (curA) {
        lenA++;
        curA = curA->next;
    }
    while (curB) {
        lenB++;
        curB = curB->next;
    }
    // 将两条链的尾端对齐（方法：长链指针先走 长度差 个节点）
    curA = headA, curB = headB;
    if (lenA > lenB) {
        int dist = lenA - lenB;
        for (int i = 0; i < dist; i++)
            curA = curA->next;
    } else {
        int dist = lenB - lenA;
        for (int i = 0; i < dist; i++)
            curB = curB->next;
    }
    // 开始检查有无相同节点
    while (curA && curB)
    {
        if (curA == curB)
            return curA;
        curA = curA->next, curB = curB->next;
    }
    return nullptr;
}
```

