#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

示例 1 ：
输入：nums = [2,2,1]
输出：1

示例 2 ：
输入：nums = [4,1,2,1,2]
输出：4

示例 3 ：
输入：nums = [1]
输出：1
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        for (const int &i : nums){
            if (s.find(i) != s.end())
                s.erase(s.find(i));
            else    
                s.insert(i);
        }
        return *s.begin();
    }

    // 改进版本：巧用异或运算，
    // 把空间复杂度将为O(1)，
    // 时间复杂度仍为O(n)但是实际速度显然会提升
    int singleNumberPro(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            res ^= nums[i];
        return res;
    }
};

int main(){
    int a = 2, b = 3;
    cout << "a ^ b: " << (a ^ b) << endl; // 1
    cout << "a ^ a: " << (a ^ a) << endl; // 0
    cout << "a ^ 0: " << (a ^ 0) << endl; // 2

    return 0;
}