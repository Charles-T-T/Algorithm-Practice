#include <iostream>
#include <vector>

using namespace std;

/*
给你一个满足下述两条属性的 m x n 整数矩阵：

每行中的整数从左到右按非严格递增顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

示例 1：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true

示例 2：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
*/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // 思路：将二分查找运用到矩阵中
        int low = 0, high = matrix.size() - 1;
        int colEnd = matrix[0].size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (matrix[mid][0] == target)
                return true;

            else if (matrix[mid][0] < target){
                if (matrix[mid][colEnd] < target){
                    // mid一整行都小于target
                    low = mid + 1;
                    continue;
                }
                else{
                    for (int j = 1; j <= colEnd; j++){
                        if (matrix[mid][j] == target)
                            return true;
                    }
                    return false;
                }
            }

            else{
                high = mid - 1;
                continue;
            }
        }

        return false;
    }
};

int main(){
    cout << "start..." << endl;
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    Solution obj;
    if (obj.searchMatrix(matrix, 13))
        cout << "True!" << endl;
    else
        cout << "False!" << endl;

    return 0;
}
