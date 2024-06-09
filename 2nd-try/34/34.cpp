#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int loc = -1; // 第一次找到target的位置（不一定是第一个/最后一个target位置）
        int left = 0, right = nums.size() - 1;
        int mid;
        vector<int> res;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                loc = mid;
                break;
            } 
            if (nums[mid] < target) 
                left = mid + 1;
            else 
                right = mid - 1;
        }

        if (loc == -1) {
            res = {-1, -1};
            return res;
        }
       
        left = loc, right = loc;
        int leftFlag = 1, rightFlag = 1;
        while (leftFlag || rightFlag) {
            if (nums[left] == target && leftFlag) left--;
            else leftFlag = 0;

            if (nums[right] == target && rightFlag) right++;
            else rightFlag = 0;

            if (left < 0) leftFlag = 0;
            if (right >= nums.size()) rightFlag = 0;
        }
        
        res = {++left, --right};
        return res;
    }
};

int main() {
    vector<int> nums = {2, 2};
    Solution obj;
    vector<int> res = obj.searchRange(nums, 2);
    for (const int & num : res)
        cout << num << " ";
    cout << endl;

    return 0;
}
