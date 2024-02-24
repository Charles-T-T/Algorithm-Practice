#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 思路：双指针（构成一个滑动窗口）+哈希集合
        int len = s.size();
        unordered_set<char> charSet;
        int right = -1;
        int res = 0;
        for (int i = 0; i < len; i++)
        {
            if (i > 0)
            {
                charSet.erase(s[i - 1]);
            }

            while (right + 1 < len && charSet.find(s[right + 1]) == charSet.end())
            {
                charSet.insert(s[right + 1]);
                right++;
            }

            res = res > (right - i + 1) ? res : (right - i + 1);
        }

        return res;
    }
};

int main()
{
    string s;
    cout << "please input a string: ";
    cin >> s;
    Solution obj;
    int n = obj.lengthOfLongestSubstring(s);
    cout << "result is: " << n << endl;

    return 0;
}
