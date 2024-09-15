# 115. 不同的子序列

[点此跳转题目链接](https://leetcode.cn/problems/distinct-subsequences/description/)

## 题目描述

给你两个字符串 `s` 和 `t` ，统计并返回在 `s` 的 **子序列** 中 `t` 出现的个数，结果需要对 $10^9 + 7$ 取模。

 

**示例 1：**

```
输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
```

**示例 2：**

```
输入：s = "babgbag", t = "bag"
输出：5
解释：
如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
```

 

**提示：**

- `1 <= s.length, t.length <= 1000`
- `s` 和 `t` 由英文字母组成



## 题解

**动态规划**解决，基本还是采用**子序列问题**的框架，不过为了求序列的不同组合方式，需要修改一下状态转移方程。

- `dp` 数组的含义： `dp[i][j]` 表示在 `s` 的前 `i` 个字符组成的子串 `s[0...i-1]` 中， `t` 的前 `j` 个字符组成的子串 `t[0...j-1]` 出现的次数。

- 状态转移方程：

  - 如果 `s[i - 1] == t[j - 1]` ，匹配成功，一方面可以“继承”此前的结果，即 `dp[i - 1][j - 1]` ；另一方面，也要加上 `dp[i - 1][j]` ，即 `s` 不添加最后这个 `s[j - 1]` 之前，子序列中 `t[0...j-1]` 的个数。故最终有 `dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]` 。

    > 例如，考虑 `s = "bagg"` 和 `t = "bag"` ：
    >
    > `s[3] == t[2]` ，如果用它匹配，相当于取 `s[0, 1, 3]` 来构成 `t` ，此时 `dp[i][j] = dp[i - 1][j - 1]` ；
    >
    > 但是，我们也可以不用 `s[3]` 而用 `s[2]` 来匹配 `'g'` ，相当于取 `s[0, 1, 2]` 来构成 `t` ，此时 `dp[i][j] = dp[i - 1][j]` 。
    >
    > 因此，上述两种情况都要加上才是完整的 `dp[i][j]` 。

  - 否则，说明 `s[i - 1]` 是 “没用的” ， `t[0...j-1]` 出现次数和上次一样 ，即 `dp[i][j] = dp[i - 1][j]` 。

- 初始化：要在 `s` 的子序列中找 `t` ，那么如果 `t` 是空串，自然存在于任意长度的 `s` 的子序列中（算作出现1次），即 `dp[i][0] = 1` 。

**代码（C++）**

```cpp
int numDistinct(string s, string t)
{
    vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));

    for (int i = 0; i < dp.size(); ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 1; j <= t.size(); ++j) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[s.size()][t.size()] % ((uint64_t)1e9 + 7);
}
```

