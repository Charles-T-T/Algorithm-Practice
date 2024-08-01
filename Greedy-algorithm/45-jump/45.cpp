#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int farDist = 0; // 能到达的最远距离
        int cover = 0;   // 当前的覆盖区间（右边界）
        int count = 0;   // 跳跃次数
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            farDist = max(farDist, i + nums[i]);
            if (i >= cover) // 到达当前覆盖的最远距离
            {
                count++;         // 必须再跳一步才能跳出当前覆盖区间
                cover = farDist; // 更新覆盖区间
            }
            if (cover >= nums.size() - 1) // 到达数组末尾
                return count;
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {2, 3, 0, 1, 4};
    Solution obj;
    cout << obj.jump(nums) << endl;
    return 0;
}