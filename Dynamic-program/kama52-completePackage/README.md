# 卡码网52. 携带研究材料

[点此跳转题目链接](https://kamacoder.com/problempage.php?pid=1052)

## 题目描述

小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。他需要带一些研究材料，但是他的行李箱空间有限。这些研究材料包括实验设备、文献资料和实验样本等等，它们各自占据不同的重量，并且具有不同的价值。

小明的行李箱所能承担的总重量为 N，问小明应该如何抉择，才能携带最大价值的研究材料，每种研究材料可以选择无数次，并且可以重复选择。

输入描述

第一行包含两个整数，N，V，分别表示研究材料的种类和行李空间 

接下来包含 N 行，每行两个整数 wi 和 vi，代表第 i 种研究材料的重量和价值

输出描述

输出一个整数，表示最大价值。

**输入示例**

```
4 5
1 2
2 4
3 4
4 5
```

**输出示例**

```
10
```

> 提示信息：第一种材料选择五次，可以达到最大值。

**数据范围：**

- `1 <= N <= 10000`

- `1 <= V <= 10000`

- `1 <= wi, vi <= 10^9`



## 题解

典型的 **完全背包问题** （每个物品都可以无限次选择在）， **动态规划** 解决。

- `dp` 数组含义： `dp[j]` 表示容量为 `j` 的背包能装的最大价值
- 状态转移方程： `dp[j] = max(dp[j], dp[j - weights[i]] + values[i])` （经典款）

:warning: 和**01背包问题**不同，处理**完全背包问题**时，**遍历容量**需要 **从小到大** ，这样相当于每次都会考虑重复使用之前用过的物品的情况（当前容量为 `j` 的情况，之后在容量为 `j + k` 的时候，可能用到，实现物品的“不限次数选择”）。

> 关于完全背包问题和本题算法的更详细解析，参见 [代码随想录-完全背包理论基础](https://programmercarl.com/背包问题理论基础完全背包.html#思路) 

**代码（C++）**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int kinds, bagSize;
    cin >> kinds >> bagSize;
    vector<int> weights(kinds), values(kinds);
    for (int i = 0; i < kinds; ++i)
        cin >> weights[i] >> values[i];

    vector<int> dp(bagSize + 1, 0);
    for (int i = 0; i < kinds; ++i) {
        for (int j = weights[i]; j <= bagSize; ++j)
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
    }
    cout << dp[bagSize] << endl;

    return 0;
}
```

