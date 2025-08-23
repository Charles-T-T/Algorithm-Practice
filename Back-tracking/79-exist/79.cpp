#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 private:
  string path;
  vector<pair<size_t, size_t>> dirc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vector<vector<bool>> visited;

  bool legalPos(const vector<vector<char>>& board, int i, int j) {
    return i >= 0 && size_t(i) < board.size() && j >= 0 && size_t(j) < board[0].size();
  } 

 public:
  // 回溯
  bool backTracking(const vector<vector<char>>& board, string word, size_t i, size_t j) {
    path += board[i][j];

    if (path.size() == word.size()) {
      if (path == word) {
        return true;
      } else {
        path.pop_back();
        return false;
      }
    }

    if (path[path.size() - 1] != word[path.size() - 1]) {
      path.pop_back();
      return false;
    }

    visited[i][j] = true;
    for (const auto& move : dirc) {
      size_t newi = i + move.first;
      size_t newj = j + move.second;
      if (legalPos(board, newi, newj) && !visited[newi][newj]) {
        if (backTracking(board, word, newi, newj)) {
          return true;
        }
      } 
    }
    visited[i][j] = false;

    path.pop_back();
    return false;
  }

  bool exist(vector<vector<char>>& board, string word) {
    visited.resize(board.size());
    for (auto &line : visited) {
      line.resize(board[0].size());
    }

    for (size_t i = 0; i < board.size(); ++i) {
      for (size_t j = 0; j < board[0].size(); ++j) {
        if (backTracking(board, word, i, j)) {
          return true;
        }
      }
    }

    return false;
  }
};

int main() {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}
  };
  Solution obj;
  cout << obj.exist(board, "ABCB") << endl;
  
  return 0;
}