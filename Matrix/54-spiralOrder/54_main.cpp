#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // 思路：四个方向上一步步走，注意边界条件的判断
        vector<int> resVec;
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        int i, j;

        // 空矩阵情况
        if (!matrix.size())
            return resVec;

        while (top <= bottom && left <= right)
        {
            for (j = left, i = top; j <= right; j++)
                resVec.push_back(matrix[i][j]);
            if (top == bottom) // 检查是否为最后一行
                return resVec;

            for (i = top + 1, j = right; i <= bottom; i++)
                resVec.push_back(matrix[i][j]);
            if (left == right) // 检查是否为最后一列
                return resVec;

            for (j = right - 1, i = bottom; j > left; j--)
                resVec.push_back(matrix[i][j]);

            for (i = bottom, j = left; i > top; i--)
                resVec.push_back(matrix[i][j]);

            top++, bottom--;
            left++, right--;
        }

        return resVec;
    }
};

int main()
{
    int rowCount;
    cout << "please input the row count of matrix: ";
    cin >> rowCount;
    cin.ignore();
    vector<vector<int>> matrix(rowCount);
    cout << "please input the matrix: " << endl;
    string line, token;
    for (int i = 0; i < rowCount; i++)
    {
        getline(cin, line);
        stringstream ss(line);
        while (ss >> token)
            matrix[i].push_back(stoi(token));
    }

    Solution obj;
    vector<int> resVec = obj.spiralOrder(matrix);
    cout << "res: ";
    for (const int &num : resVec)
        cout << num << ' ';

    return 0;
}

/*
1 11
2 12
3 13
4 14
5 15
6 16
7 17
8 18
9 19
10 20
*/