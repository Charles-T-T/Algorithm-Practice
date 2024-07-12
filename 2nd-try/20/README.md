# 20. 有效的括号

[点此跳转题目链接](https://leetcode.cn/problems/valid-parentheses/description/)

## 题目描述

给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s` ，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。
3. 每个右括号都有一个对应的相同类型的左括号。

 

**示例 1：**

```
输入：s = "()"
输出：true
```

**示例 2：**

```
输入：s = "()[]{}"
输出：true
```

**示例 3：**

```
输入：s = "(]"
输出：false
```

 

**提示：**

- `1 <= s.length <= 104`
- `s` 仅由括号 `'()[]{}'` 组成



## 题解

一道用于理解“栈”的很好题目。思路有点像求逆波兰表达式（应该说这题是逆波兰表达式的基础）：

- 左括号无脑入栈

- 遇到右括号，检查当前栈顶是否为相应的左括号（这就检查了右括号是否顺序闭合），是就弹出左括号，否则返回false

  > 这里还要注意：先检查栈是否为空

- 其他字符不入栈

- 最后，如果栈为空，说明所有括号都配对正确，返回true；否则，返回false

**代码（C++）**

```cpp
bool isValid(string s)
{
    stack<char> st;
    for (const char &c : s){
        switch (c)
        {
        case '(':
        case '[':
        case '{':
            st.push(c);
            break;

        case ')':
            if (st.empty() || st.top() != '(')
                return false;
            else
                st.pop();
            break;

        case ']':
            if (st.empty() || st.top() != '[')
                return false;
            else
                st.pop();
            break;

        case '}':
            if (st.empty() || st.top() != '{')
                return false;
            else
                st.pop();
            break;

        default:
            break;
        }
    }
    return st.empty();
}
```

这个代码直观但是有点长，浅改一下：

```cpp
bool isValid(string s)
{
    stack<char> st;
    unordered_map<char, char> cMap = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    for (char c : s)
    {
        if (cMap.find(c) != cMap.end()) {
            if (st.empty() || st.top() != cMap[c])
                return false;
            st.pop();
        } else if (c == '(' || c == '[' || c == '{')
            st.push(c);
    }
    return st.empty();
}
```

