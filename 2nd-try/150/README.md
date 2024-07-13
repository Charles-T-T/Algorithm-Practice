# 150. 逆波兰表达式求值

[点此跳转题目链接](https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/)

## 题目描述

给你一个字符串数组 `tokens` ，表示一个根据 [逆波兰表示法](https://baike.baidu.com/item/逆波兰式/128437) 表示的算术表达式。

请你计算该表达式。返回一个表示表达式值的整数。

**注意：**

- 有效的算符为 `'+'`、`'-'`、`'*'` 和 `'/'` 。
- 每个操作数（运算对象）都可以是一个整数或者另一个表达式。
- 两个整数之间的除法总是 **向零截断** 。
- 表达式中不含除零运算。
- 输入是一个根据逆波兰表示法表示的算术表达式。
- 答案及所有中间计算结果可以用 **32 位** 整数表示。

 

**示例 1：**

```
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
```

**示例 2：**

```
输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
```

**示例 3：**

```
输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

 

**提示：**

- `1 <= tokens.length <= 104`
- `tokens[i]` 是一个算符（`"+"`、`"-"`、`"*"` 或 `"/"`），或是在范围 `[-200, 200]` 内的一个整数



## 题解

栈的经典题目 :sparkles: 

由于逆波兰表达式的特点，每个运算符总是要处理其前面的两个操作数。因此，可以采用栈存储表达式中的操作数，当遇到运算符时就弹出栈顶两个元素、进行运算，并把结果入栈。最后，这般处理完整个表达式，栈中剩余的唯一元素就是计算结果。

**代码（C++）**

```cpp
int evalRPN(vector<string> &tokens)
{
    stack<int> numSt; // 存储数字的栈
    for (const string &token : tokens) { 
        if (token == "+") {
            int num1 = numSt.top();
            numSt.pop();
            int num2 = numSt.top();
            numSt.pop();
            numSt.push(num1 + num2);
        } else if (token == "-") {
            int num1 = numSt.top();
            numSt.pop();
            int num2 = numSt.top();
            numSt.pop();
            numSt.push(num2 - num1);
        } else if (token == "*") {
            int num1 = numSt.top();
            numSt.pop();
            int num2 = numSt.top();
            numSt.pop();
            numSt.push(num1 * num2);
        } else if (token == "/") {
            int num1 = numSt.top();
            numSt.pop();
            int num2 = numSt.top();
            numSt.pop();
            numSt.push(num2 / num1);
        } else 
            numSt.push(stoi(token)); // 数字无脑入栈即可
    }
    return numSt.top();
}
```

