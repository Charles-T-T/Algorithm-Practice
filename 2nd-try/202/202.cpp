#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution
{
private:
    unordered_set<int> numSet; // 已经尝试过的数字

public:
    bool isHappy(int n)
    {
        // 递归
        int sum = 0;
        int nCopy = n;
        while (nCopy) {
            int temp = nCopy % 10;
            sum += pow(temp, 2);
            nCopy = (nCopy - temp) / 10;
        }
        if (sum == 1)
            return true;
        if (numSet.find(n) != numSet.end())
            return false;
        numSet.insert(n); // 防止陷入死循环
        return isHappy(sum);
    }
};