#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] = max(dp[i - 3] + value[i], dp[i - 2] + value[i], dp[i - 1])
        vector<int> dp(nums.size() + 3, 0);
        for (int i = 3; i < dp.size(); i++){
            dp[i] = max(max(dp[i - 3] + nums[i - 3], dp[i - 2] + nums[i - 3]), dp[i - 1]);
        }
        return dp[dp.size() - 1];
    }
};

int main(){
    vector<int> nums = {1,2,3,1};
    Solution obj;
    cout << "res: " << obj.rob(nums);
    return 0;
}