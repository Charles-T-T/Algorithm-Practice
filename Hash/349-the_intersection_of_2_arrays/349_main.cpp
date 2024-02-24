#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
������������ nums1 �� nums2 ������ ���ǵĽ��� ���������е�ÿ��Ԫ��һ���� Ψһ �ġ����ǿ��� ��������������˳�� ��

ʾ�� 1��
���룺nums1 = [1,2,2,1], nums2 = [2,2]
�����[2]

ʾ�� 2��
���룺nums1 = [4,9,5], nums2 = [9,4,9,8,4]
�����[9,4]
���ͣ�[4,9] Ҳ�ǿ�ͨ����
*/

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // ˼·���ù�ϣ����
        unordered_set<int> hashSet, resSet;
        vector<int> resVec;

        for (const int &num : nums1)
            hashSet.insert(num);
        for (const int &num : nums2)
        {
            if (hashSet.find(num) != hashSet.end() && resSet.find(num) == resSet.end())
                resVec.push_back(num);

            resSet.insert(num);
        }
        return resVec;
    }
};