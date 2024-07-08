#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 哈希表秒了
        if (s.length() != t.length()) // 不等长肯定不是字母异位词
            return false;
        unordered_map<char, int> sMap, tMap;
        for (int i = 0; i < s.length(); i++)
            sMap[s[i]]++, tMap[t[i]]++;
        for (auto pair : sMap) {
            if (pair.second != tMap[pair.first])
                return false;
        }
        return true;
    }
};