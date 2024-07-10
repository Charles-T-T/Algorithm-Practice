#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

示例 1：
输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
输出：2
解释：
两个元组如下：
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

示例 2：
输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
输出：1
*/

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        // 思路：哈希表 + 分治
        int count = 0;
        unordered_map<int, int> sumMap; // 存储前两个数 a + b 各种求和结果出现的次数
        for (int a : nums1) {
            for (int b : nums2)
                sumMap[a + b]++;
        }
        // 根据后两个数的和 c + d ，找凑成0所需的差 -(c + d) 是否能由之前的 a + b 得出
        for (int c : nums3) {
            for (int d : nums4)
                count += sumMap[- c - d];
        }
        return count;
    }
};