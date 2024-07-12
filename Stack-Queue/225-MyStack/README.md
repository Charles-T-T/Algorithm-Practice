# 225. 用队列实现栈

[点此跳转题目链接](https://leetcode.cn/problems/implement-stack-using-queues/description/)

## 题目描述

请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（`push`、`top`、`pop` 和 `empty`）。

实现 `MyStack` 类：

- `void push(int x)` 将元素 x 压入栈顶。
- `int pop()` 移除并返回栈顶元素。
- `int top()` 返回栈顶元素。
- `boolean empty()` 如果栈是空的，返回 `true` ；否则，返回 `false` 。

 

**注意：**

- 你只能使用队列的标准操作 —— 也就是 `push to back`、`peek/pop from front`、`size` 和 `is empty` 这些操作。
- 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

 

**示例：**

```
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
```

 

**提示：**

- `1 <= x <= 9`
- 最多调用`100` 次 `push`、`pop`、`top` 和 `empty`
- 每次调用 `pop` 和 `top` 都保证栈不为空

 

**进阶：** 你能否仅用一个队列来实现栈。



## 题解

思路很简单，用两个队列， `q1` 作为实际存储结构， `q2` 作为辅助数据结构，涉及栈顶的操作则将 `q1` “倒入” `q2` 并注意留下最后一个元素（即 `q1` 队尾元素）作为栈顶元素即可。

**代码（C++）**

```cpp
class MyStack
{
private: 
    queue<int> q1; // q1是本体
    queue<int> q2;

public:
    MyStack() {}

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
```

这样思路应该是最简单的，但是实现也比较繁琐，因为需要经常在两个队列之间倒腾元素。我们可以优化一下，达到题目进阶要求中的**只用一个队列**实现：

> 由于队列是“先进先出”的数据结构，上面用两个队列的地方其实完全可以仅用一个队列实现：根据情况将其队头元素插到队尾即可

```cpp
class MyStack
{
private:
    queue<int> q;

public:
    MyStack() {}

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
```

**Golang**中没有现成的栈和队列，所以这里用go也写一下：

> 这里就直接实现栈了，先实现队列、再用它来实现栈的思路同上。

```go

type MyStack struct {
	slice []int
}


func Constructor() MyStack {
	return MyStack{}
}


func (st *MyStack) Push(x int)  {
	st.slice = append(st.slice, x)
}


func (st *MyStack) Pop() int {
	top := st.slice[len(st.slice) - 1]
	st.slice = st.slice[0 : len(st.slice) - 1]
	return top
}


func (st *MyStack) Top() int {
	top := st.Pop()
	st.slice = append(st.slice, top)
	return top
}


func (st *MyStack) Empty() bool {
	return len(st.slice) == 0
}
```

