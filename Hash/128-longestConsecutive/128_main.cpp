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
        int smallNum, bigNum;
        int maxLength = 0, tempLength;
        int smallFlag = 1, bigFlag = 1;
        int rounds = nums.size();
        unordered_set<int> foundNum;
        for (const int num : nums){
            tempLength = 1;
            foundNum.insert(num);
            smallNum = num - 1, bigNum = num + 1;
            while(rounds--){
                if (find(foundNum.begin(), foundNum.end(), smallNum) != foundNum.end()
                    || find(foundNum.begin(), foundNum.end(), bigNum) != foundNum.end())
                    break;
                
                if (smallFlag && find(nums.begin(), nums.end(), smallNum) != nums.end())
                {
                    tempLength++;
                    foundNum.insert(smallNum--);
                }
                else
                    smallFlag = 0;

                if (bigFlag && find(nums.begin(), nums.end(), bigNum) != nums.end())
                {
                    tempLength++;
                    foundNum.insert(bigNum++);
                }
                else
                    bigFlag = 0;

                if (!bigFlag && !smallFlag)
                    break;
            }

            maxLength = max(maxLength, tempLength);
            rounds = nums.size();
            smallFlag = 1, bigFlag = 1;
        }

        return maxLength;
    }
};

int main(){
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