#include <vector>

using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col));
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (i == 0) {
          dp[i][j] = j != 0 ? dp[i][j - 1] + grid[i][j] : grid[0][0];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j] + grid[i][j];
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
      }
    }
    return dp[row - 1][col - 1];
  }
};
