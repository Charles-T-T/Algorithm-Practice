#include <iostream>
#include <queue>

using namespace std;

/*
�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����

ʵ�� MyStack �ࣺ

void push(int x) ��Ԫ�� x ѹ��ջ����
int pop() �Ƴ�������ջ��Ԫ�ء�
int top() ����ջ��Ԫ�ء�
boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��

ע�⣺
��ֻ��ʹ�ö��еĻ������� ���� Ҳ���� push to back��peek/pop from front��size �� is empty ��Щ������
����ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���б����� deque��˫�˶��У���ģ��һ������ , ֻҪ�Ǳ�׼�Ķ��в������ɡ�

ʾ����
���룺
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
�����
[null, null, null, 2, 2, false]

���ͣ�
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // ���� 2
myStack.pop(); // ���� 2
myStack.empty(); // ���� False
*/

class MyStack
{
private:
    queue<int> q1, q2;


public:
    MyStack()
    {
        
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        // ��q1�ж�β֮���Ԫ��push��q2
        int size = q1.size() - 1;
        while (size--){
            q2.push(q1.front());
            q1.pop();
        }
        int topNum = q1.front(); // ��ȡ��ջ����Ԫ��
        q1.pop();

        // �ٽ�ʣ�µ�Ԫ�ص���q1
        while (!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return topNum;
    }

    int top()
    {
        int topNum = this->pop();
        q1.push(topNum);
        return topNum;
    }

    bool empty()
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */