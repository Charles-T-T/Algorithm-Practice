# 474. 一和零

[点此跳转题目链接](https://leetcode.cn/problems/ones-and-zeroes/description/)

## 题目描述

给你一个二进制字符串数组 `strs` 和两个整数 `m` 和 `n` 。

请你找出并返回 `strs` 的最大子集的长度，该子集中 **最多** 有 `m` 个 `0` 和 `n` 个 `1` 。

如果 `x` 的所有元素也是 `y` 的元素，集合 `x` 是集合 `y` 的 **子集** 。

 

**示例 1：**

```
输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
```

**示例 2：**

```
输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
```

 

**提示：**

- `1 <= strs.length <= 600`
- `1 <= strs[i].length <= 100`
- `strs[i]` 仅由 `'0'` 和 `'1'` 组成
- `1 <= m, n <= 100`



## 题解

实际上是01背包的变形（多了一个维度），动态规划解决。

最基本的01背包对应的物品只有“重量”和“价值”，背包自身的限制只有 **一个** “容量”，但是本题中，很显然，类似“容量”的值有两个： `m` 和 `n` ，可以分别理解为背包能装的 0 和 1 的容量。那么直接按照常规背包的解决方案，多加一层循环以便处理两个维度的 `weights` 和”容量“即可：

- `dp` 数组含义： `dp[i][j]` 表示容量为 `i` 个 0 和 `j` 个 1 的背包，最多能装的元素个数（也就是题目中的子集大小）
- 状态转移方程： `dp[i][j] = max(dp[i][j], dp[i - zeroCount][j - oneCount] + 1)` ，其中 `zeroCount` 和 `oneCount` 表示当前处理的字符串中 0 和 1 的个数； `+ 1` 相当于在原来那个子集中加入当前处理的字符串

> 该算法更详细的解析参见 [代码随想录](https://programmercarl.com/0474.一和零.html#思路) 

**C++**

```cpp
int findMaxForm(vector<string> &strs, int m, int n)
{
    // dp[i][j]: 最多有i个0和j个1的子集的最大长度
    // 对于新的二进制字符串k，其中0和1数量为k_0和k_1:
    // dp[i][j] = max(dp[i][j], dp[i - k_0][j - k_1] + 1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (const string &str : strs) {
        int zeroCount = count(str.begin(), str.end(), '0');
        int oneCount = count(str.begin(), str.end(), '1');
        for (int i = m; i >= zeroCount; --i) {
            for (int j = n; j >= oneCount; --j) 
                dp[i][j] = max(dp[i][j], dp[i - zeroCount][j - oneCount] + 1);
        }
    }
    return dp[m][n];
}
```

**Golang**

```go
func findMaxForm(strs []string, m int, n int) int {
	dp := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		dp[i] = make([]int, n+1)
	}
	for _, str := range strs {
		zeroCount, oneCount := 0, 0
		for _, c := range str {
			if c == '0' {
				zeroCount++
			}
			if c == '1' {
				oneCount++
			}
		}
		for i := m; i >= zeroCount; i-- {
			for j := n; j >= oneCount; j-- {
				dp[i][j] = max(dp[i][j], dp[i-zeroCount][j-oneCount]+1)
			}
		}
	}
	return dp[m][n]
}
```

**Python**

```python
class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for str in strs:
            zero_count = str.count('0')
            one_count = str.count('1')
            for i in range(m, zero_count - 1, -1):
                for j in range(n, one_count - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - zero_count][j - one_count] + 1)
        return dp[m][n]
    
```

