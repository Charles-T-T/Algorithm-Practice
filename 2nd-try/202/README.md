# 202. 快乐数

[点此跳转题目链接](https://leetcode.cn/problems/happy-number/description/)

## 题目描述

编写一个算法来判断一个数 `n` 是不是快乐数。

**「快乐数」** 定义为：

- 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
- 然后重复这个过程直到这个数变为 1，也可能是 **无限循环** 但始终变不到 1。
- 如果这个过程 **结果为** 1，那么这个数就是快乐数。

如果 `n` 是 *快乐数* 就返回 `true` ；不是，则返回 `false` 。

 

**示例 1：**

```
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

**示例 2：**

```
输入：n = 2
输出：false
```

 

**提示：**

- `1 <= n <= 231 - 1`



## 题解

蛮有趣的一道题目，乍一看一定会想到用**递归**，然后哐哐写完发现陷入死循环，因为题目指出：有可能**无限循环**处理而始终变不到1。所以我们还需要一个**集合**存储已经检验过的数字，这样遇到重复时就可以判断它不是快乐数。

**代码（C++）**

```cpp
class Solution
{
private:
    unordered_set<int> numSet; // 已经尝试过的数字

public:
    bool isHappy(int n)
    {
        // 递归
        int sum = 0;
        int nCopy = n;
        while (nCopy) {
            int temp = nCopy % 10;
            sum += pow(temp, 2);
            nCopy = (nCopy - temp) / 10;
        }
        if (sum == 1)
            return true;
        if (numSet.find(n) != numSet.end())
            return false;
        numSet.insert(n); // 防止陷入死循环
        return isHappy(sum);
    }
};
```

