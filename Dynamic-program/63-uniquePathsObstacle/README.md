# 63. 不同路径 II

[点此跳转题目链接](https://leetcode.cn/problems/unique-paths-ii/description/)

## 题目描述

一个机器人位于一个 `m x n` 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 `1` 和 `0` 来表示。

 

**示例 1：**

![img](./robot1.jpg)

```
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
```

**示例 2：**

![img](./robot2.jpg)

```
输入：obstacleGrid = [[0,1],[0,0]]
输出：1
```

 

**提示：**

- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` 为 `0` 或 `1`



## 题解

这题和 [62. 不同路径](https://leetcode.cn/problems/unique-paths/) 基本一样，只是加了一个障碍物而已，同样地采用动态规划解决，只需要在求 `dp` 数组时，遇到障碍物直接将那一格的到达路径数置为0即可。

-  `dp` 数组含义： `dp[i][j]` 表示达到位置 $(i, \enspace j)$ 的路径数量
- 初始化：起点为 $(0, \enspace 0)$ ，显然只有唯一方法到达起点，即 `dp[0][0] = 1` （除非有障碍物，也要置0）
- 状态转移方程：
  - 障碍物情况：有障碍物（ `obstacleGrid[i][j] == 1` ）的格子必然无法到达（注意这个要首先判断），即 `dp[i][j] = 0` 
  - 边界情况
    - 如果是上边界，要到达 $(i, \enspace j)$ 显然只能通过左边的格子向右走一步到达，即 `dp[i][j] = dp[i][j - 1]` 
    - 如果是左边界，要到达 $(i, \enspace j)$ 显然只能通过上面的格子向下走一步到达，即 `dp[i][j] = dp[i - 1][j]` 
  - 其余情况，上面两种方法都可以到达，即 `dp[i][j] = dp[i][j - 1] + dp[i - 1][j]` 

**代码（C++）**

```cpp
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
    for (int i = 0; i < dp.size(); ++i)
    {
        for (int j = 0; j < dp[0].size(); ++j)
        {
            if (obstacleGrid[i][j])      // 有障碍物：无法到达
                dp[i][j] = 0;         
            else if (i == 0 && j == 0)   // 起点
                dp[i][j] = 1;
            else if (i == 0)             // 上边界：只能从左边来
                dp[i][j] = dp[i][j - 1]; 
            else if (j == 0)             // 左边界：只能从上面来
                dp[i][j] = dp[i - 1][j]; 
            else                         // 其余情况：从左边或上面来
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    return dp[dp.size() - 1][dp[0].size() - 1];
}
```

