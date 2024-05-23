#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ���Ǹ��������� nums ��һ������ target ��

�������е�ÿ������ǰ��� '+' �� '-' ��Ȼ�������������������Թ���һ�� ���ʽ ��

���磬nums = [2, 1] �������� 2 ֮ǰ��� '+' ���� 1 ֮ǰ��� '-' ��Ȼ���������õ����ʽ "+2-1" ��
���ؿ���ͨ��������������ġ����������� target �Ĳ�ͬ ���ʽ ����Ŀ��



ʾ�� 1��
���룺nums = [1,1,1,1,1], target = 3
�����5
���ͣ�һ���� 5 �ַ���������Ŀ���Ϊ 3 ��
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

ʾ�� 2��
���룺nums = [1], target = 1
�����1

��ʾ��
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/

class Solution
{
private:

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        /**
         * ��x��y�ֱ�Ϊĳ�����ʽ�У�����Ϊ��+����֮�������Ϊ��-����֮��
         * x + y = target
         * ��sumΪnums��������֮��
         * x - y = sum
         * y = x - sum
         * x + x - sum = target
         * x = (target + sum) / 2
         * ���ԣ�Ҫ��ľ������x�Ĳ�ͬ��Ϸ�ʽ�ж�����
        */
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];

        // ������ķ�����x = (target + sum) / 2��Ϊ��������target + sumӦΪż��
        if ((target + sum) % 2 != 0)
            return 0; 
        // ��Ȼ��target�ľ���ֵ���ܴ���sum������ȫΪ����ȫΪ�����ﲻ������Ŀ˵��nums[i] >= 0��
        if (abs(target) > sum)
            return 0;

        /**
         * ���x����01���������˼��
         * nums[i]�൱�ڵ�i����Ʒ������
         * x�൱�ڱ�������
         * �����൱������nums�����Ʒ������Ϊx�ı���װ���ж����ַ�����
        */
        int bagSize = (target + sum) / 2; // Ϊ�˱�����⣬ֱ�Ӱ�x����bagSize

        // �������������ն�̬�滮��׼������
        // ��ʼ��dp���飬dp[i]��ʾ����nums[0] ~ nums[i]��ѡ������װ������Ϊi�ı����ķ�ʽ��
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1; // ��������Դ�����ø�ֵΪ1
        for (int i = 0; i < nums.size(); ++i){
            for (int j = bagSize; j >= nums[i]; --j){ // ע��������j >= nums[i]
                // �ֱ�������Ϊj��������һ����nums[i]����Ʒ�����ҵ�װ��j - nums[i]���������������ٰ�nums[i]װ��ȥ����
                dp[j] += dp[j - nums[i]]; 
            }
        }

        return dp[bagSize];
    }
};

int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    Solution obj;
    cout << "res: " << obj.findTargetSumWays(nums, 3) << endl;

    return 0;
}