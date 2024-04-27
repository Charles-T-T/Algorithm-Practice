#include <iostream>
#include <vector>

using namespace std;

/*
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]
解释:
1 + 2 + 4 = 7
没有其他符合的组合了。

示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
解释:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
没有其他符合的组合了。

示例 3:
输入: k = 4, n = 1
输出: []
解释: 不存在有效的组合。
在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
*/

/* 回溯算法 */
class Solution
{
private:
    vector<vector<int>> res; // 结果
    vector<int> path;        // 中间存储的路径

public:
    // 计算k个数的最小和
    int MinSumK(int k)
    {
        int sum = 0;
        for (int i = 1; i <= k; i++)
            sum += i;
        return sum;
    }

    void BackTracing(int k, int targetSum, int curSum, int start)
    {
        // 先确定递归出口
        if (path.size() == k)
        {
            if (curSum == targetSum)
            {
                res.push_back(path);
            }
            return;
        }
        // 剪枝
        if (curSum >= targetSum)
            return;

        // 开始回溯三步走
        for (int i = start; i <= 9; i++)
        {
            curSum += i;
            path.push_back(i);                        // 处理
            BackTracing(k, targetSum, curSum, i + 1); // 递归
            curSum -= i;
            path.pop_back();                          // 回溯
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        // 排除无效情况
        if (MinSumK(k) > n)
            return res;

        BackTracing(k, n, 0, 1);
        return res;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> res = obj.combinationSum3(3, 7);

    cout << "test..." << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}