#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

示例 1：
输入：ransomNote = "a", magazine = "b"
输出：false

示例 2：
输入：ransomNote = "aa", magazine = "ab"
输出：false

示例 3：
输入：ransomNote = "aa", magazine = "aab"
输出：true
*/

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // 哈希表秒了
        unordered_map<char, int> charMap; // magazine 中可用的字符及其数量
        for (char c : magazine)
            charMap[c]++;
        for (char c : ransomNote) {
            if (!charMap[c])
                return false;
            charMap[c]--;
        }
        return true;
    }
};