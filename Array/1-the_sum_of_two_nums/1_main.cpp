#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�

����԰�����˳�򷵻ش𰸡�

ʾ�� 1��
���룺nums = [2,7,11,15], target = 9
�����[0,1]
���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��

ʾ�� 2��
���룺nums = [3,2,4], target = 6
�����[1,2]

ʾ�� 3��
���룺nums = [3,3], target = 6
�����[0,1]
*/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // ˼·���ܾ�����ѭ����ʹ�ù�ϣ����ʱ�临�Ӷ�
        unordered_map<int, int> numMap; // map<���֣��±�>
        int numNeeded;
        vector<int> res(2);
        for (int i = 0; i < nums.size(); i++)
        {
            numNeeded = target - nums[i];
            auto it = numMap.find(numNeeded);
            if (it != numMap.end()) // �ҵ���Ҫ������
            {
                res[0] = it->second;
                res[1] = i;
                return res;
            }
            numMap[nums[i]] = i;
        }

        return res;
    }
};