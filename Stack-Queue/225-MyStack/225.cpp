#include <iostream>
#include <queue>

using namespace std;

/*
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：
void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

注意：
你只能使用队列的标准操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。


示例：
输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
*/

class MyStack
{
private: 
    queue<int> q1; // q1是本体
    queue<int> q2;

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
        // q1倒进q2，留意最后一个值
        int size = q1.size();
        for (int i = 0; i < size - 1; i++) {
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q1.pop();
        // q2倒回q1
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        // 返回栈顶
        return top;
    }

    int top()
    {
        int top;
        // q1倒进q2，留意最后一个值
        while (1)
        {
            top = q1.front();
            q2.push(top);
            q1.pop();
            if (q1.empty())
                break;
        }
        // q2倒回q1
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        // 返回栈顶
        return top;
    }

    bool empty()
    {
        return q1.empty();
    }
};

class MyStackII
{
private:
    queue<int> q;

public:
    MyStackII() {}

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        int top = q.front();
        q.pop();
        return top;
    }

    int top()
    {
        int top = this->pop();
        q.push(top);
        return top;
    }

    bool empty()
    {
        return q.empty();
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

int main() {
    MyStack ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.pop();
    ms.pop();
    ms.empty();
    return 0;
}