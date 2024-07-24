# 77. 组合

[点此跳转题目链接](https://leetcode.cn/problems/combinations/description/)

## 题目描述

给定两个整数 `n` 和 `k`，返回范围 `[1, n]` 中所有可能的 `k` 个数的组合。

你可以按 **任何顺序** 返回答案。

 

**示例 1：**

```
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

**示例 2：**

```
输入：n = 1, k = 1
输出：[[1]]
```

 

**提示：**

- `1 <= n <= 20`
- `1 <= k <= n`



## 题解

参考：[代码随想录-77.组合](https://programmercarl.com/0077.组合.html#算法公开课) ，讲得非常细了。

算是**回溯算法**的入门题目，核心要理解回溯的**树形结构**，以及其中的**横向**和**纵向**遍历逻辑：

<img src="./20201123195223940.png" alt="img" width="700" />

然后，考虑**回溯三部曲** :sparkles: 

:one: **处理** 

本题就是很基础的求组合，所以每次往当前组合 `path` 添加新数字就好了：

```cpp
path.push_back(i); 
```

> 当前组合名称取为 `path` ，旨在呼应回溯树形结构图中的纵向路线（先取一个数x，再取一个数y）

:two: **递归**

递归出口是经典的——当前组合大小达到目标组合大小，则将其加入结果集：

```cpp
if (path.size() == k)
{
    res.push_back(path);
    return;
}
```

否则，当前位置数字确定后，递归下一个位置的数来做组合：

```cpp
backTracking(i + 1, end, k)
```

:three: **回溯**

弹出当前组合的最后一个值，以便探索该位置的其他可能值：

```cpp
path.pop_back();   
```

整体代码如下：

**C++**

```cpp
class Solution
{
private:
    vector<int> path;
    vector<vector<int>> res;

public:
    void backTracking(int start, int end, int k)
    {
        // 回溯出口：子结果path已满（纵向遍历）
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        // 横向遍历
        for (int i = start; i <= end; i++)
        {
            path.push_back(i);           // 处理
            backTracking(i + 1, end, k); // 递归
            path.pop_back();             // 回溯
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backTracking(1, n, k);
        return res;
    }
};
```

**Go**

```go
type Helper struct {
	path []int
	res  [][]int
}

func (helper *Helper) backTracking(start int, end int, k int) {
	// 递归出口
	if len(helper.path) == k {
		// newPath := make([]int, len(helper.path))
		// copy(newPath, helper.path)
		// helper.res = append(helper.res, newPath)
		helper.res = append(helper.res, append([]int(nil), helper.path...))
		return
	}
	// 横向遍历
	for i := start; i <= end; i++ {
		helper.path = append(helper.path, i)           // 处理
		helper.backTracking(i+1, end, k)               // 递归
		helper.path = helper.path[:len(helper.path)-1] // 回溯
	}
}

func combine(n int, k int) [][]int {
	helper := Helper{}
	helper.backTracking(1, n, k)
	return helper.res
}
```

