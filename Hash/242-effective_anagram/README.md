# 242. 有效的字母异位词

## 题目描述

给定两个字符串 `s` 和 `t` ，编写一个函数来判断 `t` 是否是 `s` 的字母异位词。

**注意：**若 `s` 和 `t` 中每个字符出现的次数都相同，则称 `s` 和 `t` 互为字母异位词。

 

**示例 1:**

```
输入: s = "anagram", t = "nagaram"
输出: true
```

**示例 2:**

```
输入: s = "rat", t = "car"
输出: false
```

 

**提示:**

- `1 <= s.length, t.length <= 5 * 104`
- `s` 和 `t` 仅包含小写字母

 

**进阶:** 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？



## 题解

利用哈希表，先将其中两个字符串中的字符及其对应出现次数记录下来，逐个比较：

```cpp
bool isAnagram(string s, string t)
{
    if (s.length() != t.length()) // 不等长肯定不是字母异位词
        return false;
    unordered_map<char, int> sMap, tMap;
    for (int i = 0; i < s.length(); i++)
        sMap[s[i]]++, tMap[t[i]]++;
    for (auto pair : sMap) {
        if (pair.second != tMap[pair.first])
            return false;
    }
    return true;
}
```

有关哈希表基础可参见 [代码随想录 (programmercarl.com)](https://programmercarl.com/哈希表理论基础.html) 。

不过这题有个神奇解法：既然都是字符串，直接按字典序重排一遍，在比较重排后的字符串即可 :laughing: 

```cpp
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
	return s == t;
}
```

> 优雅，太优雅了 :dog: 