# 18. 四数之和

[点此跳转题目链接](https://leetcode.cn/problems/4sum/description/)

## 题目描述

给你一个由 `n` 个整数组成的数组 `nums` ，和一个目标值 `target` 。请你找出并返回满足下述全部条件且**不重复**的四元组 `[nums[a], nums[b], nums[c], nums[d]]` （若两个四元组元素一一对应，则认为两个四元组重复）：

- `0 <= a, b, c, d < n`
- `a`、`b`、`c` 和 `d` **互不相同**
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

你可以按 **任意顺序** 返回答案 。

 

**示例 1：**

```
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**示例 2：**

```
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
```

 

**提示：**

- `1 <= nums.length <= 200`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`



## 题解

在做过**15. 三数之和**后，发现这题采用同样的思路解决，只不过在最外层添加一层遍历即可。三数之和的算法参见[我的笔记](https://github.com/Charles-T-T/Algorithm-Practice/tree/master/2nd-try/15)或[Carl的讲解](https://programmercarl.com/0015.三数之和.html#算法公开课)。

**代码（C++）**

```cpp
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    // 思路：双指针，在三数求和的基础上在外套一层循环即可
    // 记四元组为(a, b, c, d)
    // 分别对应代码中的(nums[i], nums[j], nums[left], nums[right])
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > target && nums[i] >= 0)
            break; // 剪枝
        if (i > 0 && nums[i - 1] == nums[i])
            continue; // 对a去重

        // 下面基本就是三数求和
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
                break; // 剪枝
            if (j > i + 1 && nums[j - 1] == nums[j])
                continue; // 对b去重

            int left = j + 1, right = nums.size() - 1;
            while (left < right)
            {
                long long curSum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[j])
                                    + static_cast<long long>(nums[left]) + static_cast<long long>(nums[right]);
                if (curSum == target)
                {
                    res.emplace_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++; // 对c去重
                    while (left < right && nums[right] == nums[right - 1])
                        right--; // 对d去重
                    left++, right--;
                }
                else if (curSum < target)
                    left++;
                else
                    right--;
            }
        }
    }
    return res;
}
```

