#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int count = ratings.size();
        vector<int> child(ratings.size(), 1);
        // 从左向右遍历，检查：当前比左边大的情况
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                count += child[i - 1];
                child[i] += child[i - 1];
            }
        }
        // 从右向左遍历，检查：当前比右边大的情况
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && child[i] <= child[i + 1]) {
                count += (child[i + 1] + 1 - child[i]);
                child[i] = child[i + 1] + 1;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> ratings = {1, 3, 2, 2, 1};
    Solution obj;
    cout << obj.candy(ratings) << endl;
    return 0;
}

// 1 2 1 1 1
// 1 2 1 2 1