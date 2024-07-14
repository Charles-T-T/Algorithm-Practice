# 239. 滑动窗口最大值

[点此跳转题目链接](https://leetcode.cn/problems/sliding-window-maximum/)

## 题目描述

给你一个整数数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 `k` 个数字。滑动窗口每次只向右移动一位。

返回 *滑动窗口中的最大值* 。

 

**示例 1：**

```
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**示例 2：**

```
输入：nums = [1], k = 1
输出：[1]
```

 

**提示：**

- `1 <= nums.length <= 105`
- `-104 <= nums[i] <= 104`
- `1 <= k <= nums.length`



## 题解

> LeetCode标记 $\textcolor{red}{\text{困难}}$ 题目

题目不难理解，可以先无脑写出暴力解法：

```cpp
vector<int> maxSlidingWindowViolence(vector<int> &nums, int k)
{
    vector<int> res;
    int left = 0, right = k - 1;
    while (right < nums.size())
    {
        int maxNum = nums[left];
        for (int i = left + 1; i <= right; i++)
            maxNum = max(maxNum, nums[i]);
        res.push_back(maxNum);
        left++, right++;
    }
    return res;
}
```

不出意外地，在数据量大时超时了 :speak_no_evil: 

进一步研究不难发现，每次窗口滑动，其实只有**最左**和**最右**的值改变了——这容易让人联想到**队列**数据结构（出队、入队只改变队头、队尾）。如果用队列存储一个窗口中的值，每次只需要

- 将上一次的左边界值出队列
- 将这一次的右边界入队列

但是有一个问题：如何维护窗口最大值？显然，普通的队列无法每次快速找出队中最大值。一个容易联想到的方法是用优先队列（如c++中的 `priority_queue` ），但是优先队列每次出队的都是最大值，而这个值（很）可能不是左边界值。

更进一步思考，可以发现其实左右边界也不总是需要考虑的——关键在于，维护“这个窗口的最大值”和“可能在下一个窗口中成为最大值的值”，每次取这些数中的最大值加入结果，并尝试把新的右边界值加入其中，这样需要维护的数就变少了不少。

所以针对这题，我们理想的数据结构是一种特殊的队列：

- 按序存储（窗口中的）一部分数据，便于快速取出最大值
- 每次滑动窗口、更新队列时，如果原来的最大值恰是原来的左边界值，需要将其出队

这样的数据结构（特殊的单调队列）没有现成的，需要手动搓出来，之后的代码就简单了：每次尝试出队、入队、取队头（最大值）加入结果即可。

**代码**

**c++**

```cpp
// 用于解题的单调队列，原则：队列中元素单调递减
class MyQueue
{
private:
    deque<int> q; // 双端队列

public:
    void push(int num)
    {
        while (!q.empty() && q.back() < num)
            q.pop_back();
        q.push_back(num);
    }

    void pop() { q.pop_front(); }

    int front() { return q.front(); }
};

// 解题函数
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> res;
    MyQueue q;
    for (int i = 0; i < k; ++i) 
        q.push(nums[i]);
    res.push_back(q.front());
    int left = 1, right = k;
    while (right < nums.size()) {
        if (nums[left - 1] == q.front())
            q.pop();
        q.push(nums[right]);
        res.push_back(q.front());
        left++, right++;
    }
    return res;
}
```

**go**

```go
type MyQueue struct {
	q []int
}

func (mq MyQueue) front() int {
	return mq.q[0]
}

func (mq MyQueue) back() int {
	return mq.q[len(mq.q)-1]
}

func (mq *MyQueue) pop() {
	mq.q = mq.q[1:len(mq.q)]
}

func (mq *MyQueue) push(num int) {
	for len(mq.q) != 0 && mq.back() < num {
		mq.q = mq.q[0 : len(mq.q)-1]
	}
	mq.q = append(mq.q, num)
}

func maxSlidingWindow(nums []int, k int) []int {
	res := []int{}
	mq := MyQueue{}
	for i := 0; i < k; i++ {
		mq.push(nums[i])
	}
	res = append(res, mq.front())
	left, right := 1, k
	for right < len(nums) {
		if nums[left-1] == mq.front() {
			mq.pop()
		}
		mq.push(nums[right])
		res = append(res, mq.front())
		left++
		right++
	}
	return res
}
```

该思路更详细的讲解参见 [代码随想录——滑动窗口最大值](https://programmercarl.com/0239.滑动窗口最大值.html#算法公开课) 。