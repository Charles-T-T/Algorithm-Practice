# 454. 四数相加 II

[点此跳转题目链接](https://leetcode.cn/problems/4sum-ii/description/)

## 题目描述

给你四个整数数组 `nums1`、`nums2`、`nums3` 和 `nums4` ，数组长度都是 `n` ，请你计算有多少个元组 `(i, j, k, l)` 能满足：

- `0 <= i, j, k, l < n`
- `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`

 

**示例 1：**

```
输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
输出：2
解释：
两个元组如下：
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
```

**示例 2：**

```
输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
输出：1
```

 

 **提示：**

- `n == nums1.length`
- `n == nums2.length`
- `n == nums3.length`
- `n == nums4.length`
- `1 <= n <= 200`
- `-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228`



## 题解

由于从一个数组中取出四元组，暴力求解时间复杂度高达 $O(n^4)$ ，故考虑分治方法，将四元组 `(a, b, c, d)` 分为 `a, b` 和 `c, d` 两部分，让这两部分求和为0即可。利用哈希表可以分别用两个双重循环实现，时间复杂度为 $O(n^2)$ 。

**代码**

**c++**

```cpp
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    // 思路：哈希表 + 分治
    int count = 0;
    unordered_map<int, int> sumMap; // 存储前两个数a + b各种求和结果出现的次数
    for (int a : nums1) {
        for (int b : nums2)
            sumMap[a + b]++;
    }
    // 根据后两个数的和c + d，找凑成0所需的差-(c + d)是否能由之前的a + b得出
    for (int c : nums3) {
        for (int d : nums4)
            count += sumMap[- c - d];
    }
    return count;
}
```

**go**

```go
func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
	abSumMap := make(map[int]int)
	for _, a := range nums1 {
		for _, b := range nums2 {
			abSumMap[a+b]++
		}
	}
	count := 0
	for _, c := range nums3 {
		for _, d := range nums4 {
			count += abSumMap[-c-d]
		}
	}
	return count
}
```

