# 卡码网57. 爬楼梯

[点此跳转题目链接](https://kamacoder.com/problempage.php?pid=1067)

## 题目描述

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 

每次你可以爬至多m (1 <= m < n)个台阶。你有多少种不同的方法可以爬到楼顶呢？ 

注意：给定 n 是一个正整数。

**输入描述**

输入共一行，包含两个正整数，分别表示n, m

**输出描述**

输出一个整数，表示爬到楼顶的方法数。

**输入示例**

```
3 2
```

**输出示例**

```
3
```

**提示信息**

```
数据范围：
1 <= m < n <= 32;

当 m = 2，n = 3 时，n = 3 这表示一共有三个台阶，m = 2 代表你每次可以爬一个台阶或者两个台阶。

此时你有三种方法可以爬到楼顶。

1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
```



## 题解

典型的 **完全背包求排列** 问题，经典的**动态规划**解决。由于很基础，具体算法需要的可以直接看 [代码随想录](https://programmercarl.com/0070.爬楼梯完全背包版本.html#思路) 。

**代码（C++）**

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= m; ++i) {
            if (j >= i)
                dp[j] += dp[j - i];
        }
    }
    cout << dp[n] << endl;
    return 0;
}
```
