#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 双指针
        int p0 = 0;  // 负责交换 0
        int p1 = 0;  // 负责交换 1
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                swap(nums[p1], nums[i]);
                ++p1;
            } else if (nums[i] == 0) {
                swap(nums[p0], nums[i]);
                if (p0 < p1) {  // 则刚才交换了一个 1 到 nums[i]
                    swap(nums[p1], nums[i]);  // 把 1 换回去
                }
                ++p0, ++p1;
            }
        }
    }
};

int main() {
    vector<int> nums = {0, 1};
    Solution obj;
    obj.sortColors(nums);
    return 0;
}