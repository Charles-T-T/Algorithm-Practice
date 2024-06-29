#include <iostream>

using namespace std;

/*
给你一个用字符串表示的正整数 num ，请你以字符串形式返回不含尾随零的整数 num 。

示例 1：
输入：num = "51230100"
输出："512301"
解释：整数 "51230100" 有 2 个尾随零，移除并返回整数 "512301" 。

示例 2：
输入：num = "123"
输出："123"
解释：整数 "123" 不含尾随零，返回整数 "123" 。
*/

class Solution
{
public:
    string removeTrailingZeros(string num)
    {
        // 简单题，直接移
        for (int i = num.length() - 1; i >= 0; i--) {
            if (num[i] == '0') {
                num = num.substr(0, i);
                continue;
            } else 
                break;
        }
        return num;
    }
};

int main() {
    string num = "51230100";
    Solution obj;
    cout << "res: " << obj.removeTrailingZeros(num);
    return 0;
}