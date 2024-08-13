# 卡码网46. 携带研究材料

[点此跳转题目链接](https://kamacoder.com/problempage.php?pid=1046)

## 题目描述

小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。他需要带一些研究材料，但是他的行李箱空间有限。这些研究材料包括实验设备、文献资料和实验样本等等，它们各自占据不同的空间，并且具有不同的价值。 

小明的行李空间为 `N`，问小明应该如何抉择，才能携带最大价值的研究材料，每种研究材料只能选择一次，并且只有选与不选两种选择，不能进行切割。

**输入描述**

第一行包含两个正整数，第一个整数 `M` 代表研究材料的种类，第二个正整数 `N` ，代表小明的行李空间。

第二行包含 `M` 个正整数，代表每种研究材料的所占空间。 

第三行包含 `M` 个正整数，代表每种研究材料的价值。

**输出描述**

输出一个整数，代表小明能够携带的研究材料的最大价值。

输入示例

```
6 1
2 2 3 1 5 2
2 3 1 5 4 3
```

**输出示例**

```
5
```

**提示信息**

小明能够携带 6 种研究材料，但是行李空间只有 1，而占用空间为 1 的研究材料价值为 5，所以最终答案输出 5。 

**数据范围：**
`1 <= N <= 5000`
`1 <= M <= 5000`
研究材料占用空间和价值都小于等于 1000



## 题解

标准的 **01背包问题** ，动态规划解决。

> :bulb: 01背包基础参考：[代码随想录-01背包理论基础](https://programmercarl.com/背包理论基础01背包-1.html#算法公开课)

- `dp` 数组含义： `dp[i][j]` 表示从下标 `0` 到 `i` 的物品中选择，放入容量为 `j` 的背包中，所能达到的最大价值
- 状态转移方程：
  - 如果当前物品的重量/所占空间 `weights[i]` 大于当前背包容量 `j` ，则不放入，即 `dp[i][j] = dp[i - 1][j]` 
  - 否则，比较放入物品 `i` （可能需要拿出其他物品腾空间）和不放入 `i` 哪个价值更高，即 `dp[i][j] = max(dp[i - 1][j], dp[i - i][j - weights[i]] + values[i])`

**代码（C++）**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<int> weights(m), values(m);
    for (int i = 0; i < m; ++i)
        std::cin >> weights[i];
    for (int i = 0; i < m; ++i)
        std::cin >> values[i];

    std::vector<std::vector<int>> dp(m, std::vector<int>(n + 1, 0));
    for (int j = weights[0]; j <= n; ++j)
        dp[0][j] = values[0];
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (weights[i] > j)
                dp[i][j] = dp[i - 1][j];
             else 
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
        }
    }
    std::cout << dp[m - 1][n] << std::endl;

    return 0;
}
```

或者也可以将 `dp` 数组改为滚动数组，实现数组降维，减小空间开销（参考：[代码随想录](https://programmercarl.com/背包理论基础01背包-2.html#算法公开课) )

```cpp
// 一维dp
std::vector<int> dp(n + 1);
for (int j = weights[0]; j <= n; ++j)
    dp[j] = values[0];
for (int i = 1; i < weights.size(); ++i) {
    for (int j = n; j >= weights[i]; --j) 
        dp[j] = std::max(dp[j], dp[j - weights[i]] + values[i]);
}
std::cout << dp[n] << std::endl;
```

