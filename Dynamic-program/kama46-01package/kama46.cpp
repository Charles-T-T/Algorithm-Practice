#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<int> weights(m), values(m);
    for (int i = 0; i < m; ++i)
        std::cin >> weights[i];
    for (int i = 0; i < m; ++i)
        std::cin >> values[i];

    // // 二维dp
    // std::vector<std::vector<int>> dp(m, std::vector<int>(n + 1, 0));
    // for (int j = weights[0]; j <= n; ++j)
    //     dp[0][j] = values[0];
    // for (int i = 1; i < m; ++i) {
    //     for (int j = 0; j <= n; ++j) {
    //         if (weights[i] > j)
    //             dp[i][j] = dp[i - 1][j];
    //          else 
    //             dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
    //     }
    // }
    // std::cout << dp[m - 1][n] << std::endl;

    // 一维dp
    std::vector<int> dp(n + 1);
    for (int j = weights[0]; j <= n; ++j)
        dp[j] = values[0];
    for (int i = 1; i < weights.size(); ++i) {
        for (int j = n; j >= weights[i]; --j) 
            dp[j] = std::max(dp[j], dp[j - weights[i]] + values[i]);
    }
    std::cout << dp[n] << std::endl;

    return 0;
}