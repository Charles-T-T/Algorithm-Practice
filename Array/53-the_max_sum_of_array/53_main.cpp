#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

������ �������е�һ���������֡�

ʾ�� 1��
���룺nums = [-2,1,-3,4,-1,2,1,-5,4]
�����6
���ͣ����������� [4,-1,2,1] �ĺ����Ϊ 6 ��

ʾ�� 2��
���룺nums = [1]
�����1

ʾ�� 3��
���룺nums = [5,4,-1,7,8]
�����23
*/

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxRes = nums[0], pre = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            pre = max(pre + nums[i], nums[i]);
            maxRes = max(maxRes, pre);
        }
        return maxRes;
    }
};