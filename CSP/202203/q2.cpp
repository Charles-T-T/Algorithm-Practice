#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// PJD的解法
constexpr int N = 1e4 + 5;

class Solution1
{
public:
    void solve() {
        // scanf("%d%d%d", &n, &m, &k);
        cin >> n >> m >> k;
        for (int i = 1; i <= n; ++i)
        {
            int t, c;
            // scanf("%d%d", &t, &c);
            cin >> t >> c;
            add[i] = t;
            sub[i] = t - c;
        }
        sort(add + 1, add + n + 1);
        sort(sub + 1, sub + n + 1);
        for (int i = 1; i <= m; ++i)
        {
            int q;
            // scanf("%d", &q);
            cin >> q;
            int ans = howManyEqualOrLarge(add, q + k) - howManyEqualOrLarge(sub, q + k);
            // printf("%d\n", ans);
            cout << ans << "\n";
        }
    }

protected:
    int n; // 出行计划数目
    int m; // 查询个数
    int k; // 等待核酸结果时间

private:
    int add[N];
    int sub[N];

    int howManyEqualOrLarge(int *arr, int x) {
        int first_one_equal_or_large = 
            lower_bound(arr + 1, arr + n + 1, x) - arr - 1;
        return n - first_one_equal_or_large;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << (4 * 1e7 + 20) / 1024 / 1024 << endl;

    Solution1 obj1;
    obj1.solve();

    return 0;
}

/*
6 2 10
5 24
10 24
11 24
34 24
35 24
35 48
1
2
*/