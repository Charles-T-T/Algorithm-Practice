# 28. 找出字符串中第一个匹配项的下标

[点此跳转题目链接](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

## 题目描述

给你两个字符串 `haystack` 和 `needle` ，请你在 `haystack` 字符串中找出 `needle` 字符串的第一个匹配项的下标（下标从 0 开始）。如果 `needle` 不是 `haystack` 的一部分，则返回 `-1` 。

 

**示例 1：**

```
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
```

**示例 2：**

```
输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
```

 

**提示：**

- `1 <= haystack.length, needle.length <= 104`
- `haystack` 和 `needle` 仅由小写英文字符组成



## 题解

> $\mathbf{KMP}$ ，启动！

这题暴力解法没什么说的，两重循环遍历即可，时间复杂度为 $O(mn)$ ，其中 $m$ 为文本串 `haystack` 的长度， $n$ 为模式串 `needle` 的长度。

于是我们采用大名鼎鼎的**KMP算法**解决，该算法完全讲清楚有一定难度，但网上讲解浩如烟海，故不在此解析，无基础的推荐看

- 文章：[代码随想录-KMP](https://programmercarl.com/0028.实现strStr.html#算法公开课) 
- 视频 [帮你把KMP算法学个通透！（理论篇）b站](https://www.bilibili.com/video/BV1PD4y1o7nd/?vd_source=5e14dbd66e0ae4ee0bdf1614f9285a5f) & [帮你把KMP算法学个通透！（求next数组代码篇）b站](https://www.bilibili.com/video/BV1M5411j7Xx/?vd_source=5e14dbd66e0ae4ee0bdf1614f9285a5f) 

- 当初数据结构期末看了这位老师的 [【拯救者】Ep_串(下)-KMP算法-b站](https://www.bilibili.com/video/BV1z84y1z7Vp?p=17&vd_source=5e14dbd66e0ae4ee0bdf1614f9285a5f) ，也很受用

**代码（C++）**

```cpp
vector<int> getNextArr(const string &needle) {
    vector<int> next(needle.size(), 0);
    for (int i = 0, j = 1; j < next.size(); j++) {
        while (i > 0 && needle[i] != needle[j]) // 不匹配：i回退
            i = next[i - 1];
        if (needle[i] == needle[j])
            i++;
        next[j] = i;
    }
    return next;
}

int strStr(string haystack, string needle)
{
    vector<int> next = getNextArr(needle);
    for (int i = 0, j = 0; i < haystack.size(); i++) {
        while (j > 0 && haystack[i] != needle[j]) 
            j = next[j - 1];
        if (haystack[i] == needle[j]) 
            j++;
        if (j == needle.size())
            return i - needle.size() + 1;
    }
    return -1;
}
```

