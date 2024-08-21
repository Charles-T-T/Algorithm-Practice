#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution1I // 回溯算法，超时
{
private:
    // KMP算法，判断某个字符串是不是另一个字符串的子串
    bool isSubStr(const string &text, const string &pattern)
    {
        // 获取next数组
        auto Next = [](const string &pattern) -> vector<int>
        {
            vector<int> next(pattern.size(), 0);
            int j = 0;
            for (int i = 1; i < pattern.size(); ++i)
            {
                while (j > 0 && pattern[i] != pattern[j])
                    j = next[j - 1];
                if (pattern[i] == pattern[j])
                    j++;
                next[i] = j;
            }
            return next;
        };
        vector<int> next = Next(pattern);

        // 检查模式串是否为文本串的子串
        int j = 0;
        for (int i = 0; i < text.size(); ++i)
        {
            while (j > 0 && text[i] != pattern[j])
                j = next[j - 1];
            if (text[i] == pattern[j])
                j++;
            if (j == pattern.size())
                return true;
        }
        return false;
    }

    // 回溯算法
    string path = "";
    bool flag = false;
    int count = 0;
    void backTracking(
        string &path, 
        const string &target,
        const vector<string> &words) {
        // 递归出口（纵向遍历）
        if (path == target)
        {
            flag = true;
            return;
        }
        if (path.size() > target.size() || path != target.substr(0, path.size())) 
            return; 

        // 横向遍历
        for (int i = 0; i < words.size(); ++i)
        {
            path += words[i];                           // 处理
            backTracking(path, target, words);          // 递归
            path.resize(path.size() - words[i].size()); // 回溯
        }
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // 获取可能用于组成s的单词
        vector<string> subStrs;
        for (const string &word : wordDict)
        {
            if (isSubStr(s, word))
                subStrs.push_back(word);
        }

        // 回溯算法
        backTracking(path, s, subStrs);
        return flag;
    }
};

class Solution1II // 回溯算法+记忆化搜索
{
private:
    unordered_map<int, bool> memory; // 记录某子串（起始位置为start）能否由wordSet中单词组成
    bool backTracking(string s, int start, const unordered_set<string> wordSet) {
        // 递归出口（纵向遍历）
        if (start == s.size())
            return true;
        
        // 采用记忆化搜索，利用已处理过的子问题的结果
        if (memory.find(start) != memory.end())
            return memory[start];

        // 回溯搜索（横向遍历）
        for (int end = start + 1; end <= s.size(); ++end) {
            if (wordSet.find(s.substr(start, end - start)) != wordSet.end()
                && backTracking(s, end, wordSet)) {
                memory[start] = true;
                return true;
            }
        }
        
        memory[start] = false;
        return false;
    }

public:
    bool wordBreak(string s, vector<string> & wordDict)
    {
        unordered_set<string> wordSet{wordDict.begin(), wordDict.end()}; // 存储单词的哈希表，加速查找
        return backTracking(s, 0, wordSet);
    }
};

class Solution1III // 动态规划（完全背包问题）
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_set<string> wordSet{wordDict.begin(), wordDict.end()};
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + 1; j <= s.size(); ++j) {
                if (!dp[i])
                    break;
                if (wordSet.find(s.substr(i, j - i)) != wordSet.end())
                    dp[j] = true;
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    string s = "applepenapple";
    //          bccdbacdbdacddabbaaaadabadabb
    vector<string> wordDict = {"apple", "pen"};
    Solution1III obj;
    if (obj.wordBreak(s, wordDict))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}