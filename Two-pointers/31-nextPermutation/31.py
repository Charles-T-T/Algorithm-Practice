from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = n - 1
        while i >= 1:
            if nums[i] > nums[i - 1]:
                for j in range(n - 1, i - 1, -1):
                    if nums[j] > nums[i - 1]:
                        nums[j], nums[i - 1] = nums[i - 1], nums[j]
                        break
                break
            i -= 1
        nums[i:] = reversed(nums[i:])


if __name__ == "__main__":
    l = list([2, 1, 3, 5])
    l[1:] = reversed(l[1:])
    print(l)
