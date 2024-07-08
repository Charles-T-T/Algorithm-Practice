#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length()) // 不等长肯定不是字母异位词
            return false;
        unordered_map<char, int> sMap, tMap;
        for (int i = 0; i < s.length(); i++)
            sMap[s[i]]++, tMap[t[i]]++;
        for (auto pair : sMap)
        {
            if (pair.second != tMap[pair.first])
                return false;
        }
        return true;
    }

    bool isAnagram_II(string s, string t)
    {
        // 旁门左道（doge
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};