#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

示例 1:
输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。

示例 2:
输入: s = "aba"
输出: false

示例 3:
输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)

提示：
1 <= s.length <= 104
s 由小写英文字母组成
*/

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // 如果可以由一个子串重复多次构成，则该子串肯定在开头就能找到
        for (int len = 1; len <= s.size() / 2; len++) {
            if (s.size() % len != 0) // 原串长必为重复子串长的整数倍
                continue;
            string sub = s.substr(0, len);
            int start = len;
            for (start; start < s.size(); start += len) {
                string tempSub = s.substr(start, len);
                if (tempSub != sub)
                    break;
            }
            if (start >= s.size())
                return true;
        }
        return false;
    }

    bool repeatedSubstringPatternII(string s) {
        // 优雅：如果s能由子串sub重复多次构成
        // 即s表示为 sub sub ... sub sub（n个sub）
        // 那么两个s首尾相连得到的还是 sub sub ... sub sub（2n个sub）
        // 这其中又会拼出若干新的s
        // 掐头去尾之后，如果还能找到，那么s能由sub重复构成
        string ts = s + s;
        ts.erase(ts.begin()), ts.erase(ts.end() - 1); // 掐头去尾
        if (ts.find(s) != string::npos)
            return true;
        return false;
    }

    bool repeatedSubstringPatternIII(string s)
    {
        return (s.substr(1, s.size() - 1).append(s.substr(0, s.size() - 1))).find(s) != string::npos;
    }

    // KMP优化
    vector<int> getNextArr(const string &needle)
    {
        vector<int> next(needle.size(), 0);
        for (int i = 0, j = 1; j < next.size(); j++)
        {
            // 不匹配：i回退
            while (i > 0 && needle[i] != needle[j])
                i = next[i - 1];
            if (needle[i] == needle[j])
                i++;
            next[j] = i;
        }
        return next;
    }

    int strStrKMP(string haystack, string needle)
    {
        vector<int> next = getNextArr(needle);
        for (int i = 0, j = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
                j = next[j - 1];
            if (haystack[i] == needle[j])
                j++;
            if (j == needle.size())
                return i - needle.size() + 1;
        }
        return -1;
    }

    bool repeatedSubstringPatterKMP(string s) {
        return strStrKMP(s.substr(1, s.size() - 1).append(s.substr(0, s.size() - 1)), s) >= 0;
    }

    bool repeatedSubstringPatterKMPII(string s)
    {
        vector<int> next = getNextArr(s);
        int n = s.size();
        int len = next[n - 1];
        return len > 0 && n % (n - len) == 0;
    }
};