#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum_Fail(vector<int> &nums)
    {
        // 哈希表 + 分治
        vector<vector<int>> res;
        unordered_map<int, vector<pair<int, int>>> sumMap; // 前两个数 a, b 之和及其下标
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
                sumMap[nums[i] + nums[j]].emplace_back(i, j);
        }

        // 用一个哈希集合存已得到结果（三元组转为字符串），便于去重
        unordered_set<string> strSet;

        // 查找第三个数 c 凑成 0 所需的前两数之和，即 -c
        for (int i = 0; i < nums.size(); i++)
        {
            if (sumMap.find(-nums[i]) != sumMap.end())
            {
                for (pair p : sumMap[-nums[i]])
                {
                    if (i == p.first || i == p.second)
                        continue; // 三元组中不能有同一下标的数字
                    vector<int> vec = {nums[i], nums[p.first], nums[p.second]};
                    sort(vec.begin(), vec.end());
                    string str = to_string(vec[0]) + "_" + to_string(vec[1]) + "_" + to_string(vec[2]);
                    if (strSet.find(str) == strSet.end())
                    {
                        res.push_back(vec);
                        strSet.insert(str);
                    }
                }
            }
        }
        // sort(res.begin(), res.end());
        return res;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        // 目标三元组为 (a, b, c)
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0) break; // 升序排列后，第一个数a仍大于0，则三元组之和必大于0了
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 对a去重

            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int curSum = nums[i] + nums[left] + nums[right];
                if (curSum == 0)
                {
                    res.emplace_back(vector<int>{nums[i], nums[left], nums[right]});

                    // 对left和right去重
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // 双指针向中间移动，进行下一轮
                    left++, right--;
                }
                // 没找到则根据情况移动左右指针
                else if (curSum < 0) left++;
                else right--;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution obj;
    vector<vector<int>> res = obj.threeSum(nums);
    cout << "end" << endl;

    return 0;
}