#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countOfSubstrings(string word, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        // 计算 word 中，包含所有元音字母
        // 且 **至少** 有 cur_k 个辅音字母的子串个数
        auto count = [&](int cur_k) -> int {
            int res;
            int consonants = 0;                   // word[i, j]中辅音字母的个数
            unordered_map<char, int> cur_vowels;  // word[i, j]中的元音字母及其个数
            for (int i = 0, j = 0; i < word.size(); ++i) {
                while (j < word.size() &&
                       (consonants < cur_k || cur_vowels.size() < vowels.size())) {
                    if (vowels.find(word[j]) != vowels.end()) {
                        ++cur_vowels[word[j]];  // 元音字母
                    } else {
                        ++consonants;  // 辅音字母
                    }
                    ++j;
                }
                // 检查当前子串是否满足要求
                if (cur_vowels.size() == vowels.size() && consonants >= cur_k) {
                    res +=
                        word.size() - j + 1;  // 当前子串是一个，当前子串+后续每个字符也都满足要求
                }
                // 为了下一次遍历，处理当前子串开头字符
                if (vowels.find(word[i]) != vowels.end()) {
                    if (cur_vowels[word[i]] > 1) {
                        --cur_vowels[word[i]];
                    } else {
                        cur_vowels.erase(word[i]);
                    }
                } else {
                    --consonants;
                }
            }
            return res;
        };

        return count(k) - count(k + 1);
    }
};

int main() {
    string word = "aeioqq";
    Solution obj;
    cout << obj.countOfSubstrings(word, 1) << endl;

    return 0;
}