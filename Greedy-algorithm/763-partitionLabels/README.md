# 763. 划分字母区间

[点此跳转题目链接](https://leetcode.cn/problems/partition-labels/description/)

## 题目描述

给你一个字符串 `s` 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。

注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 `s` 。

返回一个表示每个字符串片段的长度的列表。

 

**示例 1：**

```
输入：s = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。 
```

**示例 2：**

```
输入：s = "eccbbbbdec"
输出：[10]
```

 

**提示：**

- `1 <= s.length <= 500`
- `s` 仅由小写英文字母组成



## 题解

根据题目要求，我们不难快速想到一个符合直觉的算法：在某个字母最后一次出现的地方分割，同时保证分割后的这一段中，其他字母也仅在这一段出现。

每个字母最后出现的位置容易解决，遍历一遍字符串、不断更新出现位置即可。而要保证分割后，其他字母也只在这段出现，则说明分割处的字母是这段子串里所有字母中，“最后出现位置”最靠后的的一个。所以我们只需要维护一个“当前出现的最后位置的最大值”即可，借用 [代码随想录](https://programmercarl.com/0763.划分字母区间.html#算法公开课) 中的图可以直观说明：

![763.划分字母区间](https://code-thinking-1253855093.file.myqcloud.com/pics/20201222191924417.png)

**代码（C++）**

```cpp
vector<int> partitionLabels(string s)
{
    // 找到每个字母最后一次出现的位置
    unordered_map<char, int> lastOccur;
    for (int i = 0; i < s.size(); ++i)
        lastOccur[s[i]] = i;
    vector<int> res;
    int curCount = 0;
    int curLastPos = -1;
    for (int i = 0; i < s.size(); ++i) {
        curLastPos = max(curLastPos, lastOccur[s[i]]);
        curCount++;
        if (curLastPos == i) {
            res.push_back(curCount);
            curCount = 0;
        }   
    }
    return res;
}
```

