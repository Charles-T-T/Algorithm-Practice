#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // 原地修改：双指针
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            swap(s[i], s[j]);
    }
};