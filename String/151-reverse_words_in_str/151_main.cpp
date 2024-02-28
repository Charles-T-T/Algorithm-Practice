#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

/*
给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。


示例 1：
输入：s = "the sky is blue"
输出："blue is sky the"

示例 2：
输入：s = "  hello world  "
输出："world hello"
解释：反转后的字符串中不能存在前导空格和尾随空格。

示例 3：
输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        // 思路：由“反转”联想到利用栈解决
        // 且发现这种方法不需要先处理多余的空格，代码比较清晰
        stack<string> wordStack; // 存储s中的各个单词的栈
        string word = "", resStr = "";
        for (int i = 0; i < s.size(); i++)
        {
            while (i < s.size() && s[i] != ' ') // 找到连续的字符，即一个“单词”
                word += s[i++];
            if (word != "")
                wordStack.push(word);
            word = "";
        }

        while (!wordStack.empty())
        {
            resStr += wordStack.top();
            resStr += ' ';
            wordStack.pop();
        }

        resStr.erase(resStr.end() - 1); // 删除最后的空格
        return resStr;
    }

    /* 上面代码空间复杂度较高，为O(n)。尝试降低空间复杂度，如下 */
    // 思路：先清理多余空格，再反转整个字符串，最后反转其中的单词
    void removeExtraSpace(string &s)
    {
        // 采用双指针清理多余空格
        int slowP = 0, fastP = 0;
        for (; fastP < s.size(); fastP++)
        {
            if (s[fastP] != ' ')
            {
                if (slowP != 0)
                    s[slowP++] = ' '; // 为非串首单词添加前面的空格
                while (fastP < s.size() && s[fastP] != ' ')
                    s[slowP++] = s[fastP++];
            }
        }

        s.resize(slowP); // 除去慢指针后面多余的字符
    }

    string reverseWordsII(string s)
    {
        removeExtraSpace(s);
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if (i == s.size() || s[i] == ' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};

int main()
{
    string s;
    cout << "please input the string: ";
    getline(cin, s);

    Solution obj;
    string res = obj.reverseWordsII(s);

    cout << "result: " << res;
    return 0;
}