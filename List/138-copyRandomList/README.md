# 138. 随机链表的复制

[点此跳转题目链接](https://leetcode.cn/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-100-liked)

## 题目描述

给你一个长度为 `n` 的链表，每个节点包含一个额外增加的随机指针 `random` ，该指针可以指向链表中的任何节点或空节点。

构造这个链表的 **[深拷贝](https://baike.baidu.com/item/深拷贝/22785317?fr=aladdin)**。 深拷贝应该正好由 `n` 个 **全新** 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 `next` 指针和 `random` 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。**复制链表中的指针都不应指向原链表中的节点** 。

例如，如果原链表中有 `X` 和 `Y` 两个节点，其中 `X.random --> Y` 。那么在复制链表中对应的两个节点 `x` 和 `y` ，同样有 `x.random --> y` 。

返回复制链表的头节点。

用一个由 `n` 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 `[val, random_index]` 表示：

- `val`：一个表示 `Node.val` 的整数。
- `random_index`：随机指针指向的节点索引（范围从 `0` 到 `n-1`）；如果不指向任何节点，则为 `null` 。

你的代码 **只** 接受原链表的头节点 `head` 作为传入参数。

 

**示例 1：**

![img](./e1.png)

```
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
```

**示例 2：**

![img](./e2.png)

```
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]
```

**示例 3：**

**![img](./e3.png)**

```
输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
```

 

**提示：**

- `0 <= n <= 1000`
- `-104 <= Node.val <= 104`
- `Node.random` 为 `null` 或指向链表中的节点。



## 题解

第一反应是在遍历并复制普通链表的过程中，用一个**哈希表**，存储原链表中各节点和新链表中的各节点的**映射** ;然后再过一遍原链表，这次获取它的 `random` 节点并在哈希表中找到其在新链表中对应的节点，从而在新链表中添加对应的 `random` 节点：

```cpp
Node *copyRandomList(Node *head)
{
    unordered_map<Node*, Node*> nodeMap; // {原节点：新节点}
    Node *dummyHead = new Node(0);
    Node *cur = dummyHead;
    Node *old = head;

    // 复制原普通链表
    while (old) {
        cur->next = new Node(old->val);
        cur = cur->next;
        nodeMap[old] = cur;
        old = old->next;
    }

    // 复制原随机链表
    cur = dummyHead->next;
    old = head;
    while (cur) {
        cur->random = nodeMap[old->random];
        cur = cur->next;
        old = old->next;
    }

    return dummyHead->next;
}
```

这么做是比较符合直觉的，毕竟由题目示例可知 `random` 可能指向当前节点后面位置的节点，所以似乎得先把普通的 “直链” 连好，才好处理 `random` 节点的连接。

不过，也可以利用回溯法，总地遍历一次原链表，在此过程中尝试连接各节点的 `random` 节点，如果 `random` 存在于新链（即在当前节点之前）就直接连，否则**递归**调用方法来创建它并连接。

下面是**LeetCode官方题解**对该算法的描述和代码：

> 本题要求我们对一个特殊的链表进行深拷贝。如果是普通链表，我们可以直接按照遍历的顺序创建链表节点。而本题中因为随机指针的存在，当我们拷贝节点时，「当前节点的随机指针指向的节点」可能还没创建，因此我们需要变换思路。一个可行方案是，我们利用回溯的方式，让每个节点的拷贝操作相互独立。对于当前节点，我们首先要进行拷贝，然后我们进行「当前节点的后继节点」和「当前节点的随机指针指向的节点」拷贝，拷贝完成后将创建的新节点的指针返回，即可完成当前节点的两指针的赋值。
>
> 具体地，我们用哈希表记录每一个节点对应新节点的创建情况。遍历该链表的过程中，我们检查「当前节点的后继节点」和「当前节点的随机指针指向的节点」的创建情况。如果这两个节点中的任何一个节点的新节点没有被创建，我们都立刻递归地进行创建。当我们拷贝完成，回溯到当前层时，我们即可完成当前节点的指针赋值。注意一个节点可能被多个其他节点指向，因此我们可能递归地多次尝试拷贝某个节点，为了防止重复拷贝，我们需要首先检查当前节点是否被拷贝过，如果已经拷贝过，我们可以直接从哈希表中取出拷贝后的节点的指针并返回即可。
>
> 在实际代码中，我们需要特别判断给定节点为空节点的情况。
>
> ```cpp
> class Solution {
> public:
>     unordered_map<Node*, Node*> cachedNode;
> 
>     Node* copyRandomList(Node* head) {
>         if (head == nullptr) {
>             return nullptr;
>         }
>         if (!cachedNode.count(head)) {
>             Node* headNew = new Node(head->val);
>             cachedNode[head] = headNew;
>             headNew->next = copyRandomList(head->next);
>             headNew->random = copyRandomList(head->random);
>         }
>         return cachedNode[head];
>     }
> };
> ```

---

上述算法的时空复杂度均为 $O(n)$ 。通过下面更巧妙的算法，我们可以免除额外数据结构（哈希表）从而将空间复杂度降为 $O(1)$ :

- 将原链表中每个节点按其节点值 `val` 复制后，直接插入到原节点的后面

  > ​​例如： $A-B-C$ 变为 $A-A'-B-B'-C-C'$ （对于任意节点 $X$ ，其复制节点记为 $X'$ ）

- 此时，任意复制节点 $X'$ 需要连接的 `random` 节点 $R'$ ，就恰好位于原节点 $X$ 的 `random` 节点 $R$ 后面了

  > 可以看到，这实际上还是确定了一种 “原节点-新节点” 的映射，不过不再需要哈希表来实现，因为上述数据结构天然将二者从位置上 “绑定” 在了一起。

- 将新节点的 `random` 节点连好后，从链表中将新节点取出连成新表即为所求——这也很容易：从第一个新节点开始，间隔着取节点即可

**代码（C++）**

```cpp
Node *copyRandomList(Node *head) 
{
    if (head == nullptr)
        return nullptr;

    // 将复制节点插入到原节点后
    Node *old = head;
    while (old) {
        Node *copyNode = new Node(old->val);
        copyNode->next = old->next;
        old->next = copyNode;
        old = copyNode->next;
    }

    // 连接random节点
    Node *cur = head;
    while (cur) {
        if (cur->random)
            cur->next->random = cur->random->next;
        cur = cur->next->next;
    }

    // 取出新节点
    Node *newHead = head->next;
    old = head;
    while (old) {
        Node *newNode = old->next;
        old->next = old->next->next; // 记得恢复原链
        old = old->next;
        if (newNode->next)
            newNode->next = newNode->next->next;
    }

    return newHead;
}
```

