#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/*
����һ���������� nums ���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k ��ͬʱ������ nums[i] + nums[j] + nums[k] == 0 ����

�㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣

ע�⣺���в����԰����ظ�����Ԫ�顣


ʾ�� 1��
���룺nums = [-1,0,1,2,-1,-4]
�����[[-1,-1,2],[-1,0,1]]
���ͣ�
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 ��
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 ��
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 ��
��ͬ����Ԫ���� [-1,0,1] �� [-1,-1,2] ��
ע�⣬�����˳�����Ԫ���˳�򲢲���Ҫ��

ʾ�� 2��
���룺nums = [0,1,1]
�����[]
���ͣ�Ψһ���ܵ���Ԫ��Ͳ�Ϊ 0 ��

ʾ�� 3��
���룺nums = [0,0,0]
�����[[0,0,0]]
���ͣ�Ψһ���ܵ���Ԫ���Ϊ 0 ��
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // ˼·��������������ѭ������Ӧ��������
        int n = nums.size();
        sort(nums.begin(), nums.end()); // �����򣬱���֮��ö��
        int targetSum;                  // ��Ҫ�ĵڶ�����������֮��
        vector<vector<int>> res;

        for (int first = 0; first < n; ++first)
        {
            if (first > 0 && nums[first] == nums[first - 1])
                continue; // Ϊ�˱����ظ���������һ��ö�ٵ�����ͬ
            targetSum = -nums[first];

            /**
             * ����˫ָ�룬��third�Ӻ���ǰ���Ӵ�С����
             * ע�������third����ÿ��ö��secondʱ���¸�ֵΪn-1
             */
            int third = n - 1;

            for (int second = first + 1; second < n - 1; ++second)
            {
                if (second > first + 1 && nums[second] == nums[second - 1]) // �����ظ�
                    continue;
                while (second < third && nums[second] + nums[third] > targetSum)
                {
                    third--;
                }
                if (second == third) // ֮���second���󣬹ʶ�����֮�Ϳ϶�����󣬲���ﵽtarget
                    break;
                if (nums[second] + nums[third] == targetSum)
                    res.push_back({nums[first], nums[second], nums[third]});
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums;
    string line, numStr;
    cout << "please input the nums: ";
    getline(cin, line);
    stringstream ss(line);
    while (ss >> numStr)
    {
        nums.push_back(stoi(numStr));
    }

    Solution obj;
    vector<vector<int>> res = obj.threeSum(nums);
    cout << "result: " << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}