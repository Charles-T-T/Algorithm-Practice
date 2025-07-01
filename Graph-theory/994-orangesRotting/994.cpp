#include <iostream>
#include <thread>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    // 思路：每轮聚焦到尚未腐烂的橘子，看它会不会被传染
    int turn = 0;                  // 全部腐烂需要的最小分钟数
    unordered_set<int> fresh_set;  // 尚且新鲜的，坐标为 ID = i * col + j
    int row = grid.size();
    int col = grid[0].size();

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == 1) fresh_set.insert(i * col + j);
      }
    }

    // 从ID反解出i, j
    auto get_ij = [col](int id) {
      int i = id / col;
      int j = id % col;
      return make_pair(i, j);
    };

    while (!fresh_set.empty()) {
      vector<std::pair<int, int>> to_be_influ;  // 本轮会被传染的
      for (auto it = fresh_set.begin(); it != fresh_set.end();) {
        auto pair = get_ij(*it);
        int i = pair.first;
        int j = pair.second;

        if ((i - 1 >= 0 && grid[i - 1][j] == 2) ||   // 上
            (i + 1 < row && grid[i + 1][j] == 2) ||  // 下
            (j - 1 >= 0 && grid[i][j - 1] == 2) ||   // 左
            (j + 1 < col && grid[i][j + 1] == 2)     // 右
        ) {
          to_be_influ.emplace_back(i, j);  // 要被传染
          it = fresh_set.erase(it);
        } else {
          ++it;
        }
      }

      // 如果本轮没有能感染的，退出循环
      if (to_be_influ.empty()) break;

      for (const auto& pair : to_be_influ) {
        grid[pair.first][pair.second] = 2;
      }

      ++turn;
    }

    return fresh_set.empty() ? turn : -1;
  }
};

int main() {
  vector<vector<int>> grid = {{0, 1, 1}, {1, 1, 1}};

  Solution obj;
  auto res = obj.orangesRotting(grid);
  cout << res << endl;

  return 0;
}