#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 哈希表秒了
        unordered_map<int, bool> numMap;
        vector<int> res;
        for (int num : nums1)
            numMap[num] = true;
        for (int num : nums2) {
            if (numMap[num]) {
                res.push_back(num);
                numMap[num] = false; // 防止重复添加
            }
        }
        return res;
    }
};