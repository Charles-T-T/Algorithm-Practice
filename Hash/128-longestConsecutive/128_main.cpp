#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>

using namespace std;

/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

示例 2：
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // 思路：暴力搜索，但是通过判断起始数字是否已经被包含在之前的尝试中，减少不必要的尝试 
        int smallNum, bigNum;
        int maxLength = 0, tempLength;
        int smallFlag = 1, bigFlag = 1;
        int rounds = nums.size();
        unordered_set<int> foundNum;
        for (const int num : nums){
            tempLength = 1;
            foundNum.insert(num);
            smallNum = num - 1, bigNum = num + 1;
            while(rounds--){
                if (find(foundNum.begin(), foundNum.end(), smallNum) != foundNum.end()
                    || find(foundNum.begin(), foundNum.end(), bigNum) != foundNum.end())
                    break;
                
                if (smallFlag && find(nums.begin(), nums.end(), smallNum) != nums.end())
                {
                    tempLength++;
                    foundNum.insert(smallNum--);
                }
                else
                    smallFlag = 0;

                if (bigFlag && find(nums.begin(), nums.end(), bigNum) != nums.end())
                {
                    tempLength++;
                    foundNum.insert(bigNum++);
                }
                else
                    bigFlag = 0;

                if (!bigFlag && !smallFlag)
                    break;
            }

            maxLength = max(maxLength, tempLength);
            rounds = nums.size();
            smallFlag = 1, bigFlag = 1;
        }

        return maxLength;
    }
};

int main(){
    vector<int> nums;
    cout << "please input the nums: ";
    string line, token;
    getline(cin, line);
    stringstream ss(line);
    while (ss >> token)
        nums.push_back(stoi(token));

    Solution obj;
    int maxLength = obj.longestConsecutive(nums);
    cout << "res: " << maxLength << endl;

    return 0;
}