# 459. 重复的子字符串

[点此跳转题目链接](https://leetcode.cn/problems/repeated-substring-pattern/description/)

## 题目描述

给定一个非空的字符串 `s` ，检查是否可以通过由它的一个子串重复多次构成。

 

**示例 1:**

```
输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。
```

**示例 2:**

```
输入: s = "aba"
输出: false
```

**示例 3:**

```
输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
```

 

**提示：**

- `1 <= s.length <= 104`
- `s` 由小写英文字母组成



## 题解

这题我的第一反应是：如果存在这样的子串 `sub` ，那么原字符串 `s` 的开头肯定也就是 `sub` ，所以可以从开头逐个尝试 `sub` ，期间可以根据特点**剪枝**：

- `sub` 的长度最多是 `s` 的一半（即 `s` 由两个 `sub` 拼接而成）
- `s` 的长度能整除 `sub` 

于是写出如下解法：

```cpp
bool repeatedSubstringPattern(string s)
{
    // 如果可以由一个子串重复多次构成，则该子串肯定在开头就能找到
    for (int len = 1; len <= s.size() / 2; len++) {
        if (s.size() % len != 0) // 原串长必为重复子串长的整数倍
            continue;
        string sub = s.substr(0, len);
        int start = len;
        for (start; start < s.size(); start += len) {
            string tempSub = s.substr(start, len);
            if (tempSub != sub)
                break;
        }
        if (start >= s.size())
            return true;
    }
    return false;
}
```

这样时间复杂度为 $O(n^2)$ ，较高。

一种优雅的解法如下：

```cpp
bool repeatedSubstringPatternII(string s) {
    string ts = s + s;
    ts.erase(ts.begin()), ts.erase(ts.end() - 1); // 掐头去尾
    return ts.find(s) != string::npos;
}
```

原理如下：

- 如果存在满足题目条件的子串 `sub` ，则原字符串 `s` 可以表示为 `subsub...subsub（n个sub）` 
- 那么将两个 `s` 首位相连，可以得到 `ts` ： `subsub...subsub（2n个sub）` ，显然其中又产生了新的若干 `s` 
- 将 `ts` “掐头去尾”，排除原来的那两个 `s` ：`_ubsub...subsu_` ，如果中间仍能找到 `s` ，则 `s` 可以由重复子串 `sub` 构成

上面代码中用到了 `find()` ，我们可以用自己的KMP算法替换，以进一步优化。不过这题更好的方案是利用KMP中的next数组实现：

```cpp
vector<int> getNextArr(const string &needle)
{
    vector<int> next(needle.size(), 0);
    for (int i = 0, j = 1; j < next.size(); j++)
    {
        // 不匹配：i回退
        while (i > 0 && needle[i] != needle[j])
            i = next[i - 1];
        if (needle[i] == needle[j])
            i++;
        next[j] = i;
    }
    return next;
}

bool repeatedSubstringPatter(string s)
{
    vector<int> next = getNextArr(s);
    int n = s.size();
    int len = next[n - 1];
    return len > 0 && n % (n - len) == 0;
}
```

> KMP算法及其next数组相关内容参见 [LeetCode Q28-笔记)](https://github.com/Charles-T-T/Algorithm-Practice/tree/master/String/28-strStr) 

下面推导一下这种解法的原理。

根据next数组的定义，如果 `s` 是由 $n$ 个 `sub` 重复构成的，那么它一定有长度为 $(n - 1)L_{sub}$ 的**最长相等前后缀**，而最长相等前后缀的长度就是next数组最后一个值（由next数组的定义可得）。同时
$$
L_s = nL_{sub}
$$
二者相减即得到重复子串的长度 $L_{sub}$ ，这个值自然应当能被 $L_s$ 整除。