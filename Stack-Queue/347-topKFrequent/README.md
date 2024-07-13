# 347. 前K个高频元素

[点此跳转题目链接](https://leetcode.cn/problems/top-k-frequent-elements/description/)

## 题目描述

给你一个整数数组 `nums` 和一个整数 `k` ，请你返回其中出现频率前 `k` 高的元素。你可以按 **任意顺序** 返回答案。

 

**示例 1:**

```
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
```

**示例 2:**

```
输入: nums = [1], k = 1
输出: [1]
```

 

**提示：**

- `1 <= nums.length <= 105`
- `k` 的取值范围是 `[1, 数组中不相同的元素的个数]`
- 题目数据保证答案唯一，换句话说，数组中前 `k` 个高频元素的集合是唯一的

 

**进阶：** 你所设计算法的时间复杂度 **必须** 优于 `O(n log n)` ，其中 `n` 是数组大小。



## 题解

将问题拆解，依次解决：

:one: 记录数组中元素出现的频率：容易想到用哈希表实现，key：元素；value：出现次数。

:two: 统计高频词汇：找到哈希表中，value最高的k个key，也就是要对整个哈希表按照value排序。比较方便的方法就是采用优先队列，将所有键值对按照value大小加入其中，队列最前面的k个元素即为所求。

**代码（C++）**

```cpp
vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> res;
    auto cmp = [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    unordered_map<int, int> freqMap;
    for (int num : nums)
        freqMap[num]++;
    for (auto pair : freqMap)
        pq.push(pair);
    for (int i = 0; i < k; i++) {
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}
```

