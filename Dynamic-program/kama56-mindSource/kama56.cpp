#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int c, n;
    cin >> c >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i)
        cin >> weights[i];
    
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
        cin >> values[i];
    
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<int> dp(c + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = c; j >= weights[i]; --j) {
            for (int k = 1; k <= nums[i] && j >= k * weights[i]; ++k) 
                dp[j] = max(dp[j], dp[j - k * weights[i]] + k * values[i]);
        }
    }        
    
    cout << dp[c] << endl;
    return 0;
}