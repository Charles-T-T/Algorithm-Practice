#include <iostream>
#include <vector>

using namespace std;

/*
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

示例 1：
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4

示例 2：
输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1

示例 3：
输入：nums = [1], target = 0
输出：-1
*/

class Solution {
public:
    int binarySearch(const vector<int> &nums, int target){
        int left = 0, right = nums.size() - 1;
        int mid;
        while(left <= right){
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else    
                right = mid - 1;
        }
        return -1;
    }

    vector<int> mergeVec(const vector<int>& vec1, const vector<int>& vec2){
        vector<int> resVec;
        resVec.insert(resVec.end(), vec1.begin(), vec1.end());
        resVec.insert(resVec.end(), vec2.begin(), vec2.end());
        return resVec;
    }

    int search(vector<int>& nums, int target) {
        // 思路：快速定位到旋转位置，并还原nums，就可以用二分查找了
        if (nums[0] <= nums[nums.size() - 1])
            return binarySearch(nums, target);
        
        // 头尾分别插入极小、大值便于操作
        nums.insert(nums.begin(), -1e6);
        nums.insert(nums.end(), 1e6);

        // 用类似二分查找的方法定位旋转位置
        int left = 1, right = nums.size() - 2;
        int mid;
        int pos;

        while (left <= right){
            /**
             * 4, 5, 6, 7, 0, 1, 2
             * 想要找到7或0对应的位置（这里选0）
             * 可以发现，0是唯一一个“比前后都小”的数
             * 从两边往中间找，过程中左边界应当总大于右边界
            */
            if (left == right){
                pos = right + 1;
                break;
            }

            mid = (left + right) / 2;
            if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]){
                pos = mid;
                break;
            }
            else{
                if (nums[mid] > nums[left]){
                    left = mid;
                    continue;
                }
                else{
                    right = mid;
                    continue;
                }
            }
        }

        vector<int> vec1(nums.begin() + pos, nums.end() - 1);
        vector<int> vec2(nums.begin() + 1, nums.begin() + pos);

        int sortedPos =  binarySearch(mergeVec(vec1, vec2), target);
        if (sortedPos == -1)
            return -1;
        return (sortedPos + pos - 1) % (nums.size() - 2);
    }
};

int main(){
    int target = 3;
    vector<int> nums = {3, 1};
    Solution obj;
    int res = obj.search(nums, target);
    cout << "res: " << res << endl;

    return 0;
}