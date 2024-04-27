#include <iostream> 
#include <vector>

using namespace std;

/*
������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�

����԰� �κ�˳�� ���ش𰸡�

ʾ�� 1��
���룺n = 4, k = 2
�����
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

ʾ�� 2��
���룺n = 1, k = 1
�����[[1]]
*/

class Solution // �����㷨������������ṹ����
{
private:
    vector<int> path; // �洢��ǰ���������Ľڵ�·��
    vector<vector<int>> res; // �洢���ս��

public:
    // ���ݺ���
    void backTracking(int n, int k, int start){
        if (path.size() == k){
            res.push_back(path);
            return;
        } // �ݹ����

        for (int i = start; i <= n; i++)
        {
            // ��֦����ʣ�µ� < ����Ҫ�ģ����֦
            if (n - i + 1 < k - path.size())
                break;
                 
            path.push_back(i); // ����
            backTracking(n, k, i + 1); // �ݹ�
            path.pop_back(); // ����
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backTracking(n, k, 1);
        return res;
    }
};

int main(){
    int n = 4, k = 2;
    Solution obj;
    vector<vector<int>> res = obj.combine(4, 2);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < res[0].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}