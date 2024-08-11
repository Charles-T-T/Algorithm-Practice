# 56. 合并区间

[点此跳转题目链接](https://leetcode.cn/problems/merge-intervals/description/)

## 题目描述

以数组 `intervals` 表示若干个区间的集合，其中单个区间为 `intervals[i] = [starti, endi]` 。请你合并所有重叠的区间，并返回 *一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间* 。

 

**示例 1：**

```
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

**示例 2：**

```
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
```

 

**提示：**

- `1 <= intervals.length <= 104`
- `intervals[i].length == 2`
- `0 <= starti <= endi <= 104`



## 题解

贪心算法解决。这题和 [435. 无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals/description/) 很像，参考我那题的 [笔记](https://blog.csdn.net/weixin_54468359/article/details/141028132?spm=1001.2014.3001.5501) ，可以采用类似的解法：

首先，将这些区间按照左边界从小到大排序。接着，尽量将下一个区间“纳入”当前区间，判断方法也很直观： **下一个区间的左边界** 不大于 **当前区间的右边界** ，就可以将其纳入当前区间。否则将下一个区间作为新的区间，计数。

**代码（C++）**

```cpp
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    // 贪心算法：先按左边界排序，再依次合并
    auto cmp = [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    };
    sort(intervals.begin(), intervals.end(), cmp);

    vector<vector<int>> res;
    int left = intervals[0][0], right = intervals[0][1];
    for (int i = 0; i < intervals.size(); ++i) {
        if (intervals[i][0] > right) {
            res.emplace_back(vector<int>{left, right});
            left = intervals[i][0], right = intervals[i][1];
        } else 
            right = max(right, intervals[i][1]);

        if (i == intervals.size() - 1)
            res.emplace_back(vector<int>{left, right});
    }
    return res;
}
```

