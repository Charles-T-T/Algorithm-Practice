#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例 1：
输入：s = "abcdefg", k = 2
输出："bacdfeg"

示例 2：
输入：s = "abcd", k = 2
输出："bacd"
*/

class Solution
{
public:
    void reverseString(string &s, int lp, int rp)
    {
        while (lp <= rp)
            swap(s[lp++], s[rp--]);
    }

    string reverseStr(string s, int k)
    {
        int dk = 2 * k;
        int p = 0; // 标记当前字符的位置
        int lp, rp;
        int size = s.size();
        while (p < size)
        {
            if (size - p < 2 * k)
            {
                if (size - p < k)
                {
                    // 如果剩余字符少于k个，将它们全部反转
                    reverseString(s, p, size - 1);
                    return s;
                }
                else
                {
                    // 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样
                    reverseString(s, p, p + k - 1);
                    return s;
                }
            }
            else
            {
                reverseString(s, p, p + k - 1);
                p += 2 * k;
            }
        }

        return s;
    }
};