from typing import List

class Solution:
    def __init__(self):
        self.path: List[str] = []
        self.res: List[List[str]] = []

    def palindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l <= r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True

    def back_tracking(self, s: str, cut_pos: int):
        if cut_pos == len(s):
            self.res.append(self.path.copy())
            return
        
        for i in range(cut_pos, len(s)):
            if self.palindrome(s[cut_pos:i+1]):
                self.path.append(s[cut_pos:i+1])
            else:
                continue
            self.back_tracking(s, i + 1)
            self.path = self.path[:-1]

    def partition(self, s: str) -> List[List[str]]:
        self.back_tracking(s, 0)
        return self.res