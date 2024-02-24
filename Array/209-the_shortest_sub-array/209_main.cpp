#include <iostream>
#include <vector>

using namespace std;

/*
����һ������ n ���������������һ�������� target ��

�ҳ����������������ܺʹ��ڵ��� target �ĳ�����С�� ���������� [numsl, numsl+1, ..., numsr-1, numsr] ���������䳤�ȡ���������ڷ��������������飬���� 0 ��



ʾ�� 1��

���룺target = 7, nums = [2,3,1,2,4,3]
�����2
���ͣ������� [4,3] �Ǹ������µĳ�����С�������顣
ʾ�� 2��

���룺target = 4, nums = [1,4,4]
�����1
ʾ�� 3��

���룺target = 11, nums = [1,1,1,1,1,1,1,1]
�����0
*/
class Solution
{
public:
    int minSubArrayLen1(int target, vector<int> &nums)
    {
        // ˼·��˫ָ��
        int left = 0, right = 0;
        int sum = nums[left];

        // �����һ����>=target
        if (sum >= target)
            return 1;

        while (sum < target && right < nums.size() - 1)
            sum += nums[++right];

        // �������nums������Ҳû��target��
        if (sum < target)
            return 0;

        // ��������˵�����ڷ��������Ĳ�Ϊ0��length
        while (right < nums.size() - 1)
        {
            sum = sum + nums[++right] - nums[left++];
            while (sum > target)
            {
                // ���Գ��ԣ�����ߣ���С�����鳤��
                sum -= nums[left];
                if (sum >= target)
                {
                    left++;
                    continue;
                }
                sum += nums[left];
                break;
            }
        }

        while (sum > target)
        {
            // ���Գ��ԣ�����ߣ���С�����鳤��
            sum -= nums[left];
            if (sum >= target)
            {
                left++;
                continue;
            }
            sum += nums[left];
            break;
        }

        return right - left + 1;
    }

    // Carl's version
    int minSubArrayLen2(int target, vector<int> &nums)
    {
        int left = 0, right = 0;
        int length = 1e6;
        int sum = 0;

        for (right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                int curLength = right - left + 1;
                length = curLength < length ? curLength : length;
                sum -= nums[left++];
            }
        }

        return length == 1e6 ? 0 : length;
    }
};

int main()
{
    vector<int> nums;
    int target, n;
    cout << "please input the target: ";
    cin >> target;
    cout << "please input the length of nums: ";
    cin >> n;

    int num;
    cout << "please input the nums, divided by space:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        nums.push_back(num);
    }

    Solution obj;
    cout << "Result: " << obj.minSubArrayLen1(target, nums) << endl;

    return 0;
}