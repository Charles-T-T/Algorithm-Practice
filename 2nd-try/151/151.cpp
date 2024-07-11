#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // 思路：用栈存储各单词，既能自然反转，又便于去除重复的空格
        string word = "";
        stack<string> wordStack;
        s += " "; // 先在结尾添加空格，确保最后一个单词也入栈
        for (char c : s)
        {
            if (c != ' ')
                word += c;
            else
            {
                if (word != "")
                {
                    wordStack.push(word);
                    word = "";
                }
            }
        }

        string res = "";
        while (!empty(wordStack)) {
            res += wordStack.top();
            res += " ";
            wordStack.pop();
        }
        res.pop_back(); // 去掉结尾的空格
        return res;
    }
};

int main() {
    string s = "the sky is blue";
    Solution obj;
    string res = obj.reverseWords(s);
    cout << "res: " << res << endl;

    return 0;
}