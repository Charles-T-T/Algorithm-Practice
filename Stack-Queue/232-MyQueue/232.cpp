#include <iostream>
#include <stack>

/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：
void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false

说明：
你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。


示例 1：
输入：
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 1, 1, false]

解释：
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
*/

using namespace std;

class MyQueue
{
private:
    stack<int> s1; // 本体
    stack<int> s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        // s1倒进s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        // 出队列
        int top = s2.top();
        s2.pop();
        // s2倒回s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return top;
    }

    int peek()
    {
        // s1倒进s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        // 记录队头元素
        int top = s2.top();
        // s2倒回s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        // 返回队头元素
        return top;
    }

    bool empty()
    {
        return s1.empty();
    }
};

class MyQueueII
{
private:
    stack<int> stIn;
    stack<int> stOut;

public:
    MyQueueII()
    {
    }

    void push(int x)
    {
        stIn.push(x);
    }

    int pop()
    {
        // 如果stOut为空，需要先倒入此时的stIn
        if (stOut.empty())
        {
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        // 出队列（stOut出栈）并返回队头（stOut栈顶）
        int top = stOut.top();
        stOut.pop();
        return top;
    }

    int peek()
    {
        int top = this->pop(); // 直接复用pop()
        stOut.push(top);       // 记得要加回去
        return top;
    }

    bool empty()
    {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */