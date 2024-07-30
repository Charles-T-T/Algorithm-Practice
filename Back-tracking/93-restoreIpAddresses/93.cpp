#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    string ip;
    vector<string> res;
    int partCount = 0; // 有效ip地址应由4个部分组成
    bool isLegalIpPart(const string &s) {
        if (s.size() > 1 && s[0] == '0') // 不能含有前导0
            return false;
        if (s.size() > 3) // 不能超过3位（最大255）
            return false;
        return stoi(s) >= 0 && stoi(s) <= 255;
    }

public:
    void backTracking(const string &s, int cutPos) {
        // 递归出口：分割位置到达字符串末尾，或分割出大于4个部分（纵向遍历）
        if (partCount > 4)
            return;
        if (cutPos >= s.size()) {
            if (partCount == 4)
                res.push_back(ip.substr(1, ip.size() - 1)); // 注意ip开头的'.'要去除
            return;
        }

        // 横向遍历
        for (int i = cutPos; i < s.size(); ++i) {
            // 处理
            string sub = s.substr(cutPos, i - cutPos + 1);
            if (!isLegalIpPart(sub))
                continue;
            ip += "." + sub;
            partCount++;
            // 递归
            backTracking(s, i + 1);
            // 回溯
            while (!ip.empty() && ip.back() != '.') 
                ip.pop_back(); // 删除上次添加的子串
            if (!ip.empty())
                ip.pop_back(); // 删除结尾的 '.'
            partCount--;
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        backTracking(s, 0);
        return res;
    }
};

int main() {
    string s = "25525511135";
    Solution obj;
    vector<string> res = obj.restoreIpAddresses(s);
    for (string str : res)
        cout << str << ",";
    cout << endl;

    return 0;
}