#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<string> res;
    string path = "";
    const string letterDict[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};

public:
    void BackTracking(const string &digits, int start)
    {
        // 确定递归出口
        if (start == digits.size())
        {
            res.push_back(path);
            return;
        }

        int num = digits[start] - '0';
        for (int i = 0; i < letterDict[num].size(); i++)
        {
            path += letterDict[num][i];       // 处理
            BackTracking(digits, start + 1); // 递归
            path.erase(path.size() - 1); // 回溯
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return res;
            
        BackTracking(digits, 0);
        return res;
    }

    void show()
    {
        cout << "[ ";
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << "]" << endl;
    }
};

int main()
{
    string digits = "23";
    Solution obj;
    obj.BackTracking(digits, 0);
    obj.show();

    return 0;
}