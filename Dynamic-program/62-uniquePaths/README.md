# 62. 不同路径

[点此跳转题目链接](https://leetcode.cn/problems/unique-paths/description/)

## 题目描述

一个机器人位于一个 `m x n` 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

 

**示例 1：**

![img](./1697422740-adxmsI-image.png)

```
输入：m = 3, n = 7
输出：28
```

**示例 2：**

```
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
```

**示例 3：**

```
输入：m = 7, n = 3
输出：28
```

**示例 4：**

```
输入：m = 3, n = 3
输出：6
```

 

**提示：**

- `1 <= m, n <= 100`
- 题目数据保证答案小于等于 `2 * 109`



## 题解

贪心算法解决，注意 **“每次只能向下或向右移动一步”** ，这就给我们提供了重叠子问题和最优子结构的基础。

-  `dp` 数组含义： `dp[i][j]` 表示达到位置 $(i, \enspace j)$ 的路径数量
- 初始化：起点为 $(0, \enspace 0)$ ，显然只有唯一方法到达起点，即 `dp[0][0] = 1` 
- 状态转移方程：
  - 边界情况
    - 如果是上边界，要到达 $(i, \enspace j)$ 显然只能通过左边的格子向右走一步到达，即 `dp[i][j] = dp[i][j - 1]` 
    - 如果是左边界，要到达 $(i, \enspace j)$ 显然只能通过上面的格子向下走一步到达，即 `dp[i][j] = dp[i - 1][j]` 
  - 其余情况，上面两种方法都可以到达，即 `dp[i][j] = dp[i][j - 1] + dp[i - 1][j]` 

**代码（C++）**

```cpp
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0) // 起点
                dp[i][j] = 1;
            else if (i == 0)             // 上边界：只能从左边来
                dp[i][j] = dp[i][j - 1]; 
            else if (j == 0)             // 左边界：只能从上面来
                dp[i][j] = dp[i - 1][j]; 
            else                         // 其余情况：从左边或上面来
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    return dp[m - 1][n - 1];
}
```
