class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for str in strs:
            zero_count = str.count('0')
            one_count = str.count('1')
            for i in range(m, zero_count - 1, -1):
                for j in range(n, one_count - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - zero_count][j - one_count] + 1)
        return dp[m][n]
    
obj = Solution()
print(obj.findMaxForm(["10", "0001","111001","1","0"], 5, 3))