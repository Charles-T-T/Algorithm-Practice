#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

������
�������е�һ���������֡�

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
        /**
         * ˼·��̰���㷨
         * ����nums���ۼ�
         * ����ǰ�ͱ�Ϊ�����������һ�����ֿ�ʼ���´�0�ۼ�
         * ��Ϊ��Ϊ����ʱ�������¼�ֻ�ᡰ���ۡ�����ĺ�
         * ÿ�θ������ͣ��Ա������
         */

        int i = 0;
        int curSum = 0, maxSum = -1e5;
        while (i < nums.size())
        {
            curSum += nums[i];
            maxSum = max(curSum, maxSum);
            if (curSum < 0)
            {
                curSum = 0;
                i++;
                continue;
            }
            i++;
        }
        return maxSum;
    }
};

int main()
{
    vector<int> nums = {-1};
    Solution obj;
    cout << "res: " << obj.maxSubArray(nums) << endl;

    return 0;
}