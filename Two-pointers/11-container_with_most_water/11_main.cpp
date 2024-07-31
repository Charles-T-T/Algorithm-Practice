#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/*
����һ������Ϊ n ���������� height ���� n �����ߣ��� i ���ߵ������˵��� (i, 0) �� (i, height[i]) ��

�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��

�����������Դ�������ˮ����

˵�����㲻����б������

ʾ�� 1��
���룺[1,8,6,2,5,4,8,3,7]
�����49
���ͣ�ͼ�д�ֱ�ߴ����������� [1,8,6,2,5,4,8,3,7]���ڴ�����£������ܹ�����ˮ����ʾΪ��ɫ���֣������ֵΪ 49��

ʾ�� 2��
���룺height = [1,1]
�����1
*/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // ˼·�����Ȿ������һ�������������������
        // ����˫ָ���Ż�ʱ�临�Ӷ�
        int leftP = 0, rightP = height.size() - 1, maxArea = 0;
        while (leftP < rightP)
        {
            maxArea = max(maxArea, (rightP - leftP) * min(height[rightP], height[leftP]));

            // ��������ָ��
            if (height[leftP] < height[rightP])
                leftP++;
            else
                rightP--;
        }
        return maxArea;
    }
};

int main()
{
    vector<int> height;
    cout << "please input the heights: ";
    string line, token;
    getline(cin, line);
    stringstream ss(line);
    while (ss >> token)
        height.push_back(stoi(token));

    Solution obj;
    int res = obj.maxArea(height);
    cout << "res: " << res << endl;

    return 0;
}