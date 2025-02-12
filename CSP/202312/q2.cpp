#include <math.h>

#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<uint64_t> tough_nums = {2,  3,  5,  7, 9,
                                      11, 13, 17, 19};  // 已知的素数

/// @brief 判断x是否为素数
/// @param x
/// @return true or false
bool IsTough(uint64_t x) {
    if (tough_nums.find(x) != tough_nums.end()) {
        return true;
    }

    if (!(x & 1)) {
        return false;
    }

    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }

    tough_nums.insert(x);
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;  // 查询的个数
    cin >> q;

    vector<int> k_vec(q);
    vector<uint64_t> n_vec(q);
    for (int i = 0; i < q; ++i) {
        uint64_t n;
        int k;
        cin >> n_vec[i] >> k_vec[i];
    }

    for (int i = 0; i < q; ++i) {
        uint64_t n = n_vec[i];
        int k = k_vec[i];
        uint64_t n_simple = 1;  // 化简后的n

        // 获取n的各个素因数
        for (uint64_t candidate = 2; candidate * candidate <= n; ++candidate) {
            if (candidate > 2 && !(candidate & 1)) {
                continue;
            }
            if (n % candidate == 0 && IsTough(candidate)) {
                int k_count = 0;  // 该素因数的指数
                uint64_t candidate_product = 1;  
                while (n % candidate == 0) {
                    n /= candidate;
                    candidate_product *= candidate;
                    k_count++;
                }
                if (k_count >= k) {
                    n_simple *= candidate_product;
                }
            }
        }

        cout << n_simple << endl;
    }

    return 0;
}
/*
3
2155895064 3
2 2
10000000000 10
*/

/*
10
1000000007 10
1000000007 10
1000000007 10
1000000007 10
998244353 10
998244353 10
998244353 10
998244353 10
998244353 10
998244353 10
*/