#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

示例 2：
输入：nums = [0,1]
输出：[[0,1],[1,0]]

示例 3：
输入：nums = [1]
输出：[[1]]
*/

class Solution
{
private:
    vector<vector<int>> res;

public:
    void BackTracking(vector<int> &temp, int startIndex){
        // 确定递归出口
        if (startIndex == temp.size()){
            res.push_back(temp);
            return;
        }

        for (int i = startIndex; i < temp.size(); i++){
            swap(temp[startIndex], temp[i]); // 处理
            BackTracking(temp, startIndex + 1); // 递归
            swap(temp[startIndex], temp[i]); // 回溯
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> temp = nums;
        BackTracking(temp, 0);
        return res;
    }
};



int main(){
    vector<int> nums = {1, 2, 3};
    Solution obj;
    vector<vector<int>> res = obj.permute(nums);


    cout << "res: ";
    cout << "[ ";
    for (int i = 0; i < res.size(); i++){
        cout << "[ ";
        for (int j = 0; j < res[0].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]" << endl;

    return 0;
}