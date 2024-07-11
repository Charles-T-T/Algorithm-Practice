#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.length(); i += 2 * k) {
            if (s.length() - i >= k) // 后面剩的够k个就反转k个
                reverse(s.begin() + i, s.begin() + i + k);
            else // 否则把剩的全部反转
                reverse(s.begin() + i, s.end());
        }
        return s;
    }
};

int main() {
    string s = "abcdefg";
    Solution obj;
    string res = obj.reverseStr(s, 2);
    cout << res << endl;

    return 0;
}