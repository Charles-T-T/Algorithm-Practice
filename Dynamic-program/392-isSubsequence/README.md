# 392. 判断子序列

[点此跳转题目链接](https://leetcode.cn/problems/is-subsequence/description/)

## 题目描述

给定字符串 **s** 和 **t** ，判断 **s** 是否为 **t** 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，`"ace"`是`"abcde"`的一个子序列，而`"aec"`不是）。

**进阶：**

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

**致谢：**

特别感谢 [@pbrother ](https://leetcode.com/pbrother/)添加此问题并且创建所有测试用例。

 

**示例 1：**

```
输入：s = "abc", t = "ahbgdc"
输出：true
```

**示例 2：**

```
输入：s = "axc", t = "ahbgdc"
输出：false
```

 

**提示：**

- `0 <= s.length <= 100`
- `0 <= t.length <= 10^4`
- 两个字符串都只由小写字符组成。



## 题解

### 双指针

首先想到的是双指针方法：两个指针分别遍历 `s` 和 `t` ，遇到相同的字符就都往前走，否则 `t` 的指针往前走，以试图找到与当前 `s` 中字符相同的字符。最后，如果 `s` 的指针成功走到末尾，说明 `s` 这个序列在 `t` 中找到了，即它是 `t` 的子串。

这应该是最简单且符合直觉的算法了。

**代码（C++）**

```cpp
bool isSubsequence(string s, string t) // 双指针
{
    int sp = 0;
    int tp = 0;
    while (sp < s.size() && tp < t.size()) {
        if (s[sp] == t[tp]) 
            sp++;
        tp++;
    }
    return sp == s.size();
}
```

### 动态规划

#### 子序列问题

此外，这题其实完全可以套用动态规划子序列问题的算法：如果 `s` 是 `t` 的子序列，则 `s` 和 `t` 的最长公共子序列长度就是 `s` 的长度。

```cpp
bool isSubsequence(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 1; i <= s.size(); ++i)
    {
        int k = t.size() - s.size() + i; // 优化搜索范围：t中没检查的字符数量要多于s中的
        for (int j = 1; j <= k; ++j)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[s.size()][t.size()] == s.size();
}
```

### 动态规划预处理+双指针

考虑题目进阶要求中**大量重复**（数十亿次）判断子序列的情况，即使采用上面算法中较快的双指针法，每次都要进行 $O(n)$ 的计算，不够高效。

可以发现，每次计算花费了大部分时间用于 **在 `t` 中寻找下一个匹配 `s` 的字符** ，也就是说如果我们可以通过预处理，提前记录 **对于 `t` 的任意位置 `i` ，从 `i` 起往后各字符（本题中即26个英文字母）第一次出现的次数** ，那么每次查找匹配字符就变成 $O(1)$ 的操作了 :tada: ​

这个**预处理**部分就可以用动态规划解决：

- `dp` 数组的含义： `dp[i][j]` 表示 `t` 中从位置 `i` 开始，下一次出现字符 `j` （用数字一一对应字符）的位置（包括 `i` ）
- 状态转移方程：
  - 如果 `t[i]` 对应的就是字符 `j` ，那么目标位置就是 `i` ： `dp[i][j] = i` 
  - 否则，要在 `i` 后面去找，即： `dp[i][j] = dp[i + 1][j]` （由此看出，要逆序构建 `dp` ）

代码上，为了方便，可以将 `dp[t.size()][...]` 全部初始化为 `t.size()` ，表示已经找到末尾、不会再出现目标字符了。 

**代码（C++）**

```cpp
bool isSubsequence(string s, string t) // DP预处理+双指针
{
    // 预处理
    vector<vector<int>> dp(t.size() + 1, vector<int>(26, t.size()));
    for (int i = t.size() - 1; i >= 0; --i) {
        int charNum = t[i] - 'a';
        for (int j = 0; j < 26; ++j) 
            dp[i][j] = charNum == j ? i : dp[i + 1][j];
    }

    // 双指针匹配
    int sp = 0;
    int tp = 0;
    while (sp < s.size() && tp < t.size()) {
        tp = dp[tp][s[sp] - 'a']; // 利用预处理结果
        if (s[sp] == t[tp]) 
            sp++, tp++;
    }

    return sp == s.size();
}
```

