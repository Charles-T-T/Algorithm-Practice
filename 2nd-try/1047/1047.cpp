#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> cs;
        for (char c : s) {
            if (!cs.empty()) {
                if (c == cs.top())
                    cs.pop();
                else    
                    cs.push(c);
            } else 
                cs.push(c);
        }
        string res = "";
        while (!cs.empty()) {
            res = cs.top() + res; // 栈顶元素加入字符串头部
            cs.pop();
        }
        return res;
    }

    string removeDuplicatesII(string s) {
        stack<char> cs;
        for (char c : s) {
            // 只把满足条件的元素入栈
            if (cs.empty() || c != cs.top())
                cs.push(c);
            else
                cs.pop();
        }
        string res = "";
        while (!cs.empty())
        {
            res = cs.top() + res; // 栈顶元素加入字符串头部
            cs.pop();
        }
        return res;
    }

    string removeDuplicatesIII(string s) {
        vector<char> stack; // 用vector模拟栈
        stack.push_back(' '); // 先加入一个空格，便于统一操作
        for (char c : s) {
            if (c != stack.back())
                stack.push_back(c);
            else
                stack.pop_back();
        }
        return string(stack.begin() + 1, stack.end());
    }

};