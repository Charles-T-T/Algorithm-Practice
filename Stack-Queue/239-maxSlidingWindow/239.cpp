#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <limits>
#include <deque>

using namespace std;

/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

示例 1：
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

示例 2：
输入：nums = [1], k = 1
输出：[1]

提示：
1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/

// 用于解题的单调队列，原则：队列中元素单调递减
class MyQueue
{
private:
    deque<int> q;

public:
    void push(int num)
    {
        while (!q.empty() && q.back() < num)
            q.pop_back();
        q.push_back(num);
    }

    void pop()
    {
        q.pop_front();
    }

    int front()
    {
        return q.front();
    }
};

class Solution
{
public:
    // 暴力解法：超时
    vector<int> maxSlidingWindowViolence(vector<int> &nums, int k)
    {
        vector<int> res;
        int left = 0, right = k - 1;
        while (right < nums.size())
        {
            int maxNum = nums[left];
            for (int i = left + 1; i <= right; i++)
                maxNum = max(maxNum, nums[i]);
            res.push_back(maxNum);
            left++, right++;
        }
        return res;
    }

    // 用队列解决
    // 辅助函数：遍历窗口内数据，返回最大值和它出现的次数，更新队列
    pair<int, int> getMaxInWindow(queue<int> &q, const vector<int> &nums, int left, int right)
    {
        int maxNum = numeric_limits<int>::min();
        unordered_map<int, int> countMap; // <数字，出现的次数>
        for (int i = left; i <= right; ++i)
        {
            maxNum = max(maxNum, nums[i]);
            countMap[nums[i]]++;
        }
        q.push(nums[right]);
        q.pop();
        return make_pair(maxNum, countMap[maxNum]);
    }

    vector<int> maxSlidingWindow_Fail(vector<int> &nums, int k)
    {
        vector<int> res;
        queue<int> q; // 存储当前窗口中数据的双端队列
        int left = 0, right = k - 1;
        // 先存第一个窗口的数据到队列，同时记录最大值
        int lastMax = numeric_limits<int>::min();
        int maxCount = 0;
        unordered_map<int, int> countMap;
        for (int i = left; i <= right; ++i)
        {
            lastMax = max(lastMax, nums[i]);
            countMap[nums[i]]++;
            q.push(nums[i]);
        }
        maxCount = countMap[lastMax];
        // 开始滑动窗口
        while (right < nums.size() - 1)
        {
            res.push_back(lastMax);
            left++, right++;
            if (nums[right] > lastMax)
            {
                lastMax = nums[right];
                maxCount = 1;
            }
            else if (nums[right] == lastMax)
            {
                continue;
            }
            else
            {
                if (lastMax == nums[left - 1])
                {
                    if (maxCount == 1)
                    {
                        auto pair = getMaxInWindow(q, nums, left, right);
                        lastMax = pair.first;
                        maxCount = pair.second;
                    }
                    else
                    {
                        q.push(nums[right]);
                        q.pop();
                        maxCount--;
                    }
                }
                else
                {
                    q.push(nums[right]);
                    q.pop();
                }
            }
        }
        res.push_back(lastMax);
        return res;
    }

    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        MyQueue q;
        for (int i = 0; i < k; ++i) 
            q.push(nums[i]);
        res.push_back(q.front());
        int left = 1, right = k;
        while (right < nums.size()) {
            if (nums[left - 1] == q.front())
                q.pop();
            q.push(nums[right]);
            res.push_back(q.front());
            left++, right++;
        }
        return res;
    }
};



int main()
{
    vector<int> nums = {-7, -8, 7, 5, 7, 1, 6, 0};
    int k = 4;
    Solution obj;
    vector<int> res = obj.maxSlidingWindow(nums, k);
    for (int num : res)
        cout << num << " ";

    return 0;
}