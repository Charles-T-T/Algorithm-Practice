#include <iostream>
#include <string>
#include <cctype>

std::string changeNum(std::string s) {
    std::string res = "";
    for (char c : s) {
        if (isdigit(c))
            res += "number";
        else
            res += c;
    }
    return res;
}

std::string changeNumCarl(std::string s) {
    int numCount = 0;
    int oldIndex = s.size() - 1;
    for (char c : s) {
        if (isdigit(c))
            numCount++;
    }
    // "number"是6个字母，减去被替换的1个数字，需要5个额外空间
    s.resize(s.size() + 5 * numCount); 
    // 双指针：从后向前填充
    int newIndex = s.size() - 1;
    while (oldIndex >= 0) {
        if (isdigit(s[oldIndex])) {
            s[newIndex--] = 'r';
            s[newIndex--] = 'e';
            s[newIndex--] = 'b';
            s[newIndex--] = 'm';
            s[newIndex--] = 'u';
            s[newIndex--] = 'n';
        } else 
            s[newIndex--] = s[oldIndex];
        oldIndex--;
    }
    return s;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << changeNumCarl(s) << std::endl;

    return 0;
}