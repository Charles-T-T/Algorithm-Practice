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
*/

class Solution
{
public:
    vector<int> sortedSquares1(vector<int> &nums)
    {
        // �����ⷨ����ƽ��������sort�����Ÿ���
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = pow(nums[i], 2);
        }
        sort(nums.begin(), nums.end());
        return nums;
    }

    vector<int> sortedSquares2(vector<int> &nums)
    {
        // ˫ָ�뷨�����������м�Ƚ�
        int max = nums.size() - 1;
        int left = 0, right = max;
        int leftNum, rightNum;
        vector<int> newVec(max + 1);
        while (left <= right)
        {
            leftNum = pow(nums[left], 2),  rightNum = pow(nums[right], 2);
            if (leftNum >= rightNum){
                newVec[max--] = leftNum;
                left++;
                continue;
            }
            else{
                newVec[max--] = rightNum;
                right--;
                continue;
            }
        }

        return newVec;
    }
};

int main(){
    vector<int> nums;
    int target, size, num;
    cout << "please input the size of nums: ";
    cin >> size;
    cout << "please input the nums, divided by space: ";
    int i = 0;
    while (i < size)
    {
        cin >> num;
        nums.push_back(num);
        i++;
    }

    Solution solution;
    nums = solution.sortedSquares2(nums);

    cout << "[ ";
    for (i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}