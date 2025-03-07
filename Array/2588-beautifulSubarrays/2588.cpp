#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// FIXME: 超时超内存
class Solution_0 {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int count = (nums[0] == 0);
        int n = nums.size();
        vector<vector<int>> results(n, vector<int>(n, 0));
        results[0][0] = nums[0];
        for (int j = 1; j < n; ++j) {
            results[0][j] = results[0][j - 1] ^ nums[j];
            if (results[0][j] == 0)
                ++count;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                results[i][j] = results[i - 1][j] ^ nums[i - 1];
                if (results[i][j] == 0)
                    ++count;
            }
        }

        // 改成下面这种形式节省了内存，但是仍然超时
        // vector<int> results(nums.size(), nums[0]);
        // for (int i = 1; i < nums.size(); ++i) {
        //     results[i] = results[i - 1] ^ nums[i];
        //     count += (results[i] == 0);
        // }
        // for (int i = 1; i < nums.size(); ++i) {
        //     results[i] = results[i] ^ nums[i - 1];
        //     if (results[i] == 0) {
        //         count++;
        //     }
        //     for (int j = i + 1; j < nums.size(); ++j) {
        //         results[j] = results[j - 1] ^ nums[j];
        //         if (results[j] == 0) {
        //             count++;
        //         }
        //     } 
        // }

        return count;
    }
};

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, long long> xor_prefix_sums_cnt;
        xor_prefix_sums_cnt[0] = 1;
        long long beautiful_cnt = 0;
        int cur_prefix_sum = 0;
        for (const int &num : nums) {
            cur_prefix_sum ^= num;
            beautiful_cnt += xor_prefix_sums_cnt[cur_prefix_sum];
            xor_prefix_sums_cnt[cur_prefix_sum]++;
        }
        return beautiful_cnt;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {4, 3, 1, 2, 4};
    cout << obj.beautifulSubarrays(nums) << endl;

    return 0;
}