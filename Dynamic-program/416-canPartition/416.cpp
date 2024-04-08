#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ�� ֻ���������� �� �ǿ� ���� nums �������ж��Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�

ʾ�� 1��
���룺nums = [1,5,11,5]
�����true
���ͣ�������Էָ�� [1, 5, 5] �� [11] ��

ʾ�� 2��
���룺nums = [1,2,3,5]
�����false
���ͣ����鲻�ָܷ������Ԫ�غ���ȵ��Ӽ���
*/

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        /** 
         * ˼·��
         * ȷ���˷ָ��ȥ��һ���֣�ʣ�µ���Ȼ������һ����
         * ֻҪ�ָ��֮��Ϊ�ܺ͵�һ�뼴��
         * 
         * ת��Ϊ�������⣺
         * ����Ϊtarget�ı������ܷ�ǡ��װ��target��ֵ����Ʒ
        */
        int sum = 0, target;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false; // �ܺͲ���ż������Ȼ�����ָܷ�Ⱥ��Ӽ�
        else
            target = sum / 2;

        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++){
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if (dp[target] == target)
            return true;
        else
            return false;
    }
};
 
int main(){
    vector<int> nums = {1, 5, 11, 5};
    Solution obj;
    if (obj.canPartition(nums))
        cout << "True!" << endl;
    else
        cout << "False!" << endl;

    return 0;
}