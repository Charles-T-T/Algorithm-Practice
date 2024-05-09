#include <iostream>
#include <vector>

using namespace std;

/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]
*/

class Solution
{
private:
    const string letterDict[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    }; // 数字-字母对照

    vector<string> res; // 存储最终结果
    string curStr = ""; // 用于临时存储res中的每个字符串

public:
    void backTracking(const string &digits, int index)
    {
        if (index == digits.length())
        {
            // 之前已经找齐了
            res.push_back(curStr);
            return;
        }

        int num = digits[index] - '0';
        string letters = letterDict[num];
        for (int i = 0; i < letters.length(); i++)
        {
            curStr += letters[i];            // 处理
            backTracking(digits, index + 1); // 递归
            curStr.pop_back();               // 回溯
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return res;

        backTracking(digits, 0);
        return res;
    }
};
