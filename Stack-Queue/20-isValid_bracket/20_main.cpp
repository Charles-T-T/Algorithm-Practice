#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false
*/

class Solution
{
public:
    bool isValid(string s)
    {
        // 思路：用栈判断
        stack<char> stackBracket;
        char temp;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
            case '[':
            case '{':
                stackBracket.push(s[i]);
                break;

            case ')':
                if (stackBracket.empty() || stackBracket.top() != '(')
                    return false;
                else
                    stackBracket.pop();
                break;

            case ']':
                if (stackBracket.empty() || stackBracket.top() != '[')
                    return false;
                else
                    stackBracket.pop();
                break;

            case '}':
                if (stackBracket.empty() || stackBracket.top() != '{')
                    return false;
                else
                    stackBracket.pop();
                break;
            
            default:
            break;
            }
        }

        return stackBracket.empty();
    }
};

int main()
{
    string s;
    cout << "please input s: ";
    cin >> s;

    Solution obj;
    if (obj.isValid(s))
        cout << "True!" << endl;
    else
        cout << "False!" << endl;

    return 0;
}