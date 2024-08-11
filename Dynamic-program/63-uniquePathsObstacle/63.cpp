#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。

示例 1：
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

示例 2：
输入：obstacleGrid = [[0,1],[0,0]]
输出：1
*/

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[rows - 1][cols - 1])
            return 0;
        /**
         * 思路：
         * 和普通版本类似，加一个障碍判断
         */
        vector<vector<int>> dp(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++)
        {
            if (obstacleGrid[i][0] || (i > 0 && !dp[i - 1][0]))
                dp[i][0] = 0;
            else
                dp[i][0] = 1;
        }

        for (int j = 0; j < cols; j++)
        {
            if (obstacleGrid[0][j] || (j > 0 && !dp[0][j - 1]))
                dp[0][j] = 0;
            else
                dp[0][j] = 1;
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (obstacleGrid[i][j])
                {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[rows - 1][cols - 1];
    }
};

class Solution2 // 二刷
{
public:
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
};

int main()
{
    vector<vector<int>> matrix = {
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    Solution obj;
    int res = obj.uniquePathsWithObstacles(matrix);
    cout << "res: " << res << endl;

    return 0;
}