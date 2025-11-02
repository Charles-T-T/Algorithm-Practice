from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        exist = set()
        for num in nums:
            if num in exist:
                return num
            else:
                exist.add(num)
        return 0