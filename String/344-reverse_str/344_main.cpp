#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

示例 1：
输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]

示例 2：
输入：s = ["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
*/

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        // 思路：为了原地修改，采用头尾双指针
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