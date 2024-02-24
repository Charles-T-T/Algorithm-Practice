#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ���ַ��� s ��һ������ k�����ַ�����ͷ����ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ���

���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����

ʾ�� 1��
���룺s = "abcdefg", k = 2
�����"bacdfeg"

ʾ�� 2��
���룺s = "abcd", k = 2
�����"bacd"
*/

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (i + k - 1 < s.size())
                // ֮����ַ���>=k����תk��
                reverse(s.begin() + i, s.begin() + i + k); 
            else
                // ֮����ַ�������k��ȫ����ת
                reverse(s.begin() + i, s.end()); 
        }
         
        return s;
    }
};