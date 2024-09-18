#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int k;
    cin >> n >> k;

    unordered_set<int> left;
    int result = 0;
    for (int i = 0; i < k; ++i) {
        int x;
        int y;
        cin >> x >> y;
        if (left.find(y) == left.end() && y != 0) 
            result++;
        left.insert(x);
    }
    cout << result << endl;

    return 0;
}

/*
10 7
1 2
3 3
3 0
3 3
6 2
2 1
8 2
*/