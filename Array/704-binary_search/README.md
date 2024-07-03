# 704. 二分查找

[点此跳转LeetCode题目链接](https://leetcode.cn/problems/binary-search/)

## 题目描述

给定一个 `n` 个元素有序的（升序）整型数组 `nums` 和一个目标值 `target` ，写一个函数搜索 `nums` 中的 `target`，如果目标值存在返回下标，否则返回 `-1`。



**示例 1:**

>**输入:** `nums`  = [-1,0,3,5,9,12],  `target`  = 9
**输出:** 4
**解释:** 9 出现在 `nums` 中并且下标为 4

**示例 2:**

>**输入:** `nums` = [-1,0,3,5,9,12], `target` = 2
**输出:** -1
**解释:** 2 不存在 `nums` 中因此返回 -1




**提示：**

1. 你可以假设 `nums` 中的所有元素是不重复的。
2. `n` 将在 `[1, 10000]`之间。
3. `nums` 的每个元素都将在 `[-9999, 9999]`之间。



## 思路

数组处理的入门经典题目。首先确定题目符合二分查找的基本要求：

- 数组是有序的（升序降序无所谓，底层逻辑都是一样的）
- 数组中无重复元素（否则我该返回给你哪个下标呢？）

二分查找的基本思路中学数学课就讲过了，不再赘述，无非是“检查区间中点是否为目标——不是就将区间对半开，在有目标的半区间接着找”这一过程的循环。这里比较关键的问题在于**区间的定义和更新**，下面展示区间为“左闭右闭”和“左闭右开”的两种写法。

### 左闭右闭

即区间为 **[left, right]** ，此时

- 初始化 `left` , `right` 就是数组的左右确界值（由闭区间定义可得）

- 循环条件为 `while (left <= right)` （ `left == right` 是有意义的，即左右指针指向同一个值）
- 当 `nums[middle] < target` 时，说明 `target` 在右半区间，更新 `left` 为 `middle + 1` （“左闭”，故可以不检查 `middle` ，即不用只让 `left = middle` ）
- 当 `nums[middle] > target` 时，说明 `target` 在左半区间，更新 `right` 为 `middle - 1` （同上）

#### 代码（c++）

```c++
int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int middle;
    while (left <= right)
    {
        middle = left + (right - left) / 2; // 防溢出的写法
        if (nums[middle] == target)
            return middle;
        if (nums[middle] < target)
        {
            left = middle + 1;
            continue;
        }
        if (nums[middle] > target)
        {
            right = middle - 1;
            continue;
        }
    }
    return -1; // target不存在于nums中
}
```

> 这里的 `middle = left + (right - left) / 2` 和 `middle = (left + right) / 2` 显然作用相同，但是规避了数组长度很大时 `right + left` 可能出现的溢出问题。

### 左闭右开

即区间为 **[left, right)** ，此时

- 初始化 `left` 是数组的左确界值， `right` 是数组右确界+1、即 `nums.size()` （由半闭半开区间定义可得）

- 循环条件为 `while (left < right)` （ `left == right` 无意义，因为 `right` 实际上是取不到的）
- 当 `nums[middle] < target` 时，说明 `target` 在右半区间，更新 `left` 为 `middle + 1` （同上）
- 当 `nums[middle] > target` 时，说明 `target` 在左半区间，更新 `right` 为 `middle` （因为实际上取不到 `right` ，要处理的还是和上面一样的 `middle - 1` ）

#### 代码

```c++
int searchII(vector<int> &nums, int target)
{
    int left = 0, right = nums.size(); // 这里体现了“右开”
    int middle;
    while (left < right)
    {
        middle = left + (right - left) / 2;
        if (nums[middle] == target)
            return middle;
        if (nums[middle] < target)
        {
            // “左闭”意味着不用再检查左边界
            left = middle + 1;
            continue;
        }
        if (nums[middle] > target)
        {
            // “右开”意味着要检查右边界
            right = middle;
            continue;
        }
    }
    return -1;
}
```

我感觉还是左闭右闭比较直观，更好理解；不过左闭右开也可以加深对二分机制的理解。

