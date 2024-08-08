#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        // 找到每个字母最后一次出现的位置
        unordered_map<char, int> lastOccur;
        for (int i = 0; i < s.size(); ++i)
            lastOccur[s[i]] = i;
        vector<int> res;
        int curCount = 0;
        int curLastPos = -1;
        for (int i = 0; i < s.size(); ++i) {
            curLastPos = max(curLastPos, lastOccur[s[i]]);
            curCount++;
            if (curLastPos == i) {
                res.push_back(curCount);
                curCount = 0;
            }   
        }
        return res;
    }
};