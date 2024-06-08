#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]

示例 2：
输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int layers; // 需要旋转的层数
        int n = matrix.size();
        if (n % 2 == 0)
            layers = n / 2;
        else
            layers =n / 2 + 1;
        
        deque<int> helper;
        for (int i = 0, len = n; i < layers; i++, len-=2) {
            // 存上边
            for (int j = i, count = 0; count < len; j++, count++) {
                helper.push_back(matrix[i][j]);
            }

            // 存右边，右边变上边
            for (int j = i, count = 0; count < len; j++, count++) {
                if (j == i)
                    helper.push_back(helper.back());
                else
                    helper.push_back(matrix[j][n - i - 1]);
                matrix[j][n - i - 1] = helper.front();
                helper.pop_front();
            }
            
            // 存下边，下边变右边
            for (int j = n - 1 - i, count = 0; count < len; j--, count++) {
                if (j == n - 1- i)
                    helper.push_back(helper.back());
                else
                    helper.push_back(matrix[n - 1 - i][j]);
                matrix[n - 1 - i][j] = helper.front();
                helper.pop_front();
            }

            // 存左边，左边变下边
            for (int j = n - i - 1, count = 0; count < len; j--, count++) {
                if (j == n - i - 1)
                    helper.push_back(helper.back());
                else
                    helper.push_back(matrix[j][i]);
                matrix[j][i] = helper.front();
                helper.pop_front();
            }

            // 上边变下边
            for (int j = i, count = 0; count < len; j++, count++) {
                matrix[i][j] = helper.front();
                helper.pop_front();
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}, 
        {7, 8, 9}
    };
    Solution obj;
    obj.rotate(matrix);

    return 0;
}