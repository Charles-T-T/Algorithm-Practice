#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

/*
��дһ���㷨���ж�һ���� n �ǲ��ǿ�������

���������� ����Ϊ��

����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���͡�
Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1��
���������� ���Ϊ 1����ô��������ǿ�������
��� n �� ������ �ͷ��� true �����ǣ��򷵻� false ��

ʾ�� 1��
���룺n = 19
�����true
���ͣ�
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

ʾ�� 2��
���룺n = 2
�����false
*/

class Solution
{
public:
    int getSum(int n){
        int sum = 0;
        while (n){
            sum += pow((n % 10), 2);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int res = 0;
        unordered_set<int> resSet;

        // �ؼ�������жϽ�������ѭ���������ü���
        while (res != 1){
            res = getSum(n);
            if (resSet.find(res) != resSet.end())
                return false; // �����ظ��Ľ����˵����������ѭ��
            else
                resSet.insert(res);

            if (res == 1)
                return true;

            n = res;
        }

        return false;
    }
};

int main(){
    int n;
    cout << "please the initial num: ";
    cin >> n;
    Solution obj;
    if(obj.isHappy(n))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}