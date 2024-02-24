#include <iostream>
#include <vector>

using namespace std;

/*
����һ�������� n ������һ������ 1 �� n^2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е� n x n �����ξ��� matrix ��

ʾ�� 1��
���룺n = 3
�����[[1,2,3],[8,9,4],[7,6,5]]

ʾ�� 2��
���룺n = 1
�����[[1]]
*/

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int len = n - 1; // �ĸ������ϣ������ÿ���ߵĳ���
        int loopTime = n / 2 + 1; // ��ѭ������
        int num = 1; // ������������
        int start = 0;
        vector<vector<int>> res(n, vector<int>(n));

        for (int loopCount = 0; loopCount < loopTime; loopCount++){
            // ����nΪ����ʱ�����һ����������
            if (loopCount == loopTime - 1 && n % 2 != 0)
            {
                res[loopCount][loopCount] = n * n;
                break;
            }
            
            for (int i = start, j = 0; j < len; i++, j++, num++) // ����
                res[loopCount][i] = num;

            for (int i = start, j = 0; j < len; i++, j++, num++) // ����
                res[i][n - loopCount - 1] = num;

            for (int i = n - start - 1, j = 0; j < len; i--, j++, num++) // ����
                res[n - loopCount - 1][i] = num;

            for (int i = n - start - 1, j = 0; j < len; i--, j++, num++) // ����
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
