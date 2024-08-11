#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j)
                dp[i] += dp[j - 1] * dp[i - j];
        }
        return dp[n];
    }
};

int main() {
    Solution obj;
    cout << obj.numTrees(3) << endl;

    return 0;
}
