#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  // KMP，启动！
  vector<int> getNextArr(const string& needle) {
    vector<int> next(needle.size(), 0);
    for (int i = 0, j = 1; j < next.size(); j++) {
      // 不匹配：i回退
      while (i > 0 && needle[i] != needle[j]) i = next[i - 1];
      if (needle[i] == needle[j]) i++;
      next[j] = i;
    }
    return next;
  }

  int strStr(string haystack, string needle) {
    vector<int> next = getNextArr(needle);
    for (int i = 0, j = 0; i < haystack.size(); i++) {
      while (j > 0 && haystack[i] != needle[j]) j = next[j - 1];
      if (haystack[i] == needle[j]) j++;
      if (j == needle.size()) return i - needle.size() + 1;
    }
    return -1;
  }
};

class Solution_2 {
 public:
  void genNextArr(int* nextval, string pattern) {
    int len = pattern.size();
    int* next = new int[len];
    int j = 0;
    next[0] = 0;

    for (int i = 1; i < len; ++i) {
      while (j > 0 && pattern[i] != pattern[j]) {
        j = next[j - 1];
      }
      if (pattern[i] == pattern[j]) ++j;
      next[i] = j;
    }

    nextval[0] = 0;
    for (int i = 1; i < len; ++i) {
      if (next[i] == 0) {
        nextval[i] = 0;
      } else if (pattern[i] == pattern[next[i] - 1]) {
        nextval[i] = nextval[next[i] - 1];
      } else {
        nextval[i] = next[i];
      }
    }

    delete[] next;
  }

  int strStr(string haystack, string needle) {
    int len_text = haystack.size();
    int len_pattern = needle.size();
    int* next = new int[len_pattern];
    genNextArr(next, needle);

    int j = 0;
    for (int i = 0; i < len_text; ++i) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = next[j - 1];
      }
      if (haystack[i] == needle[j]) ++j;
      if (j == len_pattern) return i - len_pattern + 1;
    }

    return -1;
  }
};

/*
a a a a b
0 1 2 3 0

*/

int main() {
  Solution_2 obj;
  cout << obj.strStr("mississippi", "issip") << endl;

  return 0;
}