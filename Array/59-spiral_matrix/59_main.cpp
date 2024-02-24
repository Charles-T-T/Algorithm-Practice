#include <iostream>
#include <vector>

using namespace std;

/*
给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

示例 1：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]

示例 2：
输入：n = 1
输出：[[1]]
*/

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int len = n - 1; // 四个方向上（最初）每次走的长度
        int loopTime = n / 2 + 1; // 总循环次数
        int num = 1; // 填入矩阵的数字
        int start = 0;
        vector<vector<int>> res(n, vector<int>(n));

        for (int loopCount = 0; loopCount < loopTime; loopCount++){
            // 处理n为奇数时的最后一个中心数字
            if (loopCount == loopTime - 1 && n % 2 != 0)
            {
                res[loopCount][loopCount] = n * n;
                break;
            }
            
            for (int i = start, j = 0; j < len; i++, j++, num++) // 上行
                res[loopCount][i] = num;

            for (int i = start, j = 0; j < len; i++, j++, num++) // 右列
                res[i][n - loopCount - 1] = num;

            for (int i = n - start - 1, j = 0; j < len; i--, j++, num++) // 下行
                res[n - loopCount - 1][i] = num;

            for (int i = n - start - 1, j = 0; j < len; i--, j++, num++) // 左列
                res[i][loopCount] = num;

            len -= 2;
            start++;
        }

        return res;
    }
};


int main(){
    int n;
    cout << "please input the n: ";
    cin >> n;

    vector<vector<int>> res;
    Solution obj;
    res = obj.generateMatrix(n);
    cout << "get the matrix:" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < res[0].size(); j++) 
        {
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
