#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]

示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
*/

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 思路：用哈希集合
        unordered_set<int> hashSet, resSet;
        vector<int> resVec;

        for (const int &num : nums1)
            hashSet.insert(num);
        for (const int &num : nums2)
        {
            if (hashSet.find(num) != hashSet.end() && resSet.find(num) == resSet.end())
                resVec.push_back(num);

            resSet.insert(num);
        }
        return resVec;
    }
};