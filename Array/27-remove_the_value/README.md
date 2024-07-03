# 27. 移除元素

[点此跳转LeetCode题目链接](https://leetcode.cn/problems/remove-element/description/)

## 题目描述

给你一个数组 `nums` 和一个值 `val`，你需要 **[原地](https://baike.baidu.com/item/原地算法)** 移除所有数值等于 `val` 的元素。元素的顺序可能发生改变。然后返回 `nums` 中与 `val` 不同的元素的数量。

假设 `nums` 中不等于 `val` 的元素数量为 `k`，要通过此题，您需要执行以下操作：

- 更改 `nums` 数组，使 `nums` 的前 `k` 个元素包含不等于 `val` 的元素。`nums` 的其余元素和 `nums` 的大小并不重要。
- 返回 `k`。



**用户评测：**

评测机将使用以下代码测试您的解决方案：

```cpp
int[] nums = [...]; // 输入数组
int val = ...; // 要移除的值
int[] expectedNums = [...]; // 长度正确的预期答案。
                            // 它以不等于 val 的值排序。

int k = removeElement(nums, val); // 调用你的实现

assert k == expectedNums.length;
sort(nums, 0, k); // 排序 nums 的前 k 个元素
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
```

如果所有的断言都通过，你的解决方案将会 **通过**。

 

**示例 1：**

```sh
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2,_,_]
解释：你的函数函数应该返回 k = 2, 并且 nums 中的前两个元素均为 2。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
```

**示例 2：**

```sh
输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,4,0,3,_,_,_]
解释：你的函数应该返回 k = 5，并且 nums 中的前五个元素为 0,0,1,3,4。
注意这五个元素可以任意顺序返回。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
```

 

**提示：**

- `0 <= nums.length <= 100`
- `0 <= nums[i] <= 50`
- `0 <= val <= 100`



## 题解

双指针的经典入门题目，当初也是通过这个题第一次感受到双指针的妙处所在 :laughing: 

首先暴力解法就不细说了，两重循环，遇到等于 `val` 的地方就把后面的数全部往前移一位（即删除数组中间元素的一般方法），时间复杂度为 $O(n^2)$ ，低效。

我们采用双指针法，定义快、慢两个指针来遍历数组，其中快指针将找到的**不等于 `val` 的数**写入慢指针的位置 。这样，快指针的位置一定**大于等于**慢指针，故双指针可以在同一轮遍历中完成各自工作，时间复杂度降低为 $O(n)$ 。

#### 代码

```cpp
int removeElement(vector<int> &nums, int val)
{
    // 思路：双指针，检测指针（快）在填充指针（慢）之前移动
    int fast = 0, slow = 0;
    while (fast < nums.size())
    {
        if (nums[fast] != val)
            nums[slow++] = nums[fast];
        fast++;
    }
    return slow; // 显然此时的slow恰好就是nums中不等于val的元素的数量
}
```

