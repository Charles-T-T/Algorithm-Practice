#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����

������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish������

���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����

�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��

ʾ�� 1��
���룺obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
�����2
���ͣ�3x3 ��������м���һ���ϰ��
�����Ͻǵ����½�һ���� 2 ����ͬ��·����
1. ���� -> ���� -> ���� -> ����
2. ���� -> ���� -> ���� -> ����

ʾ�� 2��
���룺obstacleGrid = [[0,1],[0,0]]
�����1
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
         * ˼·��
         * ����ͨ�汾���ƣ���һ���ϰ��ж�
        */
        vector<vector<int>> dp(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++){
            if (obstacleGrid[i][0] || (i > 0 && !dp[i - 1][0]))
                dp[i][0] = 0;
            else
                dp[i][0] = 1;
        }
            
        for (int j = 0; j < cols; j++){
            if (obstacleGrid[0][j] || (j > 0 && !dp[0][j - 1]))
                dp[0][j] = 0;
            else
                dp[0][j] = 1;
        }

        for (int i = 1; i < rows; i++){
            for (int j = 1; j < cols; j++){
                if (obstacleGrid[i][j]){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[rows - 1][cols - 1];
    }
};

int main(){
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