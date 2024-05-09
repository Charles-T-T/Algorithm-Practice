#include <iostream>
#include <vector>

using namespace std;

/*
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]

示例 2:
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释:
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]
*/

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        /**
         * 思路：看起来挺简单的（
         * 先对nums的大小取模，再进行轮转
         * 直接新开一个数组存储结果，再返给nums
        */
        if (nums.size() == 0)
            return;

        vector<int> res(nums.size());
        int newK = k % nums.size();

        // 把最后newK个先放到开头
        int lastNum = 0;
        for (int j = nums.size() - newK, i = 0; lastNum < newK; j++, i++, lastNum++){
            res[i] = nums[j];
        }

        // 把nums前面部分的数字放到res后面
        for (int i = newK, j = 0; i < res.size(); i++, j++){
            res[i] = nums[j];
        }

        nums = res;
    }
};

// [1 2 3 4 5]
// (0 1 2 3 4)