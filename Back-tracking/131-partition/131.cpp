#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    vector<string> path;
    vector<vector<string>> res;

    // 判断是否为回文串
    bool isPalindrome(const string &str)
    {
        for (int i = 0, j = str.size() - 1; i <= j; ++i, --j)
        {
            if (str[i] != str[j])
                return false;
        }
        return true;
    }

public:
    void backTracking(const string &s, int cutPos)
    {
        // 递归出口：切割点到达字符串末尾位置
        if (cutPos >= s.size())
        {
            res.push_back(path);
            return;
        }
        // 横向遍历
        for (int i = cutPos; i < s.size(); ++i)
        {
            // 处理：判断截断的子串是不是回文串
            string sub = s.substr(cutPos, i - cutPos + 1);
            if (isPalindrome(sub))
                path.push_back(sub);
            else
                continue;
            backTracking(s, i + 1); // 递归
            path.pop_back();        // 回溯
        }
    }

    vector<vector<string>> partition(string s)
    {
        backTracking(s, 0);
        return res;
    }
};