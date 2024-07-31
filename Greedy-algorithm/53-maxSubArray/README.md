# 53. 最大子数组和

[点此跳转题目链接](https://leetcode.cn/problems/maximum-subarray/description/)

## 题目描述

给你一个整数数组 `nums` ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。



**子数组** 是数组中的一个连续部分（连续的 **非空** 元素序列）。



**示例 1：**

```
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```

**示例 2：**

```
输入：nums = [1]
输出：1
```

**示例 3：**

```
输入：nums = [5,4,-1,7,8]
输出：23
```

 

**提示：**

- `1 <= nums.length <= 105`
- `-104 <= nums[i] <= 104`

 

**进阶：** 如果你已经实现复杂度为 `O(n)` 的解法，尝试使用更为精妙的 **分治法** 求解。



## 题解

经典的贪心算法。在遍历过程中，如果当前子数组之和为 **负数** ，那么再往里面添加下一个数字，相当于减小了下一个数字。所以此时，我们可以贪心地直接将前面这个和为负子数组“累赘”丢掉：

```cpp
int maxSubArray(vector<int> &nums)
{
    // 贪心算法
    int curSum = 0, maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        curSum += nums[i];
        maxSum = max(curSum, maxSum);
        if (curSum < 0) // 当前子数组和为负，就是个“累赘”，丢掉
            curSum = 0; 
    }
    return maxSum;
}
```

也可以进一步简化，更优雅：

```cpp
int maxSubArray(vector<int> &nums)
{
    int curSum = nums[0], maxSum = curSum;
    for (int i = 1; i < nums.size(); ++i) {
        curSum = max(curSum + nums[i], nums[i]);
        maxSum = max(curSum, maxSum);
    }
    return maxSum;
}
```

