#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

/*
������Сд��ĸ��ɵ��ַ��� S���ظ���ɾ��������ѡ��������������ͬ����ĸ����ɾ�����ǡ�

�� S �Ϸ���ִ���ظ���ɾ��������ֱ���޷�����ɾ����

����������ظ���ɾ�������󷵻����յ��ַ������𰸱�֤Ψһ��

ʾ����
���룺"abbaca"
�����"ca"
���ͣ�
���磬�� "abbaca" �У����ǿ���ɾ�� "bb" ��������ĸ��������ͬ�����Ǵ�ʱΨһ����ִ��ɾ���������ظ��֮�����ǵõ��ַ��� "aaca"��������ֻ�� "aa" ����ִ���ظ���ɾ�����������������ַ���Ϊ "ca"��
*/

class Solution
{
public:
    string removeDuplicates(string s)
    {
        // ˼·����ջ�������sÿ���ַ�����ջ���ж��Ƿ������ظ���������pop
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