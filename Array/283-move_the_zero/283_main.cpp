#include <iostream>
#include <vector>

using namespace std;

/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

示例 2:
输入: nums = [0]
输出: [0]
*/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // 双指针，记录0的个数，最后统一加到末尾
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

        // 在末尾添加0
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