#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例 1：
输入：s = "3[a]2[bc]"
输出："aaabcbc"

示例 2：
输入：s = "3[a2[c]]"
输出："accaccacc"

示例 3：
输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"

示例 4：
输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"
*/

class Solution
{
public:
    string decodeString(string s)
    {
        /**
         * 用一个栈处理字符串s
         * 把s的每一个字符根据情况入栈/出栈/组合
         * 遇到 "]" 就开始出栈直到遇到 "["
         * 由上一步可得到中括号内字符串
         * "[" 出栈后下一个元素肯定是相应的数字
         * 由上一步组合出含重复字符的字符串串入栈
         * 按照上面几步遍历s
         */
        stack<string> tokenStack;
        string left(1, '[');
        for (const char& c : s) {
            if (isdigit(c)) {
                string cStr(1, c);
                tokenStack.push(cStr);
                continue;
            }
            if (c == ']') {
                string word = "";
                stack<string> helper;
                while (tokenStack.top() != left) {
                    helper.push(tokenStack.top());
                    tokenStack.pop();
                }
                // 由于出栈顺序颠倒，需要倒一下才能得到word
                while (!helper.empty()) {
                    word += helper.top();
                    helper.pop();
                }
                // 弹出 "["
                tokenStack.pop();
                // 弹出数字（重复次数），注意考虑多位数
                int count = 0;
                int loc = 0; // 位数
                while (!tokenStack.empty() && isdigit(tokenStack.top()[0]))
                {
                    count += stoi(tokenStack.top()) * pow(10, loc++);
                    tokenStack.pop();
                }
                // 将word重复压回栈中
                for (int i = 0; i < count; ++i) {
                    tokenStack.push(word);
                }
                continue;
            }
            else {
                string cStr(1, c);
                tokenStack.push(cStr);
            }                
        }
        string res = "";
        stack<string> helper; // 用于倒顺序
        while (!tokenStack.empty())
        {
            helper.push(tokenStack.top());
            tokenStack.pop();
        }
        while (!helper.empty())
        {
            res += helper.top();
            helper.pop();
        }

        return res;
    }
};

int main(){
    string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    Solution obj;
    string res = obj.decodeString(s);
    cout << "res: " << res << endl;

    return 0;
}