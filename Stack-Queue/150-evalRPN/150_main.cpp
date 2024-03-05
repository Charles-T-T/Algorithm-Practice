#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

/*
����һ���ַ������� tokens ����ʾһ������ �沨����ʾ�� ��ʾ���������ʽ��

�������ñ��ʽ������һ����ʾ���ʽֵ��������

ע�⣺

��Ч�����Ϊ '+'��'-'��'*' �� '/' ��
ÿ����������������󣩶�������һ������������һ�����ʽ��
��������֮��ĳ������� ����ض� ��
���ʽ�в����������㡣
������һ�������沨����ʾ����ʾ���������ʽ��
�𰸼������м������������ 32 λ ������ʾ��

ʾ�� 1��
���룺tokens = ["2","1","+","3","*"]
�����9
���ͣ�����ʽת��Ϊ��������׺�������ʽΪ��((2 + 1) * 3) = 9

ʾ�� 2��
���룺tokens = ["4","13","5","/","+"]
�����6
���ͣ�����ʽת��Ϊ��������׺�������ʽΪ��(4 + (13 / 5)) = 6

ʾ�� 3��
���룺tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
�����22
���ͣ�����ʽת��Ϊ��������׺�������ʽΪ��
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    // ˼·��������ջ�ֱ�洢���ֺ����
    stack<int> numStack;
    int num, num1, num2, res;

    for (const string &token : tokens)
    {
      try
      {
        // ��ǰ�ַ�Ϊ���֣�ֱ��������ջ
        num = stoi(token);
        numStack.push(num);
      }
      catch (...)
      {
        // ��ǰ�ַ�Ϊ���������ջ������������������
        num1 = numStack.top();
        numStack.pop();
        num2 = numStack.top();
        numStack.pop();

        switch (token[0])
        {
        case '+':
          numStack.push(num1 + num2);
          break;

        case '-':
          numStack.push(num2 - num1);
          break;

        case '*':
          numStack.push(num1 * num2);
          break;

        case '/':
          numStack.push(num2 / num1);
          break;

        default:
          break;
        }
      }
    }

    return numStack.top();
  }
};

int main()
{
  vector<string> tokens;
  string s, token;
  cout << "please input the string s: ";
  getline(cin, s);

  stringstream ss(s);
  while (ss >> token)
  {
    tokens.push_back(token);
  }

  Solution obj;
  int res = obj.evalRPN(tokens);
  cout << "result: " << res << endl;

  return 0;
}