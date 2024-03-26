#include <iostream>

using namespace std;

/*
쳲������� ��ͨ���� F(n) ��ʾ���γɵ����г�Ϊ 쳲��������� ���������� 0 �� 1 ��ʼ�������ÿһ�����ֶ���ǰ���������ֵĺ͡�Ҳ���ǣ�

F(0) = 0��F(1) = 1
F(n) = F(n - 1) + F(n - 2)������ n > 1
���� n ������� F(n) ��

ʾ�� 1��
���룺n = 2
�����1
���ͣ�F(2) = F(1) + F(0) = 1 + 0 = 1

ʾ�� 2��
���룺n = 3
�����2
���ͣ�F(3) = F(2) + F(1) = 1 + 1 = 2

ʾ�� 3��
���룺n = 4
�����3
���ͣ�F(4) = F(3) + F(2) = 2 + 1 = 3
*/

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else
            return fib(n - 1) + fib(n - 2);
    }

    int fib_dynamic(int n)
    {
        if (n <= 1)
            return n;
        int dp[n + 1];
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};