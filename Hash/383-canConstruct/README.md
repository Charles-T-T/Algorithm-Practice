# 383. 赎金信

[点此跳转题目链接](https://leetcode.cn/problems/ransom-note/)

## 题目描述

给你两个字符串：`ransomNote` 和 `magazine` ，判断 `ransomNote` 能不能由 `magazine` 里面的字符构成。

如果可以，返回 `true` ；否则返回 `false` 。

`magazine` 中的每个字符只能在 `ransomNote` 中使用一次。

 

**示例 1：**

```
输入：ransomNote = "a", magazine = "b"
输出：false
```

**示例 2：**

```
输入：ransomNote = "aa", magazine = "ab"
输出：false
```

**示例 3：**

```
输入：ransomNote = "aa", magazine = "aab"
输出：true
```

 

**提示：**

- `1 <= ransomNote.length, magazine.length <= 105`
- `ransomNote` 和 `magazine` 由小写英文字母组成



## 题解

哈希表入门题目，先用哈希表统计 `magazine` 中各字符的数量，再拿去和 `ransomNote` 中的字符对比，看够不够用即可。

**代码**

**c++**

```cpp
bool canConstruct(string ransomNote, string magazine)
{
    // 哈希表秒了
    unordered_map<char, int> charMap; // magazine 中可用的字符及其数量
    for (char c : magazine)
        charMap[c]++;
    for (char c : ransomNote) {
        if (!charMap[c])
            return false;
        charMap[c]--;
    }
    return true;
}
```

**go**

```go
func canConstruct(ransomNote string, magazine string) bool {
	charMap := make(map[rune]int)
	for _, c := range magazine {
		charMap[c]++
	}
	for _, c := range ransomNote {
		if charMap[c] == 0 {
			return false
		}
		charMap[c]--
	}
	return true
}
```

