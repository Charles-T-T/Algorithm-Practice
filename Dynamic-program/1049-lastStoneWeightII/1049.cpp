#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
��һ��ʯͷ������������ stones ��ʾ������ stones[i] ��ʾ�� i ��ʯͷ��������

ÿһ�غϣ�����ѡ����������ʯͷ��Ȼ������һ����顣����ʯͷ�������ֱ�Ϊ x �� y���� x <= y����ô����Ŀ��ܽ�����£�

��� x == y����ô����ʯͷ���ᱻ��ȫ���飻
��� x != y����ô����Ϊ x ��ʯͷ������ȫ���飬������Ϊ y ��ʯͷ������Ϊ y-x��
������ֻ��ʣ��һ�� ʯͷ�����ش�ʯͷ ��С�Ŀ������� �����û��ʯͷʣ�£��ͷ��� 0��

ʾ�� 1��
���룺stones = [2,7,4,1,8,1]
�����1
���ͣ�
��� 2 �� 4���õ� 2����������ת��Ϊ [2,7,1,8,1]��
��� 7 �� 8���õ� 1����������ת��Ϊ [2,1,1,1]��
��� 2 �� 1���õ� 1����������ת��Ϊ [1,1,1]��
��� 1 �� 1���õ� 0����������ת��Ϊ [1]�����������ֵ��

ʾ�� 2��
���룺stones = [31,26,33,21,40]
�����5

��ʾ��
1 <= stones.length <= 30
1 <= stones[i] <= 100
*/

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        /**
         * ˼·��
         * Ŀ����ʵ�ǽ�ʯ�Ѿ����ܷ�Ϊ��С�ӽ������ѣ�Ȼ����ײ
         * ��̬�滮����ת��Ϊ01��������
         * ����Ϊweight����target = weight / 2
         * dp[j]�ĺ��壺
         * ����Ϊj�ı��������װ�¼�ֵ���˴���ֵ�ϵ�������������Ʒ
         * Ŀ�꣺��dp[target]
         */
        int weight = accumulate(stones.begin(), stones.end(), 0);
        int target = weight / 2;
        vector<int> dp(target + 1, 0);

        for (int i = 0; i < stones.size(); i++){
            for (int j = target; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return weight - dp[target] * 2;
    }
};

int main(){
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    Solution obj;
    cout << "res: " << obj.lastStoneWeightII(stones) << endl;

    return 0;
}