#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n));
        int curLayer = 0;   // 当前正在处理的层号，从外到内计数
        int curSideLen = n; // 当前在处理的这层正方形的边长
        int curNum = 1;     // 当前要填入矩阵的数字

        // 一层层处理，每层的边采用“左闭右开”的原则
        while (curSideLen > 0)
        {
            // 处理上边
            for (int j = curLayer; j < curLayer + curSideLen - 1; j++)
                res[curLayer][j] = curNum++;
            // 处理右边
            for (int i = curLayer; i < curLayer + curSideLen - 1; i++)
                res[i][curLayer + curSideLen - 1] = curNum++;
            // 处理下边
            for (int j = curLayer + curSideLen - 1; j > curLayer; j--)
                res[curLayer + curSideLen - 1][j] = curNum++;
            // 处理左边
            for (int i = curLayer + curSideLen - 1; i > curLayer; i--)
                res[i][curLayer] = curNum++;

            curLayer++;
            curSideLen -= 2;
        }

        // 如果是奇数阶矩阵，还要填中心元素
        if (n % 2 == 1)
            res[n / 2][n / 2] = n * n;

        return res;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> nums = obj.generateMatrix(3);

    cout << "end" << endl;
    return 0;
}