#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
����һ���� �ǵݼ�˳�� ������������� nums������ ÿ�����ֵ�ƽ�� ��ɵ������飬Ҫ��Ҳ�� �ǵݼ�˳�� ����

ʾ�� 1��
���룺nums = [-4,-1,0,3,10]
�����[0,1,9,16,100]
���ͣ�ƽ���������Ϊ [16,1,0,9,100]
����������Ϊ [0,1,9,16,100]

ʾ�� 2��
���룺nums = [-7,-3,2,3,11]
�����[4,9,9,49,121]

��ʾ��
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums �Ѱ� �ǵݼ�˳�� ����
*/

class Solution
{
public:
    vector<int> sortedSquares_Violence(vector<int> &nums)
    {
        // �����ⷨ����ƽ��������
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = pow(nums[i], 2);
        }
        sort(nums.begin(), nums.end());
        return nums;
    }

    vector<int> sortedSquares(vector<int> &nums)
    {
        // ˼·������˫ָ��
        // ԭ��������и���������ƽ��֮�󣬡���ͷ��������������
        vector<int> res(nums.size());
        int curLast = res.size() - 1; // �������λ��
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int ls = pow(nums[left], 2);
            int rs = pow(nums[right], 2);
            if (ls > rs)
            {
                res[curLast--] = ls;
                left++;
            }
            else
            {
                res[curLast--] = rs;
                right--;
            }
        }
        return res;
    }
};
