# 131. 分割回文串

[点此跳转题目链接](https://leetcode.cn/problems/palindrome-partitioning/description/)

## 题目描述

给你一个字符串 `s`，请你将 `s` 分割成一些子串，使每个子串都是 **回文串** 。返回 `s` 所有可能的分割方案。

>  回文串：向前和向后读都相同的字符串



**示例 1：**

```
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
```

**示例 2：**

```
输入：s = "a"
输出：[["a"]]
```

 

**提示：**

- `1 <= s.length <= 16`
- `s` 仅由小写英文字母组成



## 题解

还是经典的回溯算法，和基础的 [组合问题](https://blog.csdn.net/weixin_54468359/article/details/140668113?spm=1001.2014.3001.5501) 略有不同：

**组合问题** 是每次“将新的元素加入当前组合”，递归出口一般是“当前组合长度达到目标长度”或者其他特殊条件；本题的 **分割问题** 思路是每次“尝试在下一个位置画分割线（如果新分割截断的子串是回文的就保留）”，递归出口为“分割线位置到达字符串末尾位置”。

整体框架仍是 **回溯三部曲——处理、递归、回溯** ：

```cpp
class Solution
{
private:
    vector<string> path;
    vector<vector<string>> res;

    // 判断是否为回文串
    bool isPalindrome(const string &str)
    {
        for (int i = 0, j = str.size() - 1; i <= j; ++i, --j)
        {
            if (str[i] != str[j])
                return false;
        }
        return true;
    }

public:
    void backTracking(const string &s, int cutPos)
    {
        // 递归出口：切割点到达字符串末尾位置
        if (cutPos >= s.size())
        {
            res.push_back(path);
            return;
        }
        // 横向遍历
        for (int i = cutPos; i < s.size(); ++i)
        {
            // 处理：判断截断的子串是不是回文串
            string sub = s.substr(cutPos, i - cutPos + 1);
            if (isPalindrome(sub))
                path.push_back(sub);
            else
                continue;
            backTracking(s, i + 1); // 递归
            path.pop_back();        // 回溯
        }
    }

    vector<vector<string>> partition(string s)
    {
        backTracking(s, 0);
        return res;
    }
};
```

