# 148. 排序链表

[点此跳转题目链接](https://leetcode.cn/problems/sort-list/description/?envType=study-plan-v2&envId=top-100-liked) 

## 题目描述

给你链表的头结点 `head` ，请将其按 **升序** 排列并返回 **排序后的链表** 。

**示例 1：**

![img](D:\codes\LeetCode\List\148-sortList\sort_list_1.jpg)

```
输入：head = [4,2,1,3]
输出：[1,2,3,4]
```

**示例 2：**

![img](D:\codes\LeetCode\List\148-sortList\sort_list_2.jpg)

```
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
```

**示例 3：**

```
输入：head = []
输出：[]
```

**提示：**

- 链表中节点的数目在范围 `[0, 5 * 104]` 内
- `-105 <= Node.val <= 105`

**进阶：** 你可以在 `O(n log n)` 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

## 题解

暴力解法无需多言，遍历一遍链表获取全部元素、排序后重新整一个新链表即可：

```cpp
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> elements;
        while (head)
        {
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
```

上述算法时间复杂度为 `sort()` 的 $O(nlogn)$ ，空间复杂度为 $O(n)$ ——因为新建了一个链表。 直接看看进阶要求：时间复杂度为 $O(nlogn)$ ，空间复杂度为常数级——那么应当是要原地修改链表了。