#include <iostream>
#include <vector>

using namespace std;

/*
����һ�����������������Ե� m x n ��������

ÿ���е����������Ұ����ϸ����˳�����С�
ÿ�еĵ�һ����������ǰһ�е����һ��������
����һ������ target ����� target �ھ����У����� true �����򣬷��� false ��

ʾ�� 1��
���룺matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
�����true

ʾ�� 2��
���룺matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
�����false
*/

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // ˼·�������ֲ������õ�������
        int low = 0, high = matrix.size() - 1;
        int colEnd = matrix[0].size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (matrix[mid][0] == target)
                return true;

            else if (matrix[mid][0] < target){
                if (matrix[mid][colEnd] < target){
                    // midһ���ж�С��target
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
