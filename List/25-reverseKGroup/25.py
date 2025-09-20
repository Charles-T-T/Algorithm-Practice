from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummyHead = ListNode(0, head)
        k_nodes = []
        cur = dummyHead.next
        before_group = dummyHead
        while cur:
            k_nodes.append(cur)
            group_next = cur.next
            if len(k_nodes) == k:
                for i in range(k-1, 0, -1):
                    k_nodes[i].next = k_nodes[i-1]
                k_nodes[0].next = group_next
                before_group.next = k_nodes[-1]
                before_group = k_nodes[0]
                k_nodes.clear()
            cur = group_next
        return dummyHead.next
            