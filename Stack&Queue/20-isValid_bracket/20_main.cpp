#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�

ʾ�� 1��
���룺s = "()"
�����true

ʾ�� 2��
���룺s = "()[]{}"
�����true

ʾ�� 3��
���룺s = "(]"
�����false
*/

class Solution
{
public:
    bool isValid(string s)
    {
        // ˼·����ջ�ж�
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