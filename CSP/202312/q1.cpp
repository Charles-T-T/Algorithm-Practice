#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool operator<(const vector<int> &a, const vector<int> &b)
{
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] >= b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int n;  // 仓库个数
    int m;  // 位置编码的维数
    cin >> n >> m;

    vector<vector<int>> store(n + 1, vector<int>(m, 0)); // 仓库
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> store[i][j];
        }
    }
    
    for (size_t i = 1; i <= n; ++i) {
        int cur_min_upper = 0;  // 当前比store[i]大的仓库中，编号最小的
        for (size_t j = 1; j <= n; ++j) {
            if (j == i) {
                continue;
            }
            if (store[i] < store[j]) {
               cur_min_upper = j;
               break;
            }
        }
        cout << cur_min_upper << endl;
    }
  
    return 0;
}

/*
4 2
0 0
-1 -1
1 2
0 -1
*/
