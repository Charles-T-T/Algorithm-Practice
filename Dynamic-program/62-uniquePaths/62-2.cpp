#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> board(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0) {
          board[i][j] = j != 0 ? board[i][j - 1] : 1;
        } else if (j == 0) {
          board[i][j] = i != 0 ? board[i - 1][j] : 1;
        } else {
          board[i][j] = board[i][j - 1] + board[i - 1][j];
        }
      }
    }
    return board[m - 1][n - 1];
  }
};