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
        // ���ȳ��Ա�������
        int width, length, curS, maxS = 0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++){
                width = j - i;
                length = min(height[i], height[j]);
                curS = width * length;
                maxS = max(maxS, curS);
            }
        }

        return maxS;
    }
};

int main(){
    vector<int> height;
    cout << "please input the heights: ";
    string line, token;
    getline(cin, line);
    stringstream ss(line);
    while(ss >> token)
        height.push_back(stoi(token));

    Solution obj;
    int res = obj.maxArea(height);
    cout << "res: " << res << endl;

    return 0;
}