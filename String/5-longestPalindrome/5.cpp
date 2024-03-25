#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        /**
         * 子串s[i, j]回文的条件是:
         * 1. s[i] = s[j]
         * 2. s[i + 1, j - 1]是回文串
        */
        int len = s.size();
        if (len == 1)
            return s; // 单个字符就是回文串

        int maxLen = 1, start = 0;
        vector<vector<int>> pd(len, vector<int>(len)); // pd[i][j] = 1[i, j]是回文串
        for (int i = 0; i < len; i++)
            pd[i][i] = 1; // 单个字符就是回文串
        for (int l = 2; l <= len; l++) // 枚举，由串长和起始位置确定字串
        {
            for (int i = 0; i < len; i++)
            {
                // 由 l = j - i + 1可得
                int j = l + i - 1;
                if (j > len - 1)
                    break;

                if (s[i] != s[j])
                    pd[i][j] = 0;
                else{
                    if (l <= 3 || pd[i + 1][j - 1]){
                        pd[i][j] = 1;
                        maxLen = l;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main(){
    cout << "please input s: ";
    string s;
    cin >> s;
    Solution obj;
    string res = obj.longestPalindrome(s);
    cout << "result: " << res << endl;

    return 0;
}