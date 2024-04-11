#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

示例 1:
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

示例 2:
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。

提示:
1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母
*/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        /**
         * 思路：
         * 滑动窗口
         * 动态判断窗口中的字符及其对应数量是否和p的相符
         */
        vector<int> index;
        int lenP = p.length(), lenS = s.length();

        if (lenP > lenS)
            return index;

        unordered_map<char, int> target, window;
        for (const char &c : p)
            target[c]++;

        int left = 0, right = 0; // 滑动窗口的左右边界
        int matchedNum = 0;      // 当前窗口中与p匹配的字符数
        while (right < lenS)
        {
            if (target.count(s[right]))
            {
                window[s[right]]++;
                if (window[s[right]] == target[s[right]])
                    matchedNum++;
            }

            while (right - left + 1 >= lenP)
            {
                if (matchedNum == target.size())
                    index.push_back(left);

                if (target.count(s[left]))
                {
                    if (window[s[left]] == target[s[left]])
                        matchedNum--;
                    window[s[left]]--;
                }

                left++;
            }
            right++;
        }

        return index;
    }
};

int main()
{
    string s = "cbaebabacd";
    string p = "abc";

    Solution obj;
    vector<int> res = obj.findAnagrams(s, p);
    cout << "[ ";
    for (const int &num : res)
        cout << num << " ";
    cout << "]" << endl;

    return 0;
}