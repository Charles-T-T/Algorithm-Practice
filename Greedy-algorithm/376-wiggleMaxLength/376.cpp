#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        // 仅有一个元素或者含两个不等元素的序列也视作摆动序列
        if (nums.size() == 1)
            return 1;
        if (nums.size() == 2)
            return nums[0] == nums[1] ? 1 : 2;

        // 贪心算法
        int prevDiff = nums[1] - nums[0];     // 前两个数的差值
        int curDiff;                          // 当前两个数的差值
        int len = nums[0] == nums[1] ? 1 : 2; // 摆动子序列的长度
        for (int i = 2; i < nums.size(); ++i)
        {
            curDiff = nums[i] - nums[i - 1];
            if (curDiff * prevDiff < 0 || (prevDiff == 0 && curDiff != 0))
            {
                prevDiff = curDiff; // 只在“摆动”时才更新prevDiff
                len++;
            }
        }
        return len;
    }
};

int main()
{
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    Solution obj;
    cout << "res: " << obj.wiggleMaxLength(nums) << endl;

    return 0;
}