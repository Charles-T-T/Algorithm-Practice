#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    unordered_map<int, int> num_count;
public:
    int majorityElement(vector<int>& nums) {
        int limit = nums.size() / 2;
        for (int &num : nums) {
            if (num_count.find(num) != num_count.end()) {
                ++num_count[num];
            } else {
                num_count[num] = 1;
            }
            if (num_count[num] > limit) {
                return num;
            }
        }
        return 0;
    }
};