# 卡码网 55. 右旋字符串

[点此跳转题目链接](https://kamacoder.com/problempage.php?pid=1065)

## 题目描述

字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。给定一个字符串 s 和一个正整数 k，请编写一个函数，将字符串中的后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。 

例如，对于输入字符串 "abcdefg" 和整数 2，函数应该将其转换为 "fgabcde"。

**输入描述**

输入共包含两行，第一行为一个正整数 k，代表右旋转的位数。第二行为字符串 s，代表需要旋转的字符串。

**输出描述**

输出共一行，为进行了右旋转操作后的字符串。

**输入示例**

```
2
abcdefg
```

输出示例

```
fgabcde
```

**提示信息**

数据范围：
`1 <= k < 10000`
`1 <= s.length < 10000`



## 题解

两种基本算法，第一种是暴力解决：开一个新字符串，然后按照题目要求截取原字符串的两部分、添加到新字符串中即可：
```cpp
 std::string rightSpanStr(std::string s, int k) {
    std::string front = s.substr(s.size() - k, k);
    std::string back = s.substr(0, s.size() - k);
    return front + back;
}
```

第二种要优雅一点，可以原地实现：先将字符串整体反转，在按照题目要求反转其中的两个部分：

```cpp
void rightSpanLocal(std::string &s, int k) {
    std::reverse(s.begin(), s.end());
    std::reverse(s.begin(), s.begin() + k);
    std::reverse(s.begin() + k, s.end());
}
```

> 类似题目中，这种“先反转整体，再反转局部”的思想还蛮常见的。