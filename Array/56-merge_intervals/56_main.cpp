#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ������ϲ������ص������䣬������ һ�����ص����������飬��������ǡ�ø��������е��������� ��

ʾ�� 1��
���룺intervals = [[1,3],[2,6],[8,10],[15,18]]
�����[[1,6],[8,10],[15,18]]
���ͣ����� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].

ʾ�� 2��
���룺intervals = [[1,4],[4,5]]
�����[[1,5]]
���ͣ����� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣
*/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // ˼·���������������Ժϲ��ĺϲ��ͺ���
        vector<vector<int>> resIV;
        vector<int> newIV(2);

        // �Ƚ�ԭintervals����ÿ���������߽��С��������
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++)
        {
            if (i > 0 && intervals[i][0] <= resIV.back()[1])
            {
                newIV[0] = resIV.back()[0];
                newIV[1] = max(resIV.back()[1], intervals[i][1]);
                resIV.pop_back();
                resIV.push_back(newIV);
                continue;
            }
            resIV.push_back(intervals[i]);
        }

        return resIV;
    }
};

int main(){
    vector<vector<int>> intervals, resIV;
    int ivSize, left, right;
    

    cout << "please input the size of the intervals: ";
    cin >> ivSize;
    for (int i = 0; i < ivSize; i++)
    {
        cout << "No." << i + 1 << " vec: ";
        cin >> left >> right;
        vector<int> curIV(2);
        curIV[0] = left;
        curIV[1] = right;
        intervals.push_back(curIV);
    }

    Solution obj;
    resIV = obj.merge(intervals);
    cout << "result: "
         << "[";
    for (const vector<int>& vec : resIV){
        cout << "[" << vec[0] << ", " << vec[1] << "]";
    }
    cout << "]";

    return 0;
}