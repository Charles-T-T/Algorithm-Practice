#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 思路：贪心算法，每天考虑：如果在今天卖出，能赚多少？
        // 因此需要维护一个minBuyin，表示今天之前最低的买入价
        // 以及维护一个maxProfit，表示最大利润
        int minBuyin = prices[0];
        int maxProfit = 0;
        for (int price : prices){
            maxProfit = max(price - minBuyin, maxProfit);
            minBuyin = min(price, minBuyin);
        }

        return maxProfit;
    }
};