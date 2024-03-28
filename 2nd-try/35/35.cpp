#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // ����ʱ�临�Ӷ�Ҫ�󣬲��ö��ֲ���
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right){
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target){
                left = mid + 1;
                continue;
            }
            else{
                right = mid - 1;
                continue;
            }
        }

        return left;
    }
};