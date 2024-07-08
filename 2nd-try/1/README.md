# 1. 两数之和

[点此跳转题目链接](https://leetcode.cn/problems/two-sum/description/)

## 题目描述

给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** *`target`* 的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

 

**示例 1：**

```
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**示例 2：**

```
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

**示例 3：**

```
输入：nums = [3,3], target = 6
输出：[0,1]
```

 

**提示：**

- `2 <= nums.length <= 104`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`
- **只会存在一个有效答案**

 

**进阶：**你可以想出一个时间复杂度小于 `O(n2)` 的算法吗？



## 题解

:see_no_evil: 梦开始的地方——LeetCode第 :one: 题

第一次写包是暴力解法的：遍历每一个数，每次再遍历一次以检查这个数和其他数求和能否得出 `target` 。这样的时间复杂度是 $O(n^2)$ 。

采用一个经典思路：求差法——先确定每个数 `num` 欲求和得到 `target` 所需的”另一半“，即 `target - num` ，再检查数组中有没有这些差之一。这样只需扫描两遍数组，时间复杂度为 $O(n)$ 。

**代码（C++）**

```cpp
vector<int> twoSum(vector<int> &nums, int target)
{
    // 哈希表解决：找数字所需的“另一半”
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); i++)
        numMap[nums[i]] = i;
    vector<int> res(2);
    for (int i = 0; i < nums.size(); i++) {
        if (numMap.find(target - nums[i]) != numMap.end() &&
            numMap[target - nums[i]] != i) {
            res[0] = i, res[1] = numMap[target - nums[i]];
            break;
        }
    }
    return res;
}
```

最近在学Golang，也练练手 :man_technologist: ​

**代码（Go）**

```go
func twoSum(nums []int, target int) []int {
	numMap := make(map[int]int)
	for i, num := range nums {
		numMap[num] = i
	}
	res := make([]int, 2)
	for i, num := range nums {
		pos, ok := numMap[target - num]
		if ok && pos != i {
			res[0] = pos
			res[1] = i
			break
		}
	}
	return res
}
```

