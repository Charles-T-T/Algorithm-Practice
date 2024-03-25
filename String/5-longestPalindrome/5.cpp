#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        /**
         * �Ӵ�s[i, j]���ĵ�������:
         * 1. s[i] = s[j]
         * 2. s[i + 1, j - 1]�ǻ��Ĵ�
        */
        int len = s.size();
        if (len == 1)
            return s; // �����ַ����ǻ��Ĵ�

        int maxLen = 1, start = 0;
        vector<vector<int>> pd(len, vector<int>(len)); // pd[i][j] = 1[i, j]�ǻ��Ĵ�
        for (int i = 0; i < len; i++)
            pd[i][i] = 1; // �����ַ����ǻ��Ĵ�
        for (int l = 2; l <= len; l++) // ö�٣��ɴ�������ʼλ��ȷ���ִ�
        {
            for (int i = 0; i < len; i++)
            {
                // �� l = j - i + 1�ɵ�
                int j = l + i - 1;
                if (j > len - 1)
                    break;

                if (s[i] != s[j])
                    pd[i][j] = 0;
                else{
                    if (l <= 3 || pd[i + 1][j - 1]){
                        pd[i][j] = 1;
                        maxLen = l;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main(){
    cout << "please input s: ";
    string s;
    cin >> s;
    Solution obj;
    string res = obj.longestPalindrome(s);
    cout << "result: " << res << endl;

    return 0;
}