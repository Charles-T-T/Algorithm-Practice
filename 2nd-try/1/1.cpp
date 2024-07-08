#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 哈希表解决：找数字所需的“另一半”
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++)
            numMap[nums[i]] = i;
        vector<int> res(2);
        for (int i = 0; i < nums.size(); i++) {
            if (numMap.find(target - nums[i]) != numMap.end() &&
                numMap[target - nums[i]] != i) {
                res[0] = i, res[1] = numMap[target - nums[i]];
                break;
            }
        }
        return res;
    }
};