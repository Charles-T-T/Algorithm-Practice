#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

示例 1：
输入：m = 3, n = 7
输出：28

示例 2：
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下

示例 3：
输入：m = 7, n = 3
输出：28

示例 4：
输入：m = 3, n = 3
输出：6
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        /**
         * 思路：
         * 动态规划，定义dp数组：
         * dp[i][j]表示走到[i][j]位置的不同路线数
         * 而走到[i][j]位置可以从它上面或左边走来
         */
        vector<vector<int>> dp(m, vector<int>(n));

        // 初始化：最上行和最左列只能直着走到（一种方法）
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        // 求其他位置的路径数
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

class Solution2 // 二刷
{
public:
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
};

int main()
{
    Solution2 obj;
    cout << obj.uniquePaths(3, 7) << endl;

    return 0;
}