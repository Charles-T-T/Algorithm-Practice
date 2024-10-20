# 516. 最长回文子序列

[点此跳转题目链接](https://leetcode.cn/problems/longest-palindromic-subsequence/description/)

## 题目描述

给你一个字符串 `s` ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

 

**示例 1：**

```
输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。
```

**示例 2：**

```
输入：s = "cbbd"
输出：2
解释：一个可能的最长回文子序列为 "bb" 。
```

 

**提示：**

- `1 <= s.length <= 1000`
- `s` 仅由小写英文字母组成



## 题解

**动态规划** 解决，如果做了前面的那些子序列类型题目，这题基本可以秒了：

- 确定 `dp` 数组含义： `dp[i][j]` 表示子串 `s[i][j]` 中最长回文子序列的长度

- 状态转移方程：

  - 如果 `i = j` ，即单个字符，视为回文子序列，长度为1
  - 否则，
    - 如果 `s[i] = s[j]` ，相当于其内部的最长回文子序列有增加了相同的一头一尾，故 `dp[i][j] = dp[i + 1][j - 1] + 2` 
    - 否则，尝试拿 `s[i]` 或 `s[j]` 与内部的子串匹配，或许能增长最长回文子序列，即 `dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])` 

- 确定遍历顺序：从状态转移方程可以看出， `dp[i][j]` 可以从三种状态转移而来：

  - `dp[i + 1][j - 1]` 
  - `dp[i + 1][j]` 
  - `dp[i][j - 1]` 

  相应的，遍历顺序自然应该是：

  ```cpp
  for (int i = s.size() - 1; i >= 0; --i) {
      for (int j = i; j < s.size(); ++j) {
  		...
      }
  }
  ```

**代码** 

**c++** 

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (i == j) {
                    dp[i][j] = 1;
                } else if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][s.size() - 1];
    }
};
```

**python** 

```python
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        dp = [[0 for _ in range(len(s))] for _ in range(len(s))]

        for i in range(len(s) - 1, -1, -1):
            for j in range(i, len(s)):
                if i == j:
                    dp[i][j] = 1
                elif s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
                
        return dp[0][-1]
```

**golang** 

```go
func longestPalindromeSubseq(s string) int {
	dp := make([][]int, len(s))
	for i := range dp {
		dp[i] = make([]int, len(s))
	}

	for i := len(s) - 1; i >= 0; i-- {
		for j := i; j < len(s); j++ {
			if i == j {
				dp[i][j] = 1
			} else if s[i] == s[j] {
				dp[i][j] = dp[i+1][j-1] + 2
			} else {
				dp[i][j] = max(dp[i+1][j], dp[i][j-1])
			}
		}
	}

	return dp[0][len(s)-1]
}
```





