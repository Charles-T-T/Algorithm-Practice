#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

示例 1：
输入：stones = [2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。

示例 2：
输入：stones = [31,26,33,21,40]
输出：5

提示：
1 <= stones.length <= 30
1 <= stones[i] <= 100
*/

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        /**
         * 思路：
         * 目标其实是将石堆尽可能分为大小接近的两堆，然后碰撞
         * 动态规划，可转化为01背包问题
         * 总重为weight，则target = weight / 2
         *
         * dp[j]的含义：
         * 容量为j的背包最多能装下价值（此处数值上等于重量）的物品
         *
         * 目标：
         * 将dp[target]尽可能接近target（尽量大）
         */
        int weight = accumulate(stones.begin(), stones.end(), 0);
        int target = weight / 2;
        vector<int> dp(target + 1, 0);

        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = target; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return weight - dp[target] * 2;
    }
};

class Solution2 // 二刷
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        // 分成两大堆，且尽量使它们重量相等
        int sumWeight = 0; 
        for (int stone : stones)
            sumWeight += stone;
        int halfWeight = sumWeight / 2;
        // 转化为01背包问题：容量为halfWeight的背包
        vector<int> dp(halfWeight + 1, 0);
        for (int j = stones[0]; j <= halfWeight; ++j)
            dp[j] = stones[0];
        for (int i = 1; i < stones.size(); ++i) {
            for (int j = halfWeight; j >= stones[i]; --j)
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
        return abs(sumWeight - 2 * dp[halfWeight]);
    }
};

int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    Solution2 obj;
    cout << "res: " << obj.lastStoneWeightII(stones) << endl;

    return 0;
}