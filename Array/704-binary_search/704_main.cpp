#include <iostream>
#include <vector>

using namespace std;

/*
����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��


ʾ�� 1:

����: nums = [-1,0,3,5,9,12], target = 9
���: 4
����: 9 ������ nums �в����±�Ϊ 4
ʾ�� 2:

����: nums = [-1,0,3,5,9,12], target = 2
���: -1
����: 2 ������ nums ����˷��� -1
*/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid; // ���Һ��м��±�
        while (left <= right)
        {
            mid = left + (right - left) / 2; // Ϊ�˷�ֹleft + right�����д����ʵ�ʵ�ͬ��(left + right) / 2
            if (nums[mid] == target)
                return mid;
            else
            {
                if (nums[mid] < target)
                {
                    left = mid + 1;
                    continue;
                }
                else
                {
                    right = mid - 1;
                    continue;
                }
            }
        }
        return -1; // nums�в�����target
    }
};

int main()
{
    vector<int> nums;
    int target, size, num;
    cout << "please input the target: ";
    cin >> target;
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
    cout << "location: " << solution.search(nums, target);
    return 0;
}