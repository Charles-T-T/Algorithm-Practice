#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        // 思路：双指针
        // 原数组可能有负数，这样平方之后，“两头”的数总是最大的
        vector<int> res;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int ls = pow(nums[left], 2);
            int rs = pow(nums[right], 2);
            // 数组头插要移动后面元素，先这样大的放前面，最后反转即可
            if (ls > rs) {
                res.push_back(ls);
                left++;
            } else {
                res.push_back(rs);
                right--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

