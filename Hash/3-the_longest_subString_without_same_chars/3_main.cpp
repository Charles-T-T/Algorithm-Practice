#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

ʾ�� 1:
����: s = "abcabcbb"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

ʾ�� 2:
����: s = "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��

ʾ�� 3:
����: s = "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
     ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���
*/

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    // ˼·��˫ָ�루����һ���������ڣ�+��ϣ����
    int len = s.size();
    unordered_set<char> charSet;
    int right = -1;
    int res = 0;
    for (int i = 0; i < len; i++) {
      if (i > 0) {
        charSet.erase(s[i - 1]);
      }

      while (right + 1 < len && charSet.find(s[right + 1]) == charSet.end()) {
        charSet.insert(s[right + 1]);
        right++;
      }

      res = res > (right - i + 1) ? res : (right - i + 1);
    }

    return res;
  }
};

class Solution_2 {
 public:
  int lengthOfLongestSubstring(string s) {
    int left = 0;
    int right = 0;
    int max_len = 0;

    unordered_set<char> wnd_letters;
    while (right < s.size()) {
      if (wnd_letters.find(s[right]) == wnd_letters.end()) {
        wnd_letters.insert(s[right]);
      } else {
        max_len = max(max_len, right - left);
        while (s[left] != s[right]) {
          wnd_letters.erase(s[left]);
          ++left;
        }
        ++left;
      }
      ++right;
    }

    return max(max_len, right - left);
  }
};

int main() {
  string s =
      "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwx"
      "yzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNO"
      "PQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345"
      "6789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrst"
      "uvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  Solution_2 obj;
  int n = obj.lengthOfLongestSubstring(s);
  cout << "result is: " << n << endl;

  return 0;
}
