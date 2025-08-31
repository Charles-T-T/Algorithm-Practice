#include <cstddef>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<vector<string>> res;
  vector<string> path;

  bool palindrome(string s) {
    for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) {
      if (s[i] != s[j]) return false;
    }
    return true;
  }

  void backTracking(string s, size_t cut_pos) {
    if (cut_pos == s.size()) {
      res.push_back(path);
      return;
    }

    for (size_t i = cut_pos; i < s.size(); ++i) {
      string sub = s.substr(cut_pos, i - cut_pos + 1);
      if (palindrome(sub)) {
        path.push_back(sub);
      } else {
        continue;
      }
      backTracking(s, i + 1);
      path.pop_back();
    }
  }

  vector<vector<string>> partition(string s) {
      backTracking(s, 0);
      return res;
  }
};

int main() {
  string s = "aab";
  Solution obj;
  auto res = obj.partition(s);
  return 0;
}