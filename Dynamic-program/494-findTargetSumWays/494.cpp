#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个非负整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。



示例 1：
输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

示例 2：
输入：nums = [1], target = 1
输出：1

提示：
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/

class Solution
{
private:

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        /**
         * 记x、y分别为某个表达式中，符号为“+”数之和与符号为“-”数之和
         * x + y = target
         * 记sum为nums中所有数之和
         * x - y = sum
         * y = x - sum
         * x + x - sum = target
         * x = (target + sum) / 2
         * 所以，要求的就是这个x的不同组合方式有多少种
        */
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];

        // 由上面的分析，x = (target + sum) / 2需为整数，则target + sum应为偶数
        if ((target + sum) % 2 != 0)
            return 0; 
        // 自然，target的绝对值不能大于sum，否则全为正或全为负都达不到（题目说了nums[i] >= 0）
        if (abs(target) > sum)
            return 0;

        /**
         * 求出x，用01背包问题的思想
         * nums[i]相当于第i件物品的重量
         * x相当于背包容量
         * 本题相当于求“用nums里的物品把容量为x的背包装满有多少种方法”
        */
        int bagSize = (target + sum) / 2; // 为了便于理解，直接把x记作bagSize

        // 接下来基本按照动态规划标准步骤走
        // 初始化dp数组，dp[i]表示“从nums[0] ~ nums[i]中选东西，装满容量为i的背包的方式”
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1; // “万物起源”，得赋值为1
        for (int i = 0; i < nums.size(); ++i){
            for (int j = bagSize; j >= nums[i]; --j){ // 注意这里是j >= nums[i]
                // 现背包容量为j，手上有一个重nums[i]的物品，则：找到装满j - nums[i]容量背包方法，再把nums[i]装进去就行
                dp[j] += dp[j - nums[i]]; 
            }
        }

        return dp[bagSize];
    }
};

int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    Solution obj;
    cout << "res: " << obj.findTargetSumWays(nums, 3) << endl;

    return 0;
}