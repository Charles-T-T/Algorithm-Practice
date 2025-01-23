#include <iostream>
#include <vector>

using namespace std;

/// @brief 二分查找
class Solution {
public:
    int binarySearch(const vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        // 逐行使用二分法查找target
        for (const vector<int>& line : matrix) {
            if (binarySearch(line, target) != -1) {
                return true;
            }
        }
        return false;
    }
};

/// @brief z字查找
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0;
        int y = matrix[0].size() - 1;
        while (x < matrix.size() && y >= 0) {
            if (matrix[x][y] < target) {
                x++;
            } else if (matrix[x][y] > target) {
                y--;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution obj = Solution();
    vector<int> arr = {1, 4, 5, 6, 9, 11, 13};
    cout << obj.binarySearch(arr, 10) << endl;

    vector<vector<int>> m = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout << obj.searchMatrix(m, 5) << endl;

    return 0;
}