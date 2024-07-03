#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int fast = 0, slow = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != val) 
                nums[slow++] = nums[fast];
            fast++;
        }
        return slow;
    }
};

int main()
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    Solution obj;
    int res = obj.removeElement(nums, val);

    return 0;
}