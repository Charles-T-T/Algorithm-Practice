#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
���������ַ��� s �� p���ҵ� s ������ p �� ��λ�� ���Ӵ���������Щ�Ӵ�����ʼ�����������Ǵ������˳��

��λ�� ָ����ͬ��ĸ�������γɵ��ַ�����������ͬ���ַ�������

ʾ�� 1:
����: s = "cbaebabacd", p = "abc"
���: [0,6]
����:
��ʼ�������� 0 ���Ӵ��� "cba", ���� "abc" ����λ�ʡ�
��ʼ�������� 6 ���Ӵ��� "bac", ���� "abc" ����λ�ʡ�

ʾ�� 2:
����: s = "abab", p = "ab"
���: [0,1,2]
����:
��ʼ�������� 0 ���Ӵ��� "ab", ���� "ab" ����λ�ʡ�
��ʼ�������� 1 ���Ӵ��� "ba", ���� "ab" ����λ�ʡ�
��ʼ�������� 2 ���Ӵ��� "ab", ���� "ab" ����λ�ʡ�

��ʾ:
1 <= s.length, p.length <= 3 * 104
s �� p ������Сд��ĸ
*/

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        /**
         * ˼·��
         * ��������
         * ��̬�жϴ����е��ַ������Ӧ�����Ƿ��p�����
         */
        vector<int> index;
        int lenP = p.length(), lenS = s.length();

        if (lenP > lenS)
            return index;

        unordered_map<char, int> target, window;
        for (const char &c : p)
            target[c]++;

        int left = 0, right = 0; // �������ڵ����ұ߽�
        int matchedNum = 0;      // ��ǰ��������pƥ����ַ���
        while (right < lenS)
        {
            if (target.count(s[right]))
            {
                window[s[right]]++;
                if (window[s[right]] == target[s[right]])
                    matchedNum++;
            }

            while (right - left + 1 >= lenP)
            {
                if (matchedNum == target.size())
                    index.push_back(left);

                if (target.count(s[left]))
                {
                    if (window[s[left]] == target[s[left]])
                        matchedNum--;
                    window[s[left]]--;
                }

                left++;
            }
            right++;
        }

        return index;
    }
};

int main()
{
    string s = "cbaebabacd";
    string p = "abc";

    Solution obj;
    vector<int> res = obj.findAnagrams(s, p);
    cout << "[ ";
    for (const int &num : res)
        cout << num << " ";
    cout << "]" << endl;

    return 0;
}