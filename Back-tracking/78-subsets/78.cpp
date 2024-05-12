#include <iostream>
#include <vector>

using namespace std;

/*
����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ�
�Ӽ�
���ݼ�����

�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��

ʾ�� 1��
���룺nums = [1,2,3]
�����[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

ʾ�� 2��
���룺nums = [0]
�����[[],[0]]
*/

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

public:
    void BackTracking(const vector<int> &nums, int len, int start)
    {
        // ȷ���ݹ����
        if (start == len)
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            path.push_back(nums[i]);            // ����
            BackTracking(nums, len, i + 1); // �ݹ�
            path.pop_back();                    // ����
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        for (int i = 0; i <= nums.size(); i++)
        {
            BackTracking(nums, i, 0);
        }
        return res;
    }
};

void Display(vector<vector<int>> nums)
{
    cout << "[ ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < nums[i].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution obj;
    vector<vector<int>> res = obj.subsets(nums);
    Display(res);

    return 0;
}
