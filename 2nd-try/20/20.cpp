#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (const char &c : s){
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                st.push(c);
                break;

            case ')':
                if (st.empty() || st.top() != '(')
                    return false;
                else
                    st.pop();
                break;

            case ']':
                if (st.empty() || st.top() != '[')
                    return false;
                else
                    st.pop();
                break;

            case '}':
                if (st.empty() || st.top() != '{')
                    return false;
                else
                    st.pop();
                break;

            default:
                break;
            }
        }
        return st.empty();
    }
};