#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int BinarySearchPro(vector<int> nums, int target, bool exact) {
        // 改良版二分查找：保证查找到第一个target的位置
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            // 为了保证找到“第一个”target，界限应该尽量“往左收”
            if (nums[mid] > target || (exact && nums[mid] >= target)) 
                right = mid - 1;
            else 
                left = mid + 1;
        }
        int ans = right + 1;
        if (!exact || (ans < nums.size() && nums[ans] == target))
            return ans;
        else    
            return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return vector<int> {-1, -1};
        // 找到第一个target的位置和第一个(target - 1)的位置-1即可
        int num1 = BinarySearchPro(nums, target, true);
        if (num1 == -1)
            return vector<int>{-1, -1};
        int num2 = BinarySearchPro(nums, target, false) - 1;
        if (num2 > nums.size() - 1)
            return vector<int> {num1, (int)nums.size() - 1};
        else
            return vector<int> {num1, num2};
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution obj;
    vector<int> res = obj.searchRange(nums, 1);
    for (const int & num : res)
        cout << num << " ";
    cout << endl;

    return 0;
}
