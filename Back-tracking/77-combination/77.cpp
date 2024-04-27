#include <iostream> 
#include <vector>

using namespace std;

/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。

示例 1：
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

示例 2：
输入：n = 1, k = 1
输出：[[1]]
*/

class Solution // 回溯算法解决，利用树结构理解
{
private:
    vector<int> path; // 存储当前经过的树的节点路径
    vector<vector<int>> res; // 存储最终结果

public:
    // 回溯函数
    void backTracking(int n, int k, int start){
        if (path.size() == k){
            res.push_back(path);
            return;
        } // 递归出口

        for (int i = start; i <= n; i++)
        {
            path.push_back(i); // 处理
            backTracking(n, k, i + 1); // 递归
            path.pop_back(); // 回溯
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        backTracking(n, k, 1);
        return res;
    }
};