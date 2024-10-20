#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // 初始化dp数组（全为false）
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (i == j) {
                    dp[i][j] = true;
                    res++;
                } else if (s[i] == s[j]) {
                    if (i + 1 == j) {
                        dp[i][j] = true;
                        res++;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                        if (dp[i][j]) {
                            res++;
                        }
                    }
                }
            }
        }

        return res;
    }
};

// asffghhgffuygf
int main() {
    string s = "aaa";
    Solution obj;
    cout << obj.countSubstrings(s) << endl;

    return 0;
}