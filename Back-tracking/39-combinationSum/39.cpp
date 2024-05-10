#include <iostream>
#include <vector>

using namespace std;

/*
����һ�� ���ظ�Ԫ�� ���������� candidates ��һ��Ŀ������ target ���ҳ� candidates �п���ʹ���ֺ�ΪĿ���� target �� ���� ��ͬ��� �������б���ʽ���ء�����԰� ����˳�� ������Щ��ϡ�

candidates �е� ͬһ�� ���ֿ��� �������ظ���ѡȡ ���������һ�����ֵı�ѡ������ͬ������������ǲ�ͬ�ġ�

���ڸ��������룬��֤��Ϊ target �Ĳ�ͬ��������� 150 ����

ʾ�� 1��
���룺candidates = [2,3,6,7], target = 7
�����[[2,2,3],[7]]
���ͣ�
2 �� 3 �����γ�һ���ѡ��2 + 2 + 3 = 7 ��ע�� 2 ����ʹ�ö�Ρ�
7 Ҳ��һ����ѡ�� 7 = 7 ��
������������ϡ�

ʾ�� 2��
����: candidates = [2,3,5], target = 8
���: [[2,2,2,2],[2,3,3],[3,5]]

ʾ�� 3��
����: candidates = [2], target = 1
���: []
*/

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> curComb;

public:
    void backTracking(const vector<int> &candidates, int target, int sum, int startIndex){
        // ȷ���ݹ����
        if (sum == target){
            res.push_back(curComb);
            return;
        }
        if (sum > target)
            return;

        for (int i = startIndex; i < candidates.size(); i++){
            // ����
            sum += candidates[i];
            curComb.push_back(candidates[i]);

            // �ݹ�
            backTracking(candidates, target, sum, i); // ע�����ﲻ��i+1

            // ����
            sum -= candidates[i];
            curComb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backTracking(candidates, target, 0, 0);
        return res;
    }

    void ShowRes(){
        cout << "[";
        for (int i = 0; i < res.size(); i++)
        {
            cout << "[ ";
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << "]";
        }
        cout << "]";
    }
};

int main(){
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution obj;

    vector<vector<int>> res = obj.combinationSum(candidates, target);
    obj.ShowRes();

    return 0;
}