#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    // 判断某个括号组合是否有效
    bool isValid() {
        stack<char> st;
        for (const char &c : path) {
            if (c == '(') {
                st.push(c);
            } else {
                if (st.empty() || st.top() != '(') {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }

    void backTracking(int start, int end) {
        // 剪枝出口：开头为 ')' 或括号数量溢出
        if (path.front() == ')' ||
            count(path.begin(), path.end(), '(') > target ||
            count(path.begin(), path.end(), ')') > target) {
            return;
        }

        // 递归出口：达到目标长度且括号组合有效
        if (path.size() == target * 2 && isValid()) {
            result.push_back(path);
            return;
        }

        // 回溯算法
        for (int i = 0; i <= end; ++i) {
            path += candidates[i];
            backTracking(i, end);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        target = n;
        backTracking(0, 1);
        return result;
    }

private:
    int target;
    vector<char> candidates = {'(', ')'};
    string path = "";
    vector<string> result;
};

// 更优雅的回溯
class Solution_2 {
public:
    void backTracking() {
        // 递归出口：达到目标大小
        if (path.size() == target * 2) {
            result.push_back(path);
            return;
        }

        // 回溯算法
        // 如果当前 path 的左括号数量小于 target，则加一个左括号
        if (left_count < target) {
            path += '(';
            ++left_count;
            backTracking();
            --left_count;
            path.pop_back();
        }
        // 否则，如果此时右括号个数小于左括号，则加一个右括号
        if (right_count < left_count) {
            path += ')';
            ++right_count;
            backTracking();
            --right_count;
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        target = n;
        backTracking();
        return result;
    }

private:
    int target;
    int left_count = 0;
    int right_count = 0;
    string path;
    vector<string> result;
};

int main() {
    Solution obj;
    auto result = obj.generateParenthesis(3);
    cout << result.size() << endl;
    return 0;
}