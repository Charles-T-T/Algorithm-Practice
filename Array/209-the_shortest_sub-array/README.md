# 209. 长度最小的子数组

[点此跳转题目链接](https://leetcode.cn/problems/minimum-size-subarray-sum/description/)

## 题目描述

给定一个含有 `n` 个正整数的数组和一个正整数 `target` 。

找出该数组中满足其总和大于等于 `target` 的长度最小的 **子数组** `[numsl, numsl+1, ..., numsr-1, numsr]` ，并返回其长度。如果不存在符合条件的子数组，返回 `0` 。



**示例 1：**

```sh
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
```

**示例 2：**

```sh
输入：target = 4, nums = [1,4,4]
输出：1
```

**示例 3：**

```sh
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
```

 

**提示：**

- `1 <= target <= 109`
- `1 <= nums.length <= 105`
- `1 <= nums[i] <= 105`

 

**进阶：**

- 如果你已经实现 `O(n)` 时间复杂度的解法, 请尝试设计一个 `O(n log(n))` 时间复杂度的解法。



## 题解

典型的**双指针**构造**滑动窗口**题目。定义快慢双指针，其中：

:one: 快慢双指针都初始化为0

:two: 快指针前进一个单位（越界则返回）

:three: 当前快慢指针之间（含指针所指元素）这个 **“窗口”** 中元素之和是否大于等于 `target` ：是则下一步，否则上一步

:four: 更新最小长度，慢指针前进一个单位，回到上一步

这样就做到了整体上只遍历一次数组，动态更新最小长度来求解。

### 代码

```cpp
int minSubArrayLen(int target, vector<int> &nums)
{
    // 思路：采用快慢双指针，构成一个滑动窗口，动态更新最短长度
    int slow = 0, fast = 0;
    const int MAX = numeric_limits<int>::max();
    int minLen = MAX;
    int curSum = nums[fast];
    while (1)
    {
        if (curSum >= target)
        {
            minLen = min(minLen, fast - slow + 1);
            curSum -= nums[slow];
            slow++;
        }
        else
        {
            fast++;
            if (fast >= nums.size())
                break;
            curSum += nums[fast];
        }
    }
    return minLen == MAX ? 0 : minLen;
}
```

下面附上Carl哥的版本，思路一致，代码比我更简洁规范些：

```cpp
int minSubArrayLen_Carl(int target, vector<int> &nums)
{
    int left = 0, right = 0;
    int length = 1e6;
    int sum = 0;

    for (right = 0; right < nums.size(); right++)
    {
        sum += nums[right];
        while (sum >= target)
        {
            int curLength = right - left + 1;
            length = curLength < length ? curLength : length;
            sum -= nums[left++];
        }
    }

    return length == 1e6 ? 0 : length;
}
```

> 本题进一步解析见卡哥文章：[代码随想录 (programmercarl.com)](https://programmercarl.com/0977.有序数组的平方.html#其他语言版本) 