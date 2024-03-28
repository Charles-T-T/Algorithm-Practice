#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        /**
         * s[i, j]为回文串的条件有二：
         * 1. s[i + 1, j - 1]是回文串
         * 2. s[i] = s[j]
         */
        int len = s.size();
        int maxLen = 1, resStart = 0;
        int dp[len][len];
        // 初始化dp数组（单个字符就是回文子串）
        for (int i = 0; i < len; i++)
            dp[i][i] = 1;
        for (int i = 0; i < len; i++)
        {
            // 根据起始位置i和串长l确定子串并枚举
            for (int l = 2; l <= len; l++)
            {
                // 由l = j - i + 1可得
                int j = l + i - 1;
                if (j >= len)
                    break;
                // 列出状态转移方程
                if (s[i] == s[j])
                {
                    dp[i][j] = (i + 1 == j) ? 1 : dp[i + 1][j - 1];
                    if (dp[i][j] && l > maxLen)
                    {
                        maxLen = l;
                        resStart = i;
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }

        return s.substr(resStart, maxLen);
    }
};

int main()
{
    string s;
    cout << "please input the s: ";
    cin >> s;
    Solution obj;
    cout << "res: " << obj.longestPalindrome(s) << endl;

    return 0;
}