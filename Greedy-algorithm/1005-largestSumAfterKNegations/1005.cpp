#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        // 贪心：尽量把小的负数取反，变成正数
        sort(nums.begin(), nums.end(), [](int a, int b){return abs(a) > abs(b);});
        int sum = 0;
        for (int &num : nums) {
            if (num < 0 && k > 0) {
                num = -num;
                k--;
            }
            sum += num;
        }
        if (k % 2 == 1)
            sum -= 2 * nums.back();
        return sum;
    }
};

int main()
{
    vector<int> nums = {-4, -2, -3};
    Solution obj;
    cout << obj.largestSumAfterKNegations(nums, 4) << endl;

    return 0;
}