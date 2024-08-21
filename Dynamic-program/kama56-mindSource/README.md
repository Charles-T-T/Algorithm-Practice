# 卡码网56. 携带矿石资源

[点此跳转题目链接](https://kamacoder.com/problempage.php?pid=1066)

## 题目描述

你是一名宇航员，即将前往一个遥远的行星。在这个行星上，有许多不同类型的矿石资源，每种矿石都有不同的重要性和价值。你需要选择哪些矿石带回地球，但你的宇航舱有一定的容量限制。 

给定一个宇航舱，最大容量为 `C` 。现在有 `N` 种不同类型的矿石，每种矿石有一个重量 `w[i]` ，一个价值 `v[i]` ，以及最多 `k[i]` 个可用。不同类型的矿石在地球上的市场价值不同。你需要计算如何在不超过宇航舱容量的情况下，最大化你所能获取的总价值。



**输入描述**

输入共包括四行，第一行包含两个整数 `C` 和 `N` ，分别表示宇航舱的容量和矿石的种类数量。 

接下来的三行，每行包含 `N` 个正整数。具体如下： 

第二行包含 `N` 个整数，表示 `N` 种矿石的重量。 

第三行包含 `N` 个整数，表示 `N` 种矿石的价格。 

第四行包含 `N` 个整数，表示 `N` 种矿石的可用数量上限。

**输出描述**

输出一个整数，代表获取的最大价值。

**输入示例**

```
10 3
1 3 4
15 20 30
2 3 2
```

**输出示例**

```
90
```

**提示信息**

数据范围：
`1 <= C <= 10000`
`1 <= N <= 10000`
`1 <= w[i], v[i], k[i] <= 10000`



## 题解

典型的 **多重背包问题** ：每个物品的可使用次数有限但可能不止一次。

按照传统的01背包问题框架，加一个遍历每个物品的使用次数的循环即可。更详细的解析参见 [代码随想录-多重背包](https://programmercarl.com/背包问题理论基础多重背包.html#多重背包) 。

**代码（C++）**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int c, n;
    cin >> c >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i)
        cin >> weights[i];
    
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
        cin >> values[i];
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<int> dp(c + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = c; j >= weights[i]; --j) {
            for (int k = 1; k <= nums[i] && j >= k * weights[i]; ++k) 
                dp[j] = max(dp[j], dp[j - k * weights[i]] + k * values[i]);
        }
    }        
    
    cout << dp[c] << endl;
    return 0;
}
```

