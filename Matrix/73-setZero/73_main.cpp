#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

示例 1：
输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]

示例 2：
输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // 思路：先找到初始状态下的零的位置，再置零
        unordered_set<int> zeroRow, zeroCol;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeroRow.insert(i), zeroCol.insert(j);
                    continue;
                }
            }
        }

        for (const int &row : zeroRow)
            fill(matrix[row].begin(), matrix[row].end(), 0);

        for (const int& col : zeroCol){
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][col] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix;
    int rowSize;
    string line, token;

    cout << "please input the num of rows: ";
    cin >> rowSize;
    cin.ignore();
    matrix.resize(rowSize);

    cout << "please input the matrix: " << endl;
    for (int i = 0; i < rowSize; i++)
    {
        cout << "row " << i << ": ";
        getline(cin, line);
        stringstream ss(line);
        while (ss >> token)
            matrix[i].push_back(stoi(token));
    }

    Solution obj;
    obj.setZeroes(matrix);

    cout << "res: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}