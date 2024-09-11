# 718. 最长重复子数组

[点此跳转题目链接](https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/)

## 题目描述

给两个整数数组 `nums1` 和 `nums2` ，返回 *两个数组中 **公共的** 、长度最长的子数组的长度* 。

 

**示例 1：**

```
输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。
```

**示例 2：**

```
输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5
```

 

**提示：**

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 100`



## 题解

动态规划解决。这里的 “子数组” 其实就是 “连续子序列” ，因此参考最长子序列问题的套路：

- `dp` 数组的含义：

  - 记 $A$ 为： `nums1` 中长度为 `i - 1` 的（前缀）子数组 
  - 记 $B$ 为： `nums2` 中长度为 `j - 1` 的（前缀）子数组 

   `dp[i][j]` 表示： $A$ 和 $B$ 的最长公共子数组的长度

  > 这里长度分别为 `i - 1` 、 `j - 1` 而非 `i` 、 `j` ，是为了方便 `dp` 的初始化（在后续代码中不难看出），否则还需要单独对 `dp` 起始元素进行定义。

- 状态转移方程：如果 `nums1[i - 1] == nums2[j - 1]` ，即 $A$ 和 $B$ 的末尾元素相同，我们就可以把该公共元素加入之前的公共子数组中：`dp[i][j] = dp[i - 1][j - 1] + 1` ，并相应地更新最长公共子数组长度： `len = max(len, dp[i][j])` 。

**代码（C++）**

```cpp
int findLength(vector<int> &nums1, vector<int> &nums2)
{
    int len = 0;
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    for (int i = 1; i <= nums1.size(); ++i) {
        for (int j = 1; j <= nums2.size(); ++j) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                len = max(len, dp[i][j]);
            } 
        }
    }
    return len;
}
```

**Python**

```python 
def findLength(self, nums1: List[int], nums2: List[int]) -> int:
    dp = [[0] * (len(nums2) + 1) for _ in range(len(nums1) + 1)]
    length = 0

    for i in range(1, len(nums1) + 1):
        for j in range(1, len(nums2) + 1):
            if nums1[i - 1] == nums2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                length = max(length, dp[i][j])

    return length
```

**Golang**

```go
func findLength(nums1 []int, nums2 []int) int {
	length := 0
	d := make([][]int, len(nums1)+1)
	for i := range d {
		d[i] = make([]int, len(nums2)+1)
	}

	for i := 1; i <= len(nums1); i++ {
		for j := 1; j <= len(nums2); j++ {
			if nums1[i-1] == nums2[j-1] {
				d[i][j] = d[i-1][j-1] + 1
				length = max(length, d[i][j])
			}
		}
	}

	return length
}
```

