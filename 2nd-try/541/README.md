# 541. 反转字符串 II

[点此跳转题目链接](https://leetcode.cn/problems/reverse-string-ii/description/)

## 题目描述

给定一个字符串 `s` 和一个整数 `k`，从字符串开头算起，每计数至 `2k` 个字符，就反转这 `2k` 字符中的前 `k` 个字符。

- 如果剩余字符少于 `k` 个，则将剩余字符全部反转。
- 如果剩余字符小于 `2k` 但大于或等于 `k` 个，则反转前 `k` 个字符，其余字符保持原样。

 

**示例 1：**

```
输入：s = "abcdefg", k = 2
输出："bacdfeg"
```

**示例 2：**

```
输入：s = "abcd", k = 2
输出："bacd"
```

 

**提示：**

- `1 <= s.length <= 104`
- `s` 仅由小写英文组成
- `1 <= k <= 104`



## 题解

蛮有意思的一个题目，初看用双指针可以解决——一个指针负责2k的位置，另一个负责k的位置。但是进一步思考可以发现，记某次计数后，剩余字符数量为 $s$ 题目给出的 :three: 种情况

- $s \ge 2k$
- $k \le s < 2k$
- $s < k$

其实可以化为 :two: 种：

- $s \ge k$ ，就反转前 $k$ 个
- 否则，把剩余的 $s$ 个都反转了

所以其实只需要一个指针即可，每次判断指针后面够不够 $k$ 个字符：够的话，就把它们反转，然后前进 $2k$ 个字符；否则，把后面的字符都反转，然后返回结果。

**代码**

**c++**

```cpp
string reverseStr(string s, int k)
{
    for (int i = 0; i < s.length(); i += 2 * k) {
        if (s.length() - i >= k) // 后面剩的够k个就反转k个
            reverse(s.begin() + i, s.begin() + i + k);
        else // 否则把剩的全部反转
            reverse(s.begin() + i, s.end());
    }
    return s;
}
```

**go**

```go
func reverse(s string, begin int, end int) string {
	r := []rune(s)
	for i, j := begin, end-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	s = string(r)
	return s
}

func reverseStr(s string, k int) string {
	for i := 0; i < len(s); i += 2 * k {
		if len(s)-i >= k {
			s = reverse(s, i, i+k)
		} else {
			s = reverse(s, i, len(s))
		}
	}
	return s
}
```

