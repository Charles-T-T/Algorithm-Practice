from typing import List, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class MinListHeap:
    def __init__(self):
        self.data: list[tuple[int, ListNode]] = []

    def __len__(self):
        return len(self.data)

    def top(self) -> tuple[int, ListNode] | None:
        return self.data[0] if self.data else None

    def pop(self) -> tuple[int, ListNode] | None:
        if self.data:
            self._swap(0, len(self) - 1)
            v = self.data.pop()
            self._sift_down(0)
            return v
        else:
            return None

    def push(self, v: tuple[int, ListNode]):
        self.data.append(v)
        self._sift_up(len(self) - 1)

    def _swap(self, x: int, y: int):
        self.data[x], self.data[y] = self.data[y], self.data[x]

    def _sift_up(self, idx: int):
        while idx > 0:
            parent = (idx - 1) // 2
            if self.data[idx][0] < self.data[parent][0]:
                self._swap(parent, idx)
                idx = parent
            else:
                break

    def _sift_down(self, idx: int):
        n = len(self)
        while idx < n - 1:
            smallest = idx
            left = 2 * idx + 1
            if left < n and self.data[left][0] < self.data[idx][0]:
                smallest = left
            right = 2 * idx + 2
            if right < n and self.data[right][0] < self.data[smallest][0]:
                smallest = right
            if smallest != idx:
                self._swap(idx, smallest)
                idx = smallest
            else:
                break


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        min_heap = MinListHeap()
        for l in lists:
            if l:
                min_heap.push((l.val, l))

        dummy = ListNode()
        cur = dummy

        while len(min_heap) > 0:
            val, node = min_heap.pop()
            cur.next = ListNode(val)
            cur = cur.next

            if node.next:
                min_heap.push((node.next.val, node.next))

        return dummy.next

if __name__ == "__main__":
    # lists = [[1, 4, 5], [1, 3, 4], [2, 6]]
    l1 = ListNode(1)
    l1.next = ListNode(4)
    l1.next.next = ListNode(5)
    
    l2 = ListNode(1)
    l2.next = ListNode(3)
    l2.next.next = ListNode(4)  

    l3 = ListNode(2)
    l3.next = ListNode(6)

    lists = [l1, l2, l3]

    obj = Solution()
    l = obj.mergeKLists(lists)
    print(l)
