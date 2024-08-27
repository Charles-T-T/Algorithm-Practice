# 123. 买卖股票的最佳时机 III

[点此跳转题目链接](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/)

## 题目描述

给定一个数组，它的第 `i` 个元素是一支给定的股票在第 `i` 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 **两笔** 交易。

**注意：**你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

**示例 1:**

```
输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
```

**示例 2：**

```
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
```

**示例 3：**

```
输入：prices = [7,6,4,3,1] 
输出：0 
解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
```

**示例 4：**

```
输入：prices = [1]
输出：0
```

 

**提示：**

- `1 <= prices.length <= 105`
- `0 <= prices[i] <= 105`



## 题解

这题在 [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/) 和 [122. 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/) 的基础上，增加了买卖股票的次数限制： **最多只能进行两次交易** 。由于每次必是“先买后卖”，我首先尝试将数组整体分为两段，对应两次交易所处的时间段，然后求这两段中各进行一次交易所得利润之和（这就是普通的买卖股票问题了），最后求不同分段方式下利润最大值即可：

```cpp
class Solution // 分段+普通股票规划，超时
{
private:
    int simpleMax(const vector<int> &prices, int start, int end) {
        int low = INT_MAX, res = 0;
        for (int i = start; i < end; ++i) {
            low = min(low, prices[i]);
            res = max(res, prices[i] - low);
        }
        return res;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        for (int i = 0; i < prices.size(); ++i) {
            int v1 = simpleMax(prices, 0, i);
            int v2 = simpleMax(prices, i, prices.size());
            res = max(res, v1 + v2);
        }
        return res;
    }
};
```

不出所料，这种愚蠢的方法超时了 :clown_face: 

---

下面采用更优雅的 **动态规划** 解决。

对于任一天，当前的状态无外乎5种：

- 未进行过交易
- 进行了一次买入
- 进行了一次卖出（即完成了一笔交易）
- 进行了两次买入、一次卖出（即完成一笔交易后，有买入了一次）
- 进行了两次买入、两次卖出（即完成了两笔交易）

其中，第一种情况下（未进行过交易）的余额显然为0（初始值），可以不考虑。在第 `i` 天，剩余四种情况对应的 **最大余额** 分别记作 `dp[i][0]` 到 `dp[i][3]` 。接下来考虑它们各自对应的 **状态转移方程** ：

- **若进行了一次买入（ `dp[i][0]` )** 

  - 可能是之前就买入了的，这天无操作，故余额仍是 `dp[i - 1][0]` 
  - 可能之前没买入、这天买入了，余额： `-prices[i]` 

  所以求最大余额有： `dp[i][0] = max(dp[i - 1][0], -prices[i])` 

- **若完成了一笔交易（ `dp[i][1]` ）**

  - 可能是之前就完成了的，这天无操作，余额： `dp[i - 1][1]` 
  - 可能之前买入了，这天卖出，余额： `dp[i - 1][0] + prices[i]` 

  最大余额： `dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i])` 

- **若完成一笔交易后进行了一次买入（ `dp[i][2]` ）**

  - 可能是之前就这样了，这天无操作，余额： `dp[i - 1][2]` 
  - 可能之前完成了一笔交易，这天进行了一次买入，余额： `dp[i - 1][1] - prices[i]`

  最大余额： `dp[i][2] = max(dp[i -1][2], dp[i - 1][1] - prices[i])`

- **若完成了两笔交易（ `dp[i][3]` ）**

  - 可能之前就是这样了，这天无操作，余额： `dp[i - 1][3]`
  - 可能之前完成了一笔交易后又买入了，这天卖出，余额： `dp[i - 1][2] + prices[i]`

  最大余额： `dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i])`

末了，选取最后一天（第 `n` 天）完成了一次、两次交易的情况下余额更大的那个，即 `max(dp[n][1], dp[n][3])` 。

> 都最后一天了，显然把持有的股票卖出去的情况余额会更多，所以不考虑另外两种情况了。

综上，按照动态规划经典版式写代码就可以了：

```cpp
int maxProfit(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size(), vector<int>(4, INT_MIN / 2));
    dp[0][0] = -prices[0]; // 第一天若要操作，只能买入
    for (int i = 1; i < dp.size(); ++i) {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
    }
    return max(0, max(dp.back()[1], dp.back()[3])); // 如果股票一直跌，不如不买
}
```

> 初始化：除了 `dp[0][0]` ，其他位置初始化为 `INT_MIN / 2` ，一方面是极小数、确保正确处理前几次情况（例如，第2天最多就完成一笔交易，即 `dp[1][2]` 和 `dp[1][3]` 不应该存在），另一方面避免越界
>
> 如果股票价格从头跌到尾，动态规划的最终结果会是负数，此时需要取0（不如一直不买）

显然，上述代码中的 `dp` 数组可以简化为一维的滚动数组：

```cpp
int maxProfit(vector<int> &prices)
{
    vector<int> dp(4, INT_MIN / 2);
    dp[0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        dp[0] = max(dp[0], -prices[i]);
        dp[1] = max(dp[1], dp[0] + prices[i]);
        dp[2] = max(dp[2], dp[1] - prices[i]);
        dp[3] = max(dp[3], dp[2] + prices[i]);
    }
    return max(0, max(dp[1], dp[3]));
}
```



