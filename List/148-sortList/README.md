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

上述算法时间复杂度为 `sort()` 的 $O(n\log{n})$ ，空间复杂度为 $O(n)$ ——因为新建了一个链表。 直接看看进阶要求：时间复杂度为 $O(n\log{n})$ ，空间复杂度为常数级。

考虑算法题中常用的高效排序算法——归并排序，有：

```cpp
class Solution {
public:
    ListNode *merge(ListNode *L, ListNode *R) {
        ListNode dummyHead;
        ListNode *cur = &dummyHead;
        while (L && R) {
            if (L->val < R->val) {
                cur->next = L;
                L = L->next;
            } else {
                cur->next = R;
                R = R->next;
            }
            cur = cur->next;
        }
        cur->next = L ? L : R;
        return dummyHead.next;
    }

    ListNode *sortList(ListNode *head, ListNode *tail) {
        if (!head || head == tail) return head;

        // 快慢指针找到链表中点
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;  // 断开链表

        return merge(sortList(head, slow), sortList(mid, tail));
    }

    ListNode *sortList(ListNode *head) { return sortList(head, nullptr); }
};
```

上述算法时间复杂度为 $O(n\log{n})$ ，即归并排序的时间复杂度。空间复杂度取决于递归调用的栈空间，为 $O(\log{n})$ ，还是没到最佳的常数级别。为此，需要采用“自底向上”的归并排序实现 $O(1)$ 的空间复杂度：

> :link: 以下内容参考 [LeetCode官方题解](https://leetcode.cn/problems/sort-list/solutions/492301/pai-xu-lian-biao-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked) 

首先求得链表的长度 `length` ，然后将链表拆分成子链表进行合并。具体做法如下：

- 用 `subLength` 表示每次需要排序的子链表的长度，初始时 `subLength=1` 。
- 每次将链表拆分成若干个长度为 `subLength` 的子链表（最后一个子链表的长度可以小于 `subLength` ），按照每两个子链表一组进行合并，合并后即可得到若干个长度为 `subLength×2` 的有序子链表（最后一个子链表的长度可以小于 `subLength×2` ）。合并两个子链表仍然使用之前用过的归并算法。
- 将 `subLength` 的值加倍，重复第 2 步，对更长的有序子链表进行合并操作，直到有序子链表的长度大于或等于 `length` ，整个链表排序完毕。

通过数学归纳法易证最后得到的链表是有序的（每次合并用到的子链表是有序的，合并后的也是有序的）。

```cpp
class Solution {
public:
    ListNode *merge(ListNode *L, ListNode *R) {
        ListNode dummyHead;
        ListNode *cur = &dummyHead;
        while (L && R) {
            if (L->val < R->val) {
                cur->next = L;
                L = L->next;
            } else {
                cur->next = R;
                R = R->next;
            }
            cur = cur->next;
        }
        cur->next = L ? L : R;
        return dummyHead.next;
    }

    ListNode *sortList(ListNode *head) {
        if (!head) {
            return nullptr;
        }

        // 获取链表长度
        int length = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            length++;
            cur = cur->next;
        }

        // 自底向上，两两合并长度为subLength的子链表
        ListNode *dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode *prev = dummyHead;
            cur = prev->next;
            while (cur != nullptr) {
                // 获取第一个子链表
                ListNode *head1 = cur;
                for (int i = 1; i < subLength && cur->next != nullptr; ++i) {
                    cur = cur->next;
                }

                // 获取第二个子链表
                ListNode *head2 = cur->next;
                cur->next = nullptr;  // 断开第一个子链表结尾
                cur = head2;
                for (int i = 1; i < subLength && cur && cur->next; ++i) {
                    cur = cur->next;
                }

                // 预存第三个子链表（即下一轮的第一个子链表）的头节点
                // 即第二个子链表结尾节点的next节点
                ListNode *nextHead = nullptr;
                if (cur != nullptr) {
                    nextHead = cur->next;
                    cur->next = nullptr;  // 断开第二个子链表结尾
                }

                // 合并第一、二个子链表
                ListNode *merged = merge(head1, head2);
                
                // 更新prev、cur指针
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                cur = nextHead;
            }
        }
        return dummyHead->next;
    }
};
```

该算法时间复杂度为 $O(n \log{n})$ ，空间复杂度为 $O(1)$ 。
