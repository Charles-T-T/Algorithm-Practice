#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

/*
����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ����ʹ�� ԭ�� �㷨��

ʾ�� 1��
���룺matrix = [[1,1,1],[1,0,1],[1,1,1]]
�����[[1,0,1],[0,0,0],[1,0,1]]

ʾ�� 2��
���룺matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
�����[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // ˼·�����ҵ���ʼ״̬�µ����λ�ã�������
        // �Ż��ռ临�Ӷȣ�ֱ���õ�һ�С�����������λ��
        int rowCount = matrix.size(), colCount = matrix[0].size();
        int row0Flag = 0, col0Flag = 0; // ��ǵ�һ�С�����û����
        for (int i = 0; i < rowCount; i++)
        {
            if (!matrix[i][0])
            {
                col0Flag = 1;
                break;
            }
        }
        for (int j = 0; j < colCount; j++){
            if (!matrix[0][j])
            {
                row0Flag = 1;
                break;
            }
        }

        // ����������е���λ
        for (int i = 0; i < rowCount; i++){
            for (int j = 0; j < colCount; j++){
                if (!matrix[i][j])
                    matrix[0][j] = matrix[i][0] = 0;
            }
        }

        // �����
        for (int i = 1; i < rowCount; i++)
        {
            for (int j = 1; j < colCount; j++)
            {
                if (!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
            }
        }

        if (row0Flag)
            fill(matrix[0].begin(), matrix[0].end(), 0);

        if(col0Flag){
            for (int i = 0; i < rowCount; i++)
                matrix[i][0] = 0;
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