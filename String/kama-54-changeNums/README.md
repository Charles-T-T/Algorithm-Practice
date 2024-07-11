# 卡码网 54. 替换数字

[点此跳转题目链接](https://kamacoder.com/problempage.php?pid=1064)

## 题目描述

给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。

**输入描述**

输入一个字符串 s,s 仅包含小写字母和数字字符。

**输出描述**

打印一个新的字符串，其中每个数字字符都被替换为了number

**输入示例**

```
a1b2c3
```

**输出示例**

```
anumberbnumbercnumber
```

**提示信息**

数据范围：
`1 <= s.length < 10000`



## 题解

直接写的思路很简单：开一个新字符串，遍历旧字符串的每个字符，是数字的变为"number"加到新字符串、否则直接添加到字符串。

**代码（ACM模式）**

**c++**

```cpp
#include <iostream>
#include <string>
#include <cctype>

std::string changeNum(std::string s) {
    std::string res = "";
    for (char c : s) {
        if (isdigit(c))
            res += "number";
        else
            res += c;
    }
    return res;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << changeNumCarl(s) << std::endl;

    return 0;
}
```

**go**

```go
package main

import (
	"fmt"
	"strings"
	"unicode"
)

func changeNum(s string) string {
	var builder strings.Builder
	for _, c := range(s) {
		if unicode.IsDigit(c) {
			builder.WriteString("number")	
		} else {
			builder.WriteRune(c)
		}
	}
	return builder.String()
}

func main() {
	var s string
	fmt.Scanln(&s)
	fmt.Println(changeNum(s))
}
```

但是Carl给出了一种有趣的**双指针**解法，直接在原来字符串上扩容、修改，不额外申请空间：

- 指针 `oldIndex` 指向旧字符串的**末尾**位置
- 遍历旧字符串，统计其中的数字个数
- 计算新字符串的长度并原地扩容
- 指针 `newIndex` 指向扩容后的新字符串的**末尾**位置

然后，两个指针**都从后向前**移动， `oldIndex` 指向字符不是数字就直接赋给 `newIndex` 的位置，否则 `newIndex` 填入"number"（注意是倒着填），直到 `oldIndex` 走到起始位置。扒张 [代码随想录](https://programmercarl.com/kama54.替换数字.html#思路) 上的图片便于理解：

![img](20231030173058.png)

  这种解法的代码如下

```cpp
std::string changeNumCarl(std::string s) {
    int numCount = 0;
    int oldIndex = s.size() - 1;
    for (char c : s) {
        if (isdigit(c))
            numCount++;
    }
    // "number"是6个字母，减去被替换的1个数字，需要5个额外空间
    s.resize(s.size() + 5 * numCount); 
    // 双指针：从后向前填充
    int newIndex = s.size() - 1;
    while (oldIndex >= 0) {
        if (isdigit(s[oldIndex])) {
            s[newIndex--] = 'r';
            s[newIndex--] = 'e';
            s[newIndex--] = 'b';
            s[newIndex--] = 'm';
            s[newIndex--] = 'u';
            s[newIndex--] = 'n';
        } else 
            s[newIndex--] = s[oldIndex];
        oldIndex--;
    }
    return s;
}
```

