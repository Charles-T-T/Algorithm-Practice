#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // 思路：尝试快慢双指针，构成一个滑动窗口，动态更新最短长度
        int slow = 0, fast = 0;
        const int MAX = numeric_limits<int>::max();
        int minLen = MAX;
        int curSum = nums[fast];
        while (1)
        {
            if (curSum >= target)
            {
                minLen = min(minLen, fast - slow + 1);
                curSum -= nums[slow];
                slow++;
            }
            else
            {
                fast++;
                if (fast >= nums.size())
                    break;
                curSum += nums[fast];
            }
        }

        return minLen == MAX ? 0 : minLen;
    }
};

int main()
{
    vector<int> nums = {2,
                        3,
                        1,
                        2,
                        4,
                        3};
    Solution obj;
    int minLen = obj.minSubArrayLen(7, nums);
    cout << minLen << endl;

    return 0;
}