#include <iostream>
#include <string>
#include <vector>

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
    void reverseString(string &s, int lp, int rp)
    {
        while (lp <= rp)
            swap(s[lp++], s[rp--]);
    }

    string reverseStr(string s, int k)
    {
        int dk = 2 * k;
        int p = 0; // ��ǵ�ǰ�ַ���λ��
        int lp, rp;
        int size = s.size();
        while (p < size)
        {
            if (size - p < 2 * k)
            {
                if (size - p < k)
                {
                    // ���ʣ���ַ�����k����������ȫ����ת
                    reverseString(s, p, size - 1);
                    return s;
                }
                else
                {
                    // ���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ��
                    reverseString(s, p, p + k - 1);
                    return s;
                }
            }
            else
            {
                reverseString(s, p, p + k - 1);
                p += 2 * k;
            }
        }

        return s;
    }
};