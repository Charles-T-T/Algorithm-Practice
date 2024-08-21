# 139. 单词拆分

[点此跳转题目链接](https://leetcode.cn/problems/word-break/)

## 题目描述

给你一个字符串 `s` 和一个字符串列表 `wordDict` 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 `s` 则返回 `true`。

**注意：** 不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

 

**示例 1：**

```
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
```

**示例 2：**

```
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。
```

**示例 3：**

```
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
```

 

**提示：**

- `1 <= s.length <= 300`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 20`
- `s` 和 `wordDict[i]` 仅由小写英文字母组成
- `wordDict` 中的所有字符串 **互不相同**



## 题解

这题乍一看似乎就是经典的 [排列问题](https://blog.csdn.net/weixin_54468359/article/details/140824712?spm=1001.2014.3001.5501) ，所以首先尝试了一下回溯算法：


```cpp
class Solution // 回溯算法，超时
{
private:
    // KMP算法，判断某个字符串是不是另一个字符串的子串
    bool isSubStr(const string &text, const string &pattern)
    {
        // 获取next数组
        auto Next = [](const string &pattern) -> vector<int>
        {
            vector<int> next(pattern.size(), 0);
            int j = 0;
            for (int i = 1; i < pattern.size(); ++i)
            {
                while (j > 0 && pattern[i] != pattern[j])
                    j = next[j - 1];
                if (pattern[i] == pattern[j])
                    j++;
                next[i] = j;
            }
            return next;
        };
        vector<int> next = Next(pattern);
        // 检查模式串是否为文本串的子串
        int j = 0;
        for (int i = 0; i < text.size(); ++i)
        {
            while (j > 0 && text[i] != pattern[j])
                j = next[j - 1];
            if (text[i] == pattern[j])
                j++;
            if (j == pattern.size())
                return true;
        }
        return false;
    }

    // 回溯算法
    string path = "";
    bool flag = false;
    int count = 0;
    void backTracking(
        string &path, 
        const string &target,
        const vector<string> &words) {
        // 递归出口（纵向遍历）
        if (path == target)
        {
            flag = true;
            return;
        }
        if (path.size() > target.size() || path != target.substr(0, path.size())) 
            return; 
    
        // 横向遍历
        for (int i = 0; i < words.size(); ++i)
        {
            path += words[i];                           // 处理
            backTracking(path, target, words);          // 递归
            path.resize(path.size() - words[i].size()); // 回溯
        }
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // 获取可能用于组成s的单词
        vector<string> subStrs;
        for (const string &word : wordDict)
        {
            if (isSubStr(s, word))
                subStrs.push_back(word);
        }

        // 回溯算法
        backTracking(path, s, subStrs);
        return flag;
    }
};
```

不出意外的超时了。其实我就是想复习一下KMP算法（确信）。

但是通过 **记忆化搜索** ，我们可以减少回溯算法的问题规模，从而较大幅度降低其时间复杂度，例如下面的代码就通过了LeetCode测试：

```cpp
class Solution // 回溯算法+记忆化搜索
{
private:
    unordered_map<int, bool> memory; // 记录某子串（起始位置为start）能否由wordSet中单词组成
    bool backTracking(string s, int start, const unordered_set<string> wordSet) {
        // 递归出口（纵向遍历）
        if (start == s.size())
            return true;
        
        // 采用记忆化搜索，利用已处理过的子问题的结果
        if (memory.find(start) != memory.end())
            return memory[start];

        // 回溯搜索（横向遍历）
        for (int end = start + 1; end <= s.size(); ++end) {
            if (wordSet.find(s.substr(start, end - start)) != wordSet.end()
                && backTracking(s, end, wordSet)) {
                memory[start] = true;
                return true;
            }
        }
        
        memory[start] = false;
        return false;
    }

public:
    bool wordBreak(string s, vector<string> & wordDict)
    {
        unordered_set<string> wordSet{wordDict.begin(), wordDict.end()}; // 存储单词的哈希表，加速查找
        return backTracking(s, 0, wordSet);
    }
};
```

这里的思路和上一个代码略有不同：上一个算法是“试图用所给单词组合出目标字符串”，该算法是“试图将所给字符串划分为目标单词”，殊途同归。

接下来采用更加优雅的算法：将问题转化为 **完全背包问题** （单词可以重复使用），且要求的是 **排列** （单词的排列顺序有影响），故按照 **先遍历背包容量、再遍历物品** 的顺序 **动态规划** 即可解决。

不过，这题似乎也没必要将问题具体化到“背包”的场景，直接从 `dp` 数组的意义入手也很好理解：

- `dp` 数组含义： `dp[j]` 表示字符串 `s` 的前 `j` 个字符组成的子串，能否由 `wordDict` 中的单词组成

- 状态转移方程（伪代码）： `dp[j] = dp[i] && s[i, j] in wordDict` 

  > 若 `s` 的前 `i` 个字符构成的子串能由 `wordDict` 中的单词组成（即 `dp[i] == true]` ），且子串 `s[i, j]` 恰好是 `wordDict` 中的某个单词，那么它俩加起来（即 `s` 的前 `j` 个字符构成的子串）也能由 `wordDict` 中的单词组成。

**代码（C++）**

```cpp
bool wordBreak(string s, vector<string> &wordDict)
{
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    unordered_set<string> wordSet{wordDict.begin(), wordDict.end()};
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j <= s.size(); ++j) {
            if (!dp[i])
             	break;
            if (wordSet.find(s.substr(i, j - i)) != wordSet.end())
                dp[j] = true;
        }
    }
    return dp[s.size()];
}
```

优雅，太优雅了。
