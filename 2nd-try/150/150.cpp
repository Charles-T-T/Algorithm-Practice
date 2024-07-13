#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> numSt; // 存储数字的栈
        for (const string &token : tokens) { 
            if (token == "+") {
                int num1 = numSt.top();
                numSt.pop();
                int num2 = numSt.top();
                numSt.pop();
                numSt.push(num1 + num2);
            } else if (token == "-") {
                int num1 = numSt.top();
                numSt.pop();
                int num2 = numSt.top();
                numSt.pop();
                numSt.push(num2 - num1);
            } else if (token == "*") {
                int num1 = numSt.top();
                numSt.pop();
                int num2 = numSt.top();
                numSt.pop();
                numSt.push(num1 * num2);
            } else if (token == "/") {
                int num1 = numSt.top();
                numSt.pop();
                int num2 = numSt.top();
                numSt.pop();
                numSt.push(num2 / num1);
            } else 
                numSt.push(stoi(token)); // 数字无脑入栈即可
        }
        return numSt.top();
    }
};