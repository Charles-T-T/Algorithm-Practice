#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int kinds, bagSize;
    cin >> kinds >> bagSize;
    vector<int> weights(kinds), values(kinds);
    for (int i = 0; i < kinds; ++i)
        cin >> weights[i] >> values[i];

    vector<int> dp(bagSize + 1, 0);
    for (int i = 0; i < kinds; ++i) {
        for (int j = weights[i]; j <= bagSize; ++j)
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
    }
    cout << dp[bagSize] << endl;

    return 0;
}