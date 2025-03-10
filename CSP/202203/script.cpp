#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    using iPair = pair<int, int>;
    
    iPair p1 = {1, 2};
    iPair p2 = {3, 4};
    iPair p3 = {3, 9};

    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        else
            return a.second < b.second;
    };
    vector<iPair> pv = {p1, p2, p3};
    sort(pv.begin(), pv.end(), cmp);

    return 0;
}
