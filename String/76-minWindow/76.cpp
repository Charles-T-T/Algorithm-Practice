#include <iostream>
#include <limits>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  unordered_map<char, int> window;
  unordered_map<char, int> t_cnt;  // char in t -> count of the char

  bool cover() {
    for (const auto& kv : t_cnt) {
      if (window[kv.first] < kv.second) {
        return false;
      }
    }
    return true;
  }

  string minWindow(string s, string t) {
    for (const char& c : t) {
      ++t_cnt[c];
    }

    int min_len = numeric_limits<int>::max();
    int start = -1;
    for (int l = 0, r = 0; r < int(s.size()); ++r) {
      if (t_cnt.count(s[r])) {
        ++window[s[r]];
      }

      while (cover() && l <= r) {
        int cur_len = r - l + 1;
        if (cur_len < min_len) {
          min_len = cur_len;
          start = l;
        }
        --window[s[l]];
        ++l;
      }
    }

    return start == -1 ? "" : s.substr(start, min_len);
  }
};

int main() {
  string s = "ADOBECODEBANC";
  string t = "ABC";
  Solution obj;
  cout << obj.minWindow(s, t) << endl;

  return 0;
}