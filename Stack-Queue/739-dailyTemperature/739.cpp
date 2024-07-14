#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <queue>

using namespace std;

/*
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

示例 1:
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]

示例 2:
输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]

示例 3:
输入: temperatures = [30,60,90]
输出: [1,1,0]

提示：
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

class Solution
{
public:
    vector<int> dailyTemperaturesFail(vector<int> &temperatures)
    {
        // 双端队列解决：此算法超时
        vector<int> res(temperatures.size(), 0);
        deque<pair<int, int>> dq1, dq2;
        for (int i = 0; i < temperatures.size(); ++i)
            dq1.push_back(make_pair(temperatures[i], i));
        while (!dq1.empty())
        {
            auto p1 = dq1.front();
            dq2.push_back(p1);
            dq1.pop_front();
            while (!dq1.empty() && dq1.front().first <= p1.first)
            {
                dq2.push_back(dq1.front());
                dq1.pop_front();
            }
            if (!dq1.empty())
                res[p1.second] = dq1.front().second - p1.second;
            else
                res[p1.second] = 0;
            dq2.pop_front(); // 这天的温度处理完毕，弹出
            while (!dq2.empty())
            {
                dq1.push_front(dq2.back());
                dq2.pop_back();
            }
        }

        return res;
    }

    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        // 单调栈解决：保证栈底到栈顶元素对应的温度递减
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st;
        for (int i = 0; i < temperatures.size(); ++i)
        {
            while (!st.empty() && temperatures[i] > st.top().first)
            {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push(make_pair(temperatures[i], i));
        }
        return res;
    }

    vector<int> dailyTemperatures_TwoPointer(vector<int> &temperatures)
    {
        // 双指针解决
        vector<int> res(temperatures.size(), 0);
        // 从后往前处理各天温度
        // 最后一天在结果中的对应值只能为0，故从倒数第二天开始处理
        for (int cur = temperatures.size() - 2; cur >= 0; --cur)
        {
            int after = cur + 1; // 当前处理天数的后一天，自此往后找
            while (temperatures[after] <= temperatures[cur] && res[after] != 0)
                after += res[after]; // 由于从后向前处理，此时after肯定处理过了
            res[cur] = temperatures[after] > temperatures[cur] ? after - cur : 0;
        }
        return res;
    }
};

int main()
{
    vector<int> t = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
    Solution obj;
    vector<int> res = obj.dailyTemperatures_TwoPointer(t);
    for (int num : res)
        cout << num << " ";
    cout << endl;
    return 0;
}