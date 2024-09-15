# 72. 编辑距离

[点此跳转题目链接](https://leetcode.cn/problems/edit-distance/description/)

## 题目描述

给你两个单词 `word1` 和 `word2`， *请返回将 `word1` 转换成 `word2` 所使用的最少操作数* 。

你可以对一个单词进行如下三种操作：

- 插入一个字符
- 删除一个字符
- 替换一个字符

 

**示例 1：**

```
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
```

**示例 2：**

```
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
```

 

**提示：**

- `0 <= word1.length, word2.length <= 500`
- `word1` 和 `word2` 由小写英文字母组成



## 题解

这题感觉是**动态规划子序列问题**里比较综合的了，得对 `dp` 数组的意义和用法有比较好的认识才行。

> :link: 以下内容主要基于 [LeetCode官方题解](https://leetcode.cn/problems/edit-distance/solutions/188223/bian-ji-ju-chi-by-leetcode-solution/) 

根据题目，我们可以对任意一个单词进行三种操作：

- 插入一个字符
- 删除一个字符
- 替换一个字符

我们将给定的两个单词分别记为 `A` 和 `B` ，那么一共就有6种操作。

> 我感觉题目的描述有些误导性 :thinking: ：所谓 “将 `word1` 转换成 `word2` ” 并不是说 `word2` 不变、让 `word1` 往 `word2` 变，而是说通过对这两个单词的操作，最终使它俩相同。
>
> 因此，下面将 “ `A` 到 `B` 的编辑距离” 之类的表达统一改为 “ `A` 和 `B` 的编辑距离” ，以免歧义

不过，可以发现：

- **对单词 `A` 删除一个字符和对单词 `B` 插入一个字符是等价的。** 例如当单词 `A` 为 `doge` ，单词 `B` 为 `dog` 时，我们既可以删除单词 `A` 的最后一个字符 `e`，得到相同的 `dog` ，也可以在单词 `B` 末尾添加一个字符 `e` ，得到相同的 `doge` 
- 同理， **对单词 `B` 删除一个字符和对单词 `A` 插入一个字符也是等价的** 
- **对单词 `A` 替换一个字符和对单词 `B` 替换一个字符是等价的。** 例如当单词 `A` 为 `bat` ，单词 `B` 为 `cat` 时，我们修改单词 `A` 的第一个字母 `b -> c` ，和修改单词 `B` 的第一个字母 `c -> b` 是等价的

所以，实际上我们只需要考虑**三种**不同的操作：

- 在 `A` 中插入一个字符
- 在 `B` 中插入一个字符
- 替换 `A` 中的一个字符

下面，以 `A = "horse"` 和 `B = "ros"` 为例进一步探索：

- **在 `A` 中插入一个字符：** 如果我们知道 `horse` 和 `ro` （即 `A` 到 `B - 's'` ）的编辑距离为 `a` ，那么显然 `horse` 和 `ros` （即 `A` 和 `B` ）的编辑距离不会超过 `a + 1` 。这是因为我们可以在 `a` 次操作后将 `A` 和 `B - 's'` 变为相同的字符串，只需要额外的 `1` 次操作，在单词 `A` 的末尾添加字符 `'s'` ，就能在 `a + 1` 次操作后将 `A` 和 `B` 变为相同的字符串

- **在 B 中插入一个字符：** 如果我们知道 `hors` 到 `ros` 的编辑距离为 `b` ，那么显然 `horse` 到 `ros` 的编辑距离不会超过 `b + 1` ，原因同上

- **替换 `A` 的一个字符：** 如果我们知道 `hors` 到 `ro` 的编辑距离为 `c` ，那么显然 `horse` 到 `ros` 的编辑距离不会超过 `c + 1` ，原因同上（可以理解为：两个单词经过 `c` 次操作已经相同了，此时它们末尾各新增了一个字符且不相同，那么将其中一个替换成另一个就行了）

综上所述， `horse` 和 `ros` 的编辑距离应该为 `min(a + 1, b + 1, c + 1)` 。

不过对于第三种情况，如果两个单词新增的字符是相同的，自然不用替换，操作次数仍是 `c` 。

> :warning: 注意：为什么我们总是在单词 `A` 和 `B` 的末尾插入或者修改字符，能不能在其它的地方进行操作呢？
>
> 答案是可以的，但是我们知道，操作的顺序是不影响最终的结果的。例如对于单词 `cat` ，我们希望在 `c` 和 `a` 之间添加字符 `d` 并且将字符 `t` 修改为字符 `b` ，那么这两个操作无论为什么顺序，都会得到最终的结果 `cdab` 。

于是我们可以开始分析动态规划的老朋友们：

- `dp` 数组的含义： `dp[i][j]` 表示 `word1` 的前 `i` 个字符组成的子串（即 `word1[0...i-1]` ）和 `word2` 的前 `j` 个字符组成的子串（即 `word2[0...j-1]` ）的编辑距离

- 几个操作对应的状态：基于前面的分析可知

  - 在 `word1` 中插入一个字符，对应 `dp[i - 1][j] + 1` 
  - 在 `word2` 中插入一个字符，对应 `dp[i][j - 1] + 1` 
  - 在某个单词中替换一个字符，对应 `dp[i - 1][j - 1] + 1` 

- 状态转移方程：

  - 如果 `word1[i - 1] == word2[j - 1]` ，则 “替换” 的操作是可以免除的，所以有 `dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1]})` 
  - 否则，上述三种状态取最小值，即 `dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1` 

- 初始化：如果某个单词是空串（长度为0），那么编辑过程无非两种

  - 向空串逐个插入另一个单词的字符，操作数为另一个单词的长度
  - 将另一个单词中的字符逐个删除，操作数仍为它的长度

  所以初始化 `dp` 数组中 `dp[i][0] = i` ， `dp[0][j] = j` 。

**代码（C++）**

```cpp
int minDistance(string word1, string word2)
{
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 1; i <= word1.size(); ++i)
        dp[i][0] = i;
    for (int j = 1; j <= word2.size(); ++j) 
        dp[0][j] = j;

    for (int i = 1; i <= word1.size(); ++i) {
        for (int j = 1; j <= word2.size(); ++j) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1]});
            else
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
    }

    return dp[word1.size()][word2.size()];
}
```

**Python**

```python
def minDistance(self, word1: str, word2: str) -> int:
    dp = [[0] * (len(word2) + 1) for _ in range(len(word1) + 1)]

    for i in range(1, len(word1) + 1):
        dp[i][0] = i
    for j in range(1, len(word2) + 1):
        dp[0][j] = j

    for i in range(1, len(word1) + 1):
        for j in range(1, len(word2) + 1):
            if word1[i - 1] == word2[j - 1]:
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1])
            else:
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1

    return dp[-1][-1]
```

**Golang**

```go
func minDistance(word1 string, word2 string) int {
	dp := make([][]int, len(word1)+1)
	for i := range dp {
		dp[i] = make([]int, len(word2)+1)
	}

	for i := 1; i <= len(word1); i++ {
		dp[i][0] = i
	}
	for j := 1; j <= len(word2); j++ {
		dp[0][j] = j
	}

	for i := 1; i <= len(word1); i++ {
		for j := 1; j <= len(word2); j++ {
			if word1[i-1] == word2[j-1] {
				dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1])
			} else {
				dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
			}
		}
	}

	return dp[len(word1)][len(word2)]
}
```

