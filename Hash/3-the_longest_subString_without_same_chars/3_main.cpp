#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

ʾ�� 1:
����: s = "abcabcbb"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

ʾ�� 2:
����: s = "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��

ʾ�� 3:
����: s = "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
     ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // ˼·��˫ָ�루����һ���������ڣ�+��ϣ����
        int len = s.size();
        unordered_set<char> charSet;
        int right = -1;
        int res = 0;
        for (int i = 0; i < len; i++)
        {
            if (i > 0)
            {
                charSet.erase(s[i - 1]);
            }

            while (right + 1 < len && charSet.find(s[right + 1]) == charSet.end())
            {
                charSet.insert(s[right + 1]);
                right++;
            }

            res = res > (right - i + 1) ? res : (right - i + 1);
        }

        return res;
    }
};

int main()
{
    string s;
    cout << "please input a string: ";
    cin >> s;
    Solution obj;
    int n = obj.lengthOfLongestSubstring(s);
    cout << "result is: " << n << endl;

    return 0;
}
