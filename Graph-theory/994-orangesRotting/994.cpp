#include <iostream>
#include <queue>
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

// LeetCode官方题解：多源BFS
class Solution_2 {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    vector<int> dir_x = {-1, 0, 1, 0};
    vector<int> dir_y = {0, -1, 0, 1};
    int fresh_cnt = 0;                // 剩余的新鲜橘子数目
    queue<pair<int, int>> rotten_qu;  // 已经被腐蚀的橘子的坐标

    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> turn(row, vector<int>(col, -1));  // 被腐蚀所需轮数

    int res = 0;

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == 2) {
          turn[i][j] = 0;  // 一开始就是被腐蚀的，对应0轮就被腐蚀
          rotten_qu.emplace(i, j);
        } else if (grid[i][j] == 1) {
          ++fresh_cnt;
        }
      }
    }

    while (!rotten_qu.empty()) {
      auto [x, y] = rotten_qu.front();
      rotten_qu.pop();

      // 探索它上下左右四个方向有没有可以被腐蚀的
      for (int i = 0; i < 4; ++i) {
        int cx = x + dir_x[i];
        int cy = y + dir_y[i];
        if (cx < 0 || cx >= row || cy < 0 || cy >= col ||  // 越界
            turn[cx][cy] != -1 ||                          // 已经被腐蚀过了
            !grid[cx][cy]                                  // 空格子
        ) {
          continue;
        }

        turn[cx][cy] = turn[x][y] + 1;
        res = turn[cx][cy];
        --fresh_cnt;
        if (!fresh_cnt) break;
        rotten_qu.emplace(cx, cy);
      }
      if (!fresh_cnt) break;
    }

    return fresh_cnt ? -1 : res;
  }
};

int main() {
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

  Solution_2 obj;
  auto res = obj.orangesRotting(grid);
  cout << res << endl;

  return 0;
}