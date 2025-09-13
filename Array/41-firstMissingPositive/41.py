from typing import List
import math


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        """取巧的方法"""
        n = len(nums)
        for i in range(n):
            if nums[i] <= 0:
                nums[i] = n + 1
        for i in range(n):
            curAbsNum = abs(nums[i])
            if curAbsNum < n + 1:
                nums[curAbsNum - 1] = -abs(nums[curAbsNum - 1])
        for i in range(n):
            if nums[i] > 0:
                return i + 1
        return n + 1


if __name__ == "__main__":
    nums = [3, 4, -1, 1]
    obj = Solution()
    print(obj.firstMissingPositive(nums))
    print("这是一个测试")
