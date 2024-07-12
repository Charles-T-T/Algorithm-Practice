#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> cMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (char c : s)
        {
            if (cMap.find(c) != cMap.end()) {
                if (st.empty() || st.top() != cMap[c])
                    return false;
                st.pop();
            } else if (c == '(' || c == '[' || c == '{')
                st.push(c);
        }
        return st.empty();
    }
};