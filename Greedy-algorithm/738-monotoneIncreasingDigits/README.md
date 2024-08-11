# 738. 单调递增的数字

[点此跳转题目链接](https://leetcode.cn/problems/monotone-increasing-digits/description/)

## 题目描述

当且仅当每个相邻位数上的数字 `x` 和 `y` 满足 `x <= y` 时，我们称这个整数是**单调递增**的。

给定一个整数 `n` ，返回 *小于或等于 `n` 的最大数字，且数字呈 **单调递增*** 。

 

**示例 1:**

```
输入: n = 10
输出: 9
```

**示例 2:**

```
输入: n = 1234
输出: 1234
```

**示例 3:**

```
输入: n = 332
输出: 299
```

 

**提示:**

- `0 <= n <= 109`



## 题解

贪心算法解决。结合所给示例，我们不难想出将 `n` 转化为单调递增数的一个简单思路：从最低位开始，如果当前位（第 `i` 位）数字比上一位（第 `i + 1` 位）数字小，即满足单调递增，则数字不变；否则，第 `i` 位数字减一、之前各位数字变为9。

> 例如：332 :arrow_right: 329 :arrow_right: 299

因此，我们可以这样将数字从后往前“扫一遍”，记录最后要将数字变为9的起始位置，之后将它们都变为9即可。

**代码（C++）**

```cpp
int monotoneIncreasingDigits(int n)
{
    string strN = to_string(n);
    // 从后往前逐位确定
    int flag = strN.size(); // 结果末尾连续9的起始位
    for (int i = strN.size() - 1; i > 0; --i) {
        if (strN[i - 1] > strN[i]) {
            strN[i - 1]--;
            flag = i;
        }
    }
    for (int i = flag; i < strN.size(); ++i)
        strN[i] = '9';
    return stoi(strN);
}
```

