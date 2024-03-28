#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        /**
         * s[i, j]Ϊ���Ĵ��������ж���
         * 1. s[i + 1, j - 1]�ǻ��Ĵ�
         * 2. s[i] = s[j]
         */
        int len = s.size();
        int maxLen = 1, resStart = 0;
        int dp[len][len];
        // ��ʼ��dp���飨�����ַ����ǻ����Ӵ���
        for (int i = 0; i < len; i++)
            dp[i][i] = 1;
        for (int i = 0; i < len; i++)
        {
            // ������ʼλ��i�ʹ���lȷ���Ӵ���ö��
            for (int l = 2; l <= len; l++)
            {
                // ��l = j - i + 1�ɵ�
                int j = l + i - 1;
                if (j >= len)
                    break;
                // �г�״̬ת�Ʒ���
                if (s[i] == s[j])
                {
                    dp[i][j] = (i + 1 == j) ? 1 : dp[i + 1][j - 1];
                    if (dp[i][j] && l > maxLen)
                    {
                        maxLen = l;
                        resStart = i;
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }

        return s.substr(resStart, maxLen);
    }
};

int main()
{
    string s;
    cout << "please input the s: ";
    cin >> s;
    Solution obj;
    cout << "res: " << obj.longestPalindrome(s) << endl;

    return 0;
}