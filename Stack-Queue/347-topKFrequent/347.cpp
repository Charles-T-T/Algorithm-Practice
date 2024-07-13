#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
    struct MoreFreq {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> res;
        auto cmp = [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        unordered_map<int, int> freqMap;
        for (int num : nums)
            freqMap[num]++;
        for (auto pair : freqMap)
            pq.push(pair);
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};