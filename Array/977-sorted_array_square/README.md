# 977. 有序数组的平方

[点此跳转题目链接](https://leetcode.cn/problems/squares-of-a-sorted-array/description/)

## 题目描述

给你一个按 **非递减顺序** 排序的整数数组 `nums`，返回 **每个数字的平方** 组成的新数组，要求也按 **非递减顺序** 排序。



**示例 1：**

```sh
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
```

**示例 2：**

```sh
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
```

 

**提示：**

- `1 <= nums.length <= 104`
- `-104 <= nums[i] <= 104`
- `nums` 已按 **非递减顺序** 排序

 

**进阶：**

- 请你设计时间复杂度为 `O(n)` 的算法解决本问题



## 题解

暴力算法很容易想到：遍历数组 :arrow_right: 将其中每个数都平方 :arrow_right: 将数组排序，直接调用库函数就行。

```cpp 
vector<int> sortedSquares_Violence(vector<int> &nums)
{
    // 暴力解法：先平方再排序
    for (int i = 0; i < nums.size(); i++)
        nums[i] = pow(nums[i], 2);
    sort(nums.begin(), nums.end());
    return nums;
}
```

但是这种算法**没意思** ( :dog: )，而且时间复杂度较高——遍历一遍要 $O(n)$ ， `std::sort()` 要 $O(n log{n})$ 。

我们考虑用**双指针**：定义左、右两个指针指向数组的最左和最右元素，由于数组**有序**且**可能有负数**，平方之后最大的数总是在最左和最右端。因此，可以：

- 比较左右指针指向元素的**平方值**
- 将**大的**加到结果数组中（倒序加入，因为要求结果是升序排列）
- 相应的那个指针**向中间**移动
- 重复上述步骤直到双指针交汇，结束

### 代码

```cpp
vector<int> sortedSquares(vector<int> &nums)
{
    // 思路：左右双指针
    // 原数组可能有负数，这样平方之后，“两头”的数总是最大的
    vector<int> res(nums.size());
    int curLast = res.size() - 1; // 待填入的位置
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int ls = pow(nums[left], 2);
        int rs = pow(nums[right], 2);
        if (ls > rs)
        {
            res[curLast--] = ls;
            left++;
        }
        else
        {
            res[curLast--] = rs;
            right--;
        }
    }
    return res;
}
```

