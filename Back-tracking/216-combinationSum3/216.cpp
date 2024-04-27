#include <iostream>
#include <vector>

using namespace std;

/*
�ҳ��������֮��Ϊ n �� k ��������ϣ�����������������

ֻʹ������1��9
ÿ������ ���ʹ��һ��
���� ���п��ܵ���Ч��ϵ��б� �����б��ܰ�����ͬ��������Σ���Ͽ������κ�˳�򷵻ء�

ʾ�� 1:
����: k = 3, n = 7
���: [[1,2,4]]
����:
1 + 2 + 4 = 7
û���������ϵ�����ˡ�

ʾ�� 2:
����: k = 3, n = 9
���: [[1,2,6], [1,3,5], [2,3,4]]
����:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
û���������ϵ�����ˡ�

ʾ�� 3:
����: k = 4, n = 1
���: []
����: ��������Ч����ϡ�
��[1,9]��Χ��ʹ��4����ͬ�����֣����ǿ��Եõ�����С����1+2+3+4 = 10����Ϊ10 > 1��û����Ч����ϡ�
*/

/* �����㷨 */
class Solution
{
private:
    vector<vector<int>> res; // ���
    vector<int> path;        // �м�洢��·��

public:
    // ����k��������С��
    int MinSumK(int k)
    {
        int sum = 0;
        for (int i = 1; i <= k; i++)
            sum += i;
        return sum;
    }

    void BackTracing(int k, int targetSum, int curSum, int start)
    {
        // ��ȷ���ݹ����
        if (path.size() == k)
        {
            if (curSum == targetSum)
            {
                res.push_back(path);
            }
            return;
        }
        // ��֦
        if (curSum >= targetSum)
            return;

        // ��ʼ����������
        for (int i = start; i <= 9; i++)
        {
            curSum += i;
            path.push_back(i);                        // ����
            BackTracing(k, targetSum, curSum, i + 1); // �ݹ�
            curSum -= i;
            path.pop_back();                          // ����
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        // �ų���Ч���
        if (MinSumK(k) > n)
            return res;

        BackTracing(k, n, 0, 1);
        return res;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> res = obj.combinationSum3(3, 7);

    cout << "test..." << endl;
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