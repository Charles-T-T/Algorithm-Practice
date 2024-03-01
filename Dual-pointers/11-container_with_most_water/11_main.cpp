#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。

示例 1：
输入：[1,8,6,2,5,4,8,3,7]
输出：49
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例 2：
输入：height = [1,1]
输出：1
*/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // 思路：这题本质上是一个求矩形最大面积的问题
        // 首先尝试暴力搜索
        int width, length, curS, maxS = 0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++){
                width = j - i;
                length = min(height[i], height[j]);
                curS = width * length;
                maxS = max(maxS, curS);
            }
        }

        return maxS;
    }
};

int main(){
    vector<int> height;
    cout << "please input the heights: ";
    string line, token;
    getline(cin, line);
    stringstream ss(line);
    while(ss >> token)
        height.push_back(stoi(token));

    Solution obj;
    int res = obj.maxArea(height);
    cout << "res: " << res << endl;

    return 0;
}