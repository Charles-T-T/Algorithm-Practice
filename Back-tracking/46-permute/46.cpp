#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�

ʾ�� 1��
���룺nums = [1,2,3]
�����[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

ʾ�� 2��
���룺nums = [0,1]
�����[[0,1],[1,0]]

ʾ�� 3��
���룺nums = [1]
�����[[1]]
*/

class Solution
{
private:
    vector<vector<int>> res;

public:
    void BackTracking(vector<int> &temp, int startIndex){
        // ȷ���ݹ����
        if (startIndex == temp.size()){
            res.push_back(temp);
            return;
        }

        for (int i = startIndex; i < temp.size(); i++){
            swap(temp[startIndex], temp[i]); // ����
            BackTracking(temp, startIndex + 1); // �ݹ�
            swap(temp[startIndex], temp[i]); // ����
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> temp = nums;
        BackTracking(temp, 0);
        return res;
    }
};



int main(){
    vector<int> nums = {1, 2, 3};
    Solution obj;
    vector<vector<int>> res = obj.permute(nums);


    cout << "res: ";
    cout << "[ ";
    for (int i = 0; i < res.size(); i++){
        cout << "[ ";
        for (int j = 0; j < res[0].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]" << endl;

    return 0;
}