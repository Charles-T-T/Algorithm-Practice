#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�

ע�⣺�� s �� t ��ÿ���ַ����ֵĴ�������ͬ����� s �� t ��Ϊ��ĸ��λ�ʡ�


ʾ�� 1:
����: s = "anagram", t = "nagaram"
���: true

ʾ�� 2:
����: s = "rat", t = "car"
���: false
*/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
            return true;
        else
            return false;
    }
};