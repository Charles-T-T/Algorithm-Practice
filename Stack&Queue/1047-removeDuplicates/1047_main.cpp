#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

/*
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

示例：
输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
*/

class Solution
{
public:
    string removeDuplicates(string s)
    {
        // 思路：用栈解决，将s每个字符边入栈边判断是否相邻重复，若有则pop
        stack<char> strStack;
        string resStr;
        for (int i = 0; i < s.size(); i++)
        {
            if (strStack.empty() || s[i] != strStack.top())
            {
                strStack.push(s[i]);
                continue;
            }
            else
                strStack.pop();
        }

        while (!strStack.empty())
        {
            resStr += strStack.top();
            strStack.pop();
        }
        reverse(resStr.begin(), resStr.end());

        return resStr;
    }
};

int main()
{
    string s;
    cout << "please input the s: ";
    cin >> s;

    Solution obj;
    string res = obj.removeDuplicates(s);
    cout << res << endl;

    return 0;
}