#include <iostream>
#include <vector>

using namespace std;

/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

��ע�� �������ڲ���������������ԭ�ض�������в�����

ʾ�� 1:
����: nums = [0,1,0,3,12]
���: [1,3,12,0,0]

ʾ�� 2:
����: nums = [0]
���: [0]
*/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // ˫ָ�룬��¼0�ĸ��������ͳһ�ӵ�ĩβ
        int slow = 0, fast = 0;
        int edge = nums.size();

        for (fast = 0; fast < nums.size(); fast++){
            if (nums[fast] == 0)
            {
                edge--;
                continue;
            }
            else
                nums[slow++] = nums[fast];
        }

        // ��ĩβ���0
        for (int i = edge; i < nums.size(); i++)
            nums[i] = 0;
    }
};

int main(){
    vector<int> nums;
    int size, num;
    cout << "please input the size of nums: ";
    cin >> size;
    cout << "please input nums, divided by space: ";
    for (int i = 0; i < size; i++)
    {
        cin >> num;
        nums.push_back(num);
    }

    Solution obj;
    obj.moveZeroes(nums);
    cout << "result: [ ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "]";

    return 0;
}