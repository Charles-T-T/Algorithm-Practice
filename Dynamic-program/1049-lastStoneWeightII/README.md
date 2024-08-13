# 1049. 最后一块石头的重量 II

[点此跳转题目链接](https://leetcode.cn/problems/last-stone-weight-ii/description/)

## 题目描述

有一堆石头，用整数数组 `stones` 表示。其中 `stones[i]` 表示第 `i` 块石头的重量。

每一回合，从中选出**任意两块石头**，然后将它们一起粉碎。假设石头的重量分别为 `x` 和 `y`，且 `x <= y`。那么粉碎的可能结果如下：

- 如果 `x == y`，那么两块石头都会被完全粉碎；
- 如果 `x != y`，那么重量为 `x` 的石头将会完全粉碎，而重量为 `y` 的石头新重量为 `y-x`。

最后，**最多只会剩下一块** 石头。返回此石头 **最小的可能重量** 。如果没有石头剩下，就返回 `0`。

 

**示例 1：**

```
输入：stones = [2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
```

**示例 2：**

```
输入：stones = [31,26,33,21,40]
输出：5
```

 

**提示：**

- `1 <= stones.length <= 30`
- `1 <= stones[i] <= 100`



## 题解

根据题目，这些石头有点像玩消消乐一样”两两消除“，所以其实我们可以采用 **整体** 的思想，将它们尽可能地分成 **大小接近的两堆** ，这样两堆各自的重量之和相减，得到的就是最终剩余的那块石头重量（若恰好能分成等重的两堆，则刚好全部消除）。自然，每堆的重量应该尽量接近总重量的一半：

```cpp
int sumWeight = 0; 
for (int stone : stones)
    sumWeight += stone;
int halfWeight = sumWeight / 2;
```

接下来，我们要尝试从 `stones` 中选取若干个元素，使得它们的和靠近 `halfWeight` 。这就可以把问题转化为 **01背包问题** ，再采用相应的 **动态规划** 方法解决：

**有 `weights` 和 `value` 都为 `stones` 的物品，尽可能在容量为 `halfWeight` 的背包中装价值高的物品。** 相应的，有

- `dp` 数组含义： `dp[j]` 表示容量为 `j` 的背包能装的最高总价值
- 状态转移方程： `dp[j] = max(dp[j], dp[j - stones[i]] + stones[i])` （常规模式）

最后得到的 `dp[halfWeight]` 相当于其中一堆的重量（根据01背包算法，已经尽量接近总重量的一半了），另一堆的重量自然就是 `sumWeight - dp[halfWeight]` 。那么二者之差 `abs(sumWeight - 2 * dp[halfWeight])` 即为所求结果。

> 该算法更详细的解析参见 [代码随想录](https://programmercarl.com/1049.最后一块石头的重量II.html)

**代码（C++）**

```cpp
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
```

