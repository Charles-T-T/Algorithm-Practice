#include <iostream>
#include <vector>

using namespace std;

/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

示例 2：
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
*/

class Solution
{
public:
    bool inArea(const vector<vector<char>> &grid, int i, int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return false;
        else
            return true;
    }

    int visit(vector<vector<char>> &grid, int i, int j){
        // 当访问到一片陆地时，返回非0值；否则返回0
        if (!inArea(grid, i, j))
            return 0;
        
        if (grid[i][j] != '1') // 为水域或已访问过的陆地
            return 0;
        else{
            grid[i][j] = '2';
            return 1 + visit(grid, i - 1, j) + visit(grid, i + 1, j) + visit(grid, i, j - 1) + visit(grid, i, j + 1);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        /**
         * 思路：网格中的DFS解决（递归写法）
         * 对于grid[i][j]的值，
         * 0：水域
         * 1：陆地（未访问）
         * 2：陆地（已访问）
         * 边界判断：越界时即使返回
        */
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++){
                if (visit(grid, i, j))
                    res++;
            }
        }

        return res;
    }
};