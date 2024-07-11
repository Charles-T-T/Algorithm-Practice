#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // KMP，启动！
    vector<int> getNextArr(const string &needle) {
        vector<int> next(needle.size(), 0);
        for (int i = 0, j = 1; j < next.size(); j++) {
            // 不匹配：i回退
            while (i > 0 && needle[i] != needle[j]) 
                i = next[i - 1];
            if (needle[i] == needle[j])
                i++;
            next[j] = i;
        }
        return next;
    }

    int strStr(string haystack, string needle)
    {
        vector<int> next = getNextArr(needle);
        for (int i = 0, j = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) 
                j = next[j - 1];
            if (haystack[i] == needle[j]) 
                j++;
            if (j == needle.size())
                return i - needle.size() + 1;
        }
        return -1;
    }
};

int main() {
    string needle = "aabaabaaf"; // 0 1 0 1 2 3 4 5 0
    Solution obj;
    vector<int> next = obj.getNextArr(needle);
    for (int num : next) 
        cout << num << " ";
    cout << endl;

    return 0;

}