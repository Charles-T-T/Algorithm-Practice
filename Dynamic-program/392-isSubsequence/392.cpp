#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isSubsequence0(string s, string t) // 双指针
    {
        int sp = 0;
        int tp = 0;
        while (sp < s.size() && tp < t.size()) {
            if (s[sp] == t[tp]) 
                sp++;
            tp++;
        }
        return sp == s.size();
    }

    bool isSubsequence(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); ++i)
        {
            int k = t.size() - s.size() + i;
            for (int j = 1; j <= k; ++j)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[s.size()][t.size()] == s.size();
    }

    bool isSubsequenceII(string s, string t) // DP预处理+双指针
    {
        // 预处理
        vector<vector<int>> dp(t.size() + 1, vector<int>(26, t.size()));
        for (int i = t.size() - 1; i >= 0; --i) {
            int charNum = t[i] - 'a';
            for (int j = 0; j < 26; ++j) 
                dp[i][j] = charNum == j ? i : dp[i + 1][j];
        }

        // 双指针匹配
        int sp = 0;
        int tp = 0;
        while (sp < s.size() && tp < t.size()) {
            tp = dp[tp][s[sp] - 'a']; // 利用预处理结果
            if (s[sp] == t[tp]) 
                sp++, tp++;
        }

        return sp == s.size();
    }
};

int main()
{
    string s = "b";
    string t = "abcdd";

    Solution obj;
    if (obj.isSubsequenceII(s, t))
        cout << "True" << endl;
    else
        cout << "false" << endl;

    // cout << 'b' - 'a' << endl;

    return 0;
}