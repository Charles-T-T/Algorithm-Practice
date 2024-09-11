#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int len = 1, maxLen = 1; 
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1])
                len++;
            else {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        return max(len, maxLen);
    }
};