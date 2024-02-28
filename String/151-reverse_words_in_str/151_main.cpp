#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

/*
����һ���ַ��� s �����㷴ת�ַ����� ���� ��˳��

���� ���ɷǿո��ַ���ɵ��ַ�����s ��ʹ������һ���ո��ַ����е� ���� �ָ�����

���� ���� ˳��ߵ��� ���� ֮���õ����ո����ӵĽ���ַ�����

ע�⣺�����ַ��� s�п��ܻ����ǰ���ո�β��ո���ߵ��ʼ�Ķ���ո񡣷��صĽ���ַ����У����ʼ�Ӧ�����õ����ո�ָ����Ҳ������κζ���Ŀո�


ʾ�� 1��
���룺s = "the sky is blue"
�����"blue is sky the"

ʾ�� 2��
���룺s = "  hello world  "
�����"world hello"
���ͣ���ת����ַ����в��ܴ���ǰ���ո��β��ո�

ʾ�� 3��
���룺s = "a good   example"
�����"example good a"
���ͣ�����������ʼ��ж���Ŀո񣬷�ת����ַ�����Ҫ�����ʼ�Ŀո���ٵ�����һ����
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        // ˼·���ɡ���ת�����뵽����ջ���
        // �ҷ������ַ�������Ҫ�ȴ������Ŀո񣬴���Ƚ�����
        stack<string> wordStack; // �洢s�еĸ������ʵ�ջ
        string word = "", resStr = "";
        for (int i = 0; i < s.size(); i++)
        {
            while (i < s.size() && s[i] != ' ') // �ҵ��������ַ�����һ�������ʡ�
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

        resStr.erase(resStr.end() - 1); // ɾ�����Ŀո�
        return resStr;
    }

    /* �������ռ临�ӶȽϸߣ�ΪO(n)�����Խ��Ϳռ临�Ӷȣ����� */
    // ˼·�����������ո��ٷ�ת�����ַ��������ת���еĵ���
    void removeExtraSpace(string &s)
    {
        // ����˫ָ���������ո�
        int slowP = 0, fastP = 0;
        for (; fastP < s.size(); fastP++)
        {
            if (s[fastP] != ' ')
            {
                if (slowP != 0)
                    s[slowP++] = ' '; // Ϊ�Ǵ��׵������ǰ��Ŀո�
                while (fastP < s.size() && s[fastP] != ' ')
                    s[slowP++] = s[fastP++];
            }
        }

        s.resize(slowP); // ��ȥ��ָ����������ַ�
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