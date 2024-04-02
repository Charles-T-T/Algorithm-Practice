#include <iostream>
#include <vector>

using namespace std;

/*
����һ���Ǹ����� numRows�����ɡ�������ǡ���ǰ numRows �С�

�ڡ�������ǡ��У�ÿ�����������Ϸ������Ϸ������ĺ͡�

ʾ�� 1:
����: numRows = 5
���: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

ʾ�� 2:
����: numRows = 1
���: [[1]]
*/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        /**
         * ��̬�滮�������������ֱ�������η�ʽ�ڷź���⣩
         * dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
         * ע���ʼ����ÿ����ʼλ�ö���1
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