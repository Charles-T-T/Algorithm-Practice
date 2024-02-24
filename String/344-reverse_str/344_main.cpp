#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������

��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣

ʾ�� 1��
���룺s = ["h","e","l","l","o"]
�����["o","l","l","e","h"]

ʾ�� 2��
���룺s = ["H","a","n","n","a","h"]
�����["h","a","n","n","a","H"]
*/

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // ˼·��Ϊ��ԭ���޸ģ�����ͷβ˫ָ��
        int lp = 0, rp = s.size() - 1;
        while (lp <= rp)
            swap(s[lp++], s[rp--]);
    }
};

int main()
{
    vector<char> s;
    int size;
    cout << "please input the size of s: ";
    cin >> size;
    char c;
    cout << "please input s, divided by space: ";
    for (int i = 0; i < size; i++)
    {
        cin >> c;
        s.push_back(c);
    }

    Solution obj;
    obj.reverseString(s);
    cout << "result: [ ";
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << "]";

    return 0;
}