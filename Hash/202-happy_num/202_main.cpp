#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

/*
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

示例 1：
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

示例 2：
输入：n = 2
输出：false
*/

class Solution
{
public:
    int getSum(int n){
        int sum = 0;
        while (n){
            sum += pow((n % 10), 2);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int res = 0;
        unordered_set<int> resSet;

        // 关键：如何判断进入无限循环——利用集合
        while (res != 1){
            res = getSum(n);
            if (resSet.find(res) != resSet.end())
                return false; // 出现重复的结果，说明进入无限循环
            else
                resSet.insert(res);

            if (res == 1)
                return true;

            n = res;
        }

        return false;
    }
};

int main(){
    int n;
    cout << "please the initial num: ";
    cin >> n;
    Solution obj;
    if(obj.isHappy(n))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}