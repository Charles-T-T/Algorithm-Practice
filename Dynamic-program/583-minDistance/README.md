# 583. 两个字符串的删除操作

[点此跳转题目链接](https://leetcode.cn/problems/delete-operation-for-two-strings/description/)

## 题目描述

给定两个单词 `word1` 和 `word2` ，返回使得 `word1` 和 `word2` **相同**所需的**最小步数**。

**每步** 可以删除任意一个字符串中的一个字符。

 

**示例 1：**

```
输入: word1 = "sea", word2 = "eat"
输出: 2
解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
```

**示例  2:**

```
输入：word1 = "leetcode", word2 = "etco"
输出：4
```

 

**提示：**

- `1 <= word1.length, word2.length <= 500`
- `word1` 和 `word2` 只包含小写英文字母



## 题解

由于只提供删除操作，这题本质上就是一个**最长公共子序列**问题：**找到两个单词的最长公共子序列，然后各自将多余的字符删除**即可，这样的操作步数显然也是最少的。

**代码（C++）**

```cpp
int minDistance(string word1, string word2)
{
    // 求最长公共子序列长度
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 1; i <= word1.size(); ++i) {
        for (int j = 1; j <= word2.size(); ++j) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int maxPubLen = dp.back().back();

    return word1.size() - maxPubLen + word2.size() - maxPubLen;
}
```

