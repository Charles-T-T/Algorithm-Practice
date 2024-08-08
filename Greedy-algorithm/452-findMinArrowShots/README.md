# 452. 用最少数量的箭引爆气球

[点此跳转题目链接](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/)

## 题目描述

有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 `points` ，其中`points[i] = [x_start, x_end]` 表示水平直径在 `x_start` 和 `x_end`之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 **完全垂直** 地射出。在坐标 `x` 处射出一支箭，若有一个气球的直径的开始和结束坐标为 `x_start`，`x_end`， 且满足  `x_start ≤ x ≤ x_end`，则该气球会被 **引爆** 。可以射出的弓箭的数量 **没有限制** 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 `points` ，*返回引爆所有气球所必须射出的 **最小** 弓箭数* 。

 

**示例 1：**

```
输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：气球可以用2支箭来爆破:
-在x = 6处射出箭，击破气球[2,8]和[1,6]。
-在x = 11处发射箭，击破气球[10,16]和[7,12]。
```

**示例 2：**

```
输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4
解释：每个气球需要射出一支箭，总共需要4支箭。
```

**示例 3：**

```
输入：points = [[1,2],[2,3],[3,4],[4,5]]
输出：2
解释：气球可以用2支箭来爆破:
- 在x = 2处发射箭，击破气球[1,2]和[2,3]。
- 在x = 4处射出箭，击破气球[3,4]和[4,5]。
```



**提示:**

- `1 <= points.length <= 105`
- `points[i].length == 2`
- `-231 <= xstart < xend <= 231 - 1`



## 题解

贪心算法解决。先按照气球的左边界从小到大（按右边界同理）对 `points` 进行排序。然后，符合直觉地，应该依次尝试将下一个气球“纳入”当前的“命中范围”，从而将所有气球分成连续紧挨着的若干组，每组用一只箭即可“贯穿”。

这个“命中范围”的左边界就是当前气球左边界（最大的），右边界就是目前这组气球右边界的最小值。如果新的气球的左边界已经大于之前一组气球的右边界，即它肯定会与前一组气球的命中范围“错开”，则开始新一组。

**代码（C++）**

```cpp
int findMinArrowShots(vector<vector<int>> &points)
{
    auto cmp = [](const vector<int> &a, const vector<int> &b) {return a[0] < b[0];};
    sort(points.begin(), points.end(), cmp); // 先对points排序
    int count = 1;
    int curMin = points[0][0], curMax = points[0][1];
    for (int i = 1; i < points.size(); ++i) {
        if (points[i][0] > curMax) { // 需要开始新一组
            curMin = points[i][0], curMax = points[i][1];
            count++;
        } else 
            curMin = points[i][0], curMax = min(curMax, points[i][1]); // 更新左右边界
    }
    return count;
}
```

