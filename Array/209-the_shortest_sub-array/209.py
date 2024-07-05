from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        start = 0
        end = 0
        sum_nums = nums[end]  # 先加一个，这样后面就可以避免“先累加再自增”的顺序
        count_ans = len(nums) + 1
        count_temp = 0
        while 1: # 后面有跳出判断了
            if sum_nums >= target:
                count_temp = end - start + 1 # 要+1
                if count_temp < count_ans:
                    count_ans = count_temp
                sum_nums -= nums[start]
                start += 1

            else:
                # 这里就可以先自增，再判断要不要跳出，再累加
                end += 1
                if end >= len(nums):
                    break
                sum_nums += nums[end]

        if count_ans > len(nums):
            return 0
        return count_ans
    
obj = Solution()
res = obj.minSubArrayLen(7, [2, 3,1,2,4,3])