# 45. 跳跃游戏 II

[点此跳转题目链接](https://leetcode.cn/problems/jump-game-ii/description/)

## 题目描述

给定一个长度为 `n` 的 **0 索引**整数数组 `nums`。初始位置为 `nums[0]`。

每个元素 `nums[i]` 表示从索引 `i` 向前跳转的最大长度。换句话说，如果你在 `nums[i]` 处，你可以跳转到任意 `nums[i + j]` 处:

- `0 <= j <= nums[i]` 
- `i + j < n`

返回到达 `nums[n - 1]` 的最小跳跃次数。生成的测试用例可以到达 `nums[n - 1]`。

 

**示例 1:**

```
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
```

**示例 2:**

```
输入: nums = [2,3,0,1,4]
输出: 2
```

 

**提示:**

- `1 <= nums.length <= 104`
- `0 <= nums[i] <= 1000`
- 题目保证可以到达 `nums[n-1]`



## 题解

这题基于 [55. 跳跃游戏](https://leetcode.cn/problems/jump-game/description/) ，保证能到达终点，要求最小跳跃次数。和 [55题的题解](https://github.com/Charles-T-T/Algorithm-Practice/tree/master/Greedy-algorithm/55-canJump) 一样，核心思想仍是采用 **“覆盖区间”** 来进行探索：

```cpp
int jump(vector<int> &nums)
{
    int farDist = 0; // 能到达的最远距离
    int cover = 0;   // 当前的覆盖区间（右边界）
    int count = 0;   // 跳跃次数
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        farDist = max(farDist, i + nums[i]);
        if (i >= cover) // 到达当前覆盖的最远距离
        {
            count++;         // 必须再跳一步才能跳出当前覆盖区间
            cover = farDist; // 更新覆盖区间
        }
        if (cover >= nums.size() - 1) // 到达数组末尾
            return count;
    }
    return count;
}
```

