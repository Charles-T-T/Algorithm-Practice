from typing import List
import copy


class Solution:
    def __init__(self):
        self.res: List[List[int]] = []
        self.path: List[int] = []

    def back_tracking(self, n: int, k: int, start: int):
        if len(self.path) == k:
            self.res.append(self.path.copy())
            return

        for i in range(start, n + 1):
            self.path.append(i)
            self.back_tracking(n, k, i + 1)
            self.path.pop()

    def combine(self, n: int, k: int) -> List[List[int]]:
        self.back_tracking(n, k, 1)
        return self.res
