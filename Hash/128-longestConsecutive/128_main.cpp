#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>

using namespace std;

/*
����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�

������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣

ʾ�� 1��
���룺nums = [100,4,200,1,3,2]
�����4
���ͣ���������������� [1, 2, 3, 4]�����ĳ���Ϊ 4��

ʾ�� 2��
���룺nums = [0,3,7,2,5,8,4,6,0,1]
�����9
*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // ˼·����������������ͨ���ж���ʼ�����Ƿ��Ѿ���������֮ǰ�ĳ����У����ٲ���Ҫ�ĳ���
        int maxLength = 0, tempLength = 0;
        int curNum;
        unordered_set<int> numSet; 
        for (const int& num : nums)
            numSet.insert(num);

        // ������ÿһ��num��Ϊ���е����
        for (const int& num : nums){
            if (!numSet.count(num - 1))
            {
                curNum = num;
                tempLength = 1;
                while (numSet.count(++curNum))
                    tempLength++;
            }

            maxLength = max(maxLength, tempLength);
        }

        return maxLength;
    }
};

int main()
{
    vector<int> nums;
    cout << "please input the nums: ";
    string line, token;
    getline(cin, line);
    stringstream ss(line);
    while (ss >> token)
        nums.push_back(stoi(token));

    Solution obj;
    int maxLength = obj.longestConsecutive(nums);
    cout << "res: " << maxLength << endl;

    return 0;
}