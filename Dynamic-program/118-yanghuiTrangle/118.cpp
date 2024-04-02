#include <iostream>
#include <vector>

using namespace std;

/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例 1:
输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

示例 2:
输入: numRows = 1
输出: [[1]]
*/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        /**
         * 动态规划（把杨辉三角以直角三角形方式摆放好理解）
         * dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
         * 注意初始化：每层起始位置都是1
        */
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++)
        {
            res[i].resize(i + 1);
            res[i][0] = res[i][i] = 1;
            for (int j = 1; j < i; j++)
                res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
        }
        return res;
    }
};