#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int monotoneIncreasingDigits_Violent(int n) // 暴力解法，超时
    {
        auto isIncreasing = [](int num) -> bool {
            int prev = num % 10; // 较低一位上的数字
            num = (num - prev) / 10;
            while (num) {
                int cur = num % 10; // 当前位上的数字
                if (cur > prev)
                    return false;
                num = (num - cur) / 10;
                prev = cur;
            }
            return true;
            
        };
        for (int res = n; ; res--) {
            if (isIncreasing(res))
                return res;
        }
        return 0;
    }

    // 贪心算法
    int monotoneIncreasingDigits(int n)
    {
        string strN = to_string(n);
        // 从后往前逐位确定
        int flag = strN.size(); // 结果末尾连续9的起始位
        for (int i = strN.size() - 1; i > 0; --i) {
            if (strN[i - 1] > strN[i]) {
                strN[i - 1]--;
                flag = i;
            }
        }
        for (int i = flag; i < strN.size(); ++i)
            strN[i] = '9';
        return stoi(strN);
    }
};
 
/*
          0 
         /
        0
       /
      0
     /
    0
   /
  0
 /
0
*/