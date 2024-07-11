#include <iostream>
#include <string>
#include <algorithm>

/*
题目描述
字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。给定一个字符串 s 和一个正整数 k，请编写一个函数，将字符串中的后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。

例如，对于输入字符串 "abcdefg" 和整数 2，函数应该将其转换为 "fgabcde"。

输入描述
输入共包含两行，第一行为一个正整数 k，代表右旋转的位数。第二行为字符串 s，代表需要旋转的字符串。

输出描述
输出共一行，为进行了右旋转操作后的字符串。

输入示例
2
abcdefg

输出示例
fgabcde

提示信息
数据范围：
1 <= k < 10000,
1 <= s.length < 10000;
*/

std::string rightSpanStr(std::string s, int k) {
    // 暴力：新开一个字符串操作即可
    std::string front = s.substr(s.size() - k, k);
    std::string back = s.substr(0, s.size() - k);
    return front + back;
}

void rightSpanLocal(std::string &s, int k) {
    // 原地旋转：先整体逆转，再让两部分分别逆转
    std::reverse(s.begin(), s.end());
    std::reverse(s.begin(), s.begin() + k);
    std::reverse(s.begin() + k, s.end());
}

int main() {
    std::string s;
    int k;
    std::cin >> k;
    std::cin >> s;
    std::cout << rightSpanStr(s, k) << std::endl;
    rightSpanLocal(s, k);
    std::cout << s << std::endl;
    return 0;
}