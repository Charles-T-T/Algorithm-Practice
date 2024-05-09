#include <iostream>
#include <vector>

using namespace std;

/*
����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�

�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��

ʾ�� 1��
���룺digits = "23"
�����["ad","ae","af","bd","be","bf","cd","ce","cf"]

ʾ�� 2��
���룺digits = ""
�����[]

ʾ�� 3��
���룺digits = "2"
�����["a","b","c"]
*/

class Solution
{
private:
    const string letterDict[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    }; // ����-��ĸ����

    vector<string> res; // �洢���ս��
    string curStr = ""; // ������ʱ�洢res�е�ÿ���ַ���

public:
    void backTracking(const string &digits, int index)
    {
        if (index == digits.length())
        {
            // ֮ǰ�Ѿ�������
            res.push_back(curStr);
            return;
        }

        int num = digits[index] - '0';
        string letters = letterDict[num];
        for (int i = 0; i < letters.length(); i++)
        {
            curStr += letters[i];            // ����
            backTracking(digits, index + 1); // �ݹ�
            curStr.pop_back();               // ����
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return res;

        backTracking(digits, 0);
        return res;
    }
};
