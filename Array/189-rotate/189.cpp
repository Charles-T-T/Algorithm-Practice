#include <iostream>
#include <vector>

using namespace std;

/*
����һ���������� nums���������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����

ʾ�� 1:
����: nums = [1,2,3,4,5,6,7], k = 3
���: [5,6,7,1,2,3,4]
����:
������ת 1 ��: [7,1,2,3,4,5,6]
������ת 2 ��: [6,7,1,2,3,4,5]
������ת 3 ��: [5,6,7,1,2,3,4]

ʾ�� 2:
���룺nums = [-1,-100,3,99], k = 2
�����[3,99,-1,-100]
����:
������ת 1 ��: [99,-1,-100,3]
������ת 2 ��: [3,99,-1,-100]
*/

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        /**
         * ˼·��������ͦ�򵥵ģ�
         * �ȶ�nums�Ĵ�Сȡģ���ٽ�����ת
         * ֱ���¿�һ������洢������ٷ���nums
        */
        if (nums.size() == 0)
            return;

        vector<int> res(nums.size());
        int newK = k % nums.size();

        // �����newK���ȷŵ���ͷ
        int lastNum = 0;
        for (int j = nums.size() - newK, i = 0; lastNum < newK; j++, i++, lastNum++){
            res[i] = nums[j];
        }

        // ��numsǰ�沿�ֵ����ַŵ�res����
        for (int i = newK, j = 0; i < res.size(); i++, j++){
            res[i] = nums[j];
        }

        nums = res;
    }
};

// [1 2 3 4 5]
// (0 1 2 3 4)