#include <iostream>
#include <vector>

using namespace std;

class Solution // 暴力解法
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // 暴力解法：每个起点都试一遍
        for (int start = 0; start < gas.size(); ++start)
        {
            int curGas = gas[start];
            if (curGas < cost[start])
                continue;
            curGas -= cost[start];
            for (int i = (start + 1) % gas.size(); i < gas.size(); i = (i + 1) % gas.size())
            {
                if (i == start) // 回到起点
                    return start;
                curGas = curGas + gas[i] - cost[i];
                if (curGas < 0)
                    break;
            }
        }
        return -1;
    }
};

class Solution1_2 // 贪心算法
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int curGasLeft = 0;   // 当前剩余的油量
        int totalGasLeft = 0; // 总剩余油量（= 总gas - 总cost）
        int start = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            curGasLeft += gas[i] - cost[i];
            totalGasLeft += gas[i] - cost[i];
            if (curGasLeft < 0)
            {
                start = i + 1; // 尝试新的起点
                curGasLeft = 0;
            }
        }
        if (totalGasLeft < 0)
            return -1;
        return start;
    }
};

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    Solution obj;
    int res = obj.canCompleteCircuit(gas, cost);
    cout << res << endl;
    return 0;
}