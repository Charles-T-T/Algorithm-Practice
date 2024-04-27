#include <iostream>
#include <vector>

using namespace std;

/*
�����������֮��Ĳ��ϸ���������͸���֮�佻�棬���������г�Ϊ �ڶ����� ����һ���������ڵĻ�����������������������һ��Ԫ�ػ��ߺ���������Ԫ�ص�����Ҳ�����ڶ����С�

���磬 [1, 7, 4, 9, 2, 5] ��һ�� �ڶ����� ����Ϊ��ֵ (6, -3, 5, -7, 3) ������������ֵġ�

�෴��[1, 4, 7, 2, 5] �� [1, 7, 4, 5, 5] ���ǰڶ����У���һ����������Ϊ����ǰ������ֵ�����������ڶ�����������Ϊ�������һ����ֵΪ�㡣
������ ����ͨ����ԭʼ������ɾ��һЩ��Ҳ���Բ�ɾ����Ԫ������ã�ʣ�µ�Ԫ�ر�����ԭʼ˳��

����һ���������� nums ������ nums ����Ϊ �ڶ����� �� ������еĳ��� ��

ʾ�� 1��
���룺nums = [1,7,4,9,2,5]
�����6
���ͣ��������о�Ϊ�ڶ����У���Ԫ��֮��Ĳ�ֵΪ (6, -3, 5, -7, 3) ��

ʾ�� 2��
���룺nums = [1,17,5,10,13,15,10,5,16,8]
�����7
���ͣ�������а�����������Ϊ 7 �ڶ����С�
����һ���� [1, 17, 10, 13, 10, 16, 8] ����Ԫ��֮��Ĳ�ֵΪ (16, -7, 3, -3, 6, -8) ��

ʾ�� 3��
���룺nums = [1,2,3,4,5,6,7,8,9]
�����2
*/

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        /**
         * ˼·��
         * ̰���㷨����ν���ڶ�����������Ҫ��һ��һС��
        */
        if (nums.size() == 1)
            return 1;
        
        int length = 1;
        int flag; // �����һ�����ֱȽ��ǡ��󡱣�1�����ǡ�С����0��
        int start; // ��ʼ���ڶ�����λ��

        for (start = 1; start < nums.size(); start++)
        {
            if (nums[start] == nums[start - 1])
                continue; // �ҵ���ʼ���ڶ�����λ��
            else{
                flag = nums[start] > nums[start - 1];
                length++;
                break;
            }
        }

        for (int i = start + 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                continue; // �ҵ���һ�����ڶ�����λ��
            else if (flag && nums[i] < nums[i - 1]){
                length++;
                flag = 0;
            }
            else if (!flag && nums[i] > nums[i - 1]){
                length++;
                flag = 1;
            }
            else
                continue;
        }

        return length;
    }
};

int main(){
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    Solution obj;
    cout << "res: " << obj.wiggleMaxLength(nums) << endl;

    return 0;
}