#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        // 贪心算法：先按身高排，再按前面更高人数排
        vector<vector<int>> queue;
        auto cmp = [](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0])
                return a[0] > b[0];
            return a[1] < b[1];
        };
        sort(people.begin(), people.end(), cmp);
        for (const auto &info : people) 
            queue.insert(queue.begin() + info[1], info);
        return queue;
    }
};

int main()
{
    vector<vector<int>> people = {
        {7, 0},
        {4, 4},
        {7, 1},
        {5, 0},
        {6, 1},
        {5, 2}
    };
    Solution obj;
    vector<vector<int>> res = obj.reconstructQueue(people);

    return 0;
}