# 349. 两个数组的交集

[点此跳转题目链接](https://leetcode.cn/problems/intersection-of-two-arrays/description/)

## 题目描述

给定两个数组 `nums1` 和 `nums2` ，返回它们的 **交集** 。输出结果中的每个元素一定是 **唯一** 的。我们可以 **不考虑输出结果的顺序** 。



**示例 1：**

```
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
```

**示例 2：**

```
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
```

 

**提示：**

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 1000`



## 题解

看到求“交集”自然想到用哈希集合解决。:warning: 要注意的就是题目中说了”输出结果中的每个元素一定是 **唯一** 的“，所以要注意添加元素到结果集合时检查唯一性。

**代码（C++）**

```cpp
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    // 哈希表秒了
    unordered_map<int, bool> numMap;
    vector<int> res;
    for (int num : nums1)
        numMap[num] = true;
    for (int num : nums2) {
        if (numMap[num]) {
            res.push_back(num);
            numMap[num] = false; // 防止重复添加
        }
    }
    return res;
}
```

