# 93. 复原 IP 地址

[点此跳转题目链接](https://leetcode.cn/problems/restore-ip-addresses/description/)

## 题目描述

**有效 IP 地址** 正好由四个整数（每个整数位于 `0` 到 `255` 之间组成，且不能含有前导 `0`），整数之间用 `'.'` 分隔。

- 例如：`"0.1.2.201"` 和` "192.168.1.1"` 是 **有效** IP 地址，但是 `"0.011.255.245"`、`"192.168.1.312"` 和 `"192.168@1.1"` 是 **无效** IP 地址。

给定一个只包含数字的字符串 `s` ，用以表示一个 IP 地址，返回所有可能的**有效 IP 地址**，这些地址可以通过在 `s` 中插入 `'.'` 来形成。你 **不能** 重新排序或删除 `s` 中的任何数字。你可以按 **任何** 顺序返回答案。

 

**示例 1：**

```
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
```

**示例 2：**

```
输入：s = "0000"
输出：["0.0.0.0"]
```

**示例 3：**

```
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
```

 

**提示：**

- `1 <= s.length <= 20`
- `s` 仅由数字组成



## 题解

回溯算法解决，整体思路和 [131. 分割回文串](https://leetcode.cn/problems/palindrome-partitioning/description/) 差不多，可参见其 [对应题解](https://github.com/Charles-T-T/Algorithm-Practice/tree/master/Back-tracking/131-partition) 。

需要注意的主要是一些细节方面的问题，比如：

- 分割成功的标志为：
  - 恰好分为4段
  - 每段都是[0, 255]之间的整数，且不能有先导0
- 每次添加一段时，还要添加 `.` 
- 回溯时，要删除上次添加的整个子串和 `.` 

代码实现如下，思路及细节处理见注释：

```cpp
class Solution
{
private:
    string ip;
    vector<string> res;
    int partCount = 0; // 有效ip地址应由4个部分组成
    bool isLegalIpPart(const string &s) {
        if (s.size() > 1 && s[0] == '0') // 不能含有前导0
            return false;
        if (s.size() > 3) // 不能超过3位（最大255）
            return false;
        return stoi(s) >= 0 && stoi(s) <= 255;
    }

public:
    void backTracking(const string &s, int cutPos) {
        // 递归出口：分割位置到达字符串末尾，或分割出大于4个部分（纵向遍历）
        if (partCount > 4)
            return;
        if (cutPos >= s.size()) {
            if (partCount == 4)
                res.push_back(ip.substr(1, ip.size() - 1)); // 注意ip开头的'.'要去除
            return;
        }

        // 横向遍历
        for (int i = cutPos; i < s.size(); ++i) {
            // 处理
            string sub = s.substr(cutPos, i - cutPos + 1);
            if (!isLegalIpPart(sub))
                continue;
            ip += "." + sub;
            partCount++;
            // 递归
            backTracking(s, i + 1);
            // 回溯
            while (!ip.empty() && ip.back() != '.') 
                ip.pop_back(); // 删除上次添加的子串
            if (!ip.empty())
                ip.pop_back(); // 删除结尾的 '.'
            partCount--;
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        backTracking(s, 0);
        return res;
    }
};
```

