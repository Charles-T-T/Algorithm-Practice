# 1143. 最长公共子序列

[点此跳转题目链接](https://leetcode.cn/problems/longest-common-subsequence/description/)

## 题目描述

给定两个字符串 `text1` 和 `text2`，返回这两个字符串的最长 **公共子序列** 的长度。如果不存在 **公共子序列** ，返回 `0` 。

一个字符串的 **子序列** 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

- 例如，`"ace"` 是 `"abcde"` 的子序列，但 `"aec"` 不是 `"abcde"` 的子序列。

两个字符串的 **公共子序列** 是这两个字符串所共同拥有的子序列。

 

**示例 1：**

```
输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace" ，它的长度为 3 。
```

**示例 2：**

```
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。
```

**示例 3：**

```
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。
```

 

**提示：**

- `1 <= text1.length, text2.length <= 1000`
- `text1` 和 `text2` 仅由小写英文字符组成。



## 题解

**动态规划**的经典问题。

- `dp` 数组的含义： 

  - 记 `text1` 的前 `i` 个字符组成的子串为 $A$ 
  - 记 `text2` 的前 `j` 个字符组成的子串为 $B$ 

  `dp[i][j]` 表示 $A$ 和 $B$ 的最长公共子序列长度

- 状态转移方程：

  - 如果 `text1[i - 1] == text2[j - 1]` ，即当前的 $A$ 和 $B$ 末尾字符相同，则自然可以将其加入之前的公共子序列中，相应的最长公共子序列长度即为 `dp[i][j] = dp[i - 1][j - 1] + 1`
  - 否则，无法形成更长的公共子序列，继承之前的最大长度： `dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])` 

> 该算法更详细的讲解参见 [代码随想录-1143](https://programmercarl.com/1143.最长公共子序列.html#思路)

**代码（C++）**

```cpp
int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i <= text1.size(); ++i) {
        for (int j = 1; j <= text2.size(); ++j) {
            if (text1[i - 1] == text2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[text1.size()][text2.size()];
}
```

> 完事可以接着做 [1035. 不相交的线 - 力扣（LeetCode）](https://leetcode.cn/problems/uncrossed-lines/description/) ，稍微想一下就会发现那题就是个最长公共子序列问题，算法与本题一模一样 :rofl: ​