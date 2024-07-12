# 232. 用栈实现队列

[点此跳转题目链接](https://leetcode.cn/problems/implement-queue-using-stacks/description/)

## 题目描述

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（`push`、`pop`、`peek`、`empty`）：

实现 `MyQueue` 类：

- `void push(int x)` 将元素 x 推到队列的末尾
- `int pop()` 从队列的开头移除并返回元素
- `int peek()` 返回队列开头的元素
- `boolean empty()` 如果队列为空，返回 `true` ；否则，返回 `false`

**说明：**

- 你 **只能** 使用标准的栈操作 —— 也就是只有 `push to top`, `peek/pop from top`, `size`, 和 `is empty` 操作是合法的。
- 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

 

**示例 1：**

```
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
```

 

**提示：**

- `1 <= x <= 9`
- 最多调用 `100` 次 `push`、`pop`、`peek` 和 `empty`
- 假设所有操作都是有效的 （例如，一个空的队列不会调用 `pop` 或者 `peek` 操作）

 

**进阶：**

- 你能否实现每个操作均摊时间复杂度为 `O(1)` 的队列？换句话说，执行 `n` 个操作的总时间复杂度为 `O(n)` ，即使其中一个操作可能花费较长时间。



## 题解

思路很简单：用两个栈来回 **“倒”** ，像两杯水来回倒那样，就可以模拟队列。

比如用栈 `s1` 作为实际存储结构，另一个栈 `s2` 作为辅助结构，要获得“队头”，即 `s1` 的栈底元素，可以将 `s1` 中元素依次出栈、入栈 `s2` ，这样最后在 `s2` 栈顶的就是原来 `s1` 的栈底，即队头元素。

**代码（C++）**

```cpp
class MyQueue
{
private:
    stack<int> s1; // 本体
    stack<int> s2;

public:
    MyQueue(){}

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        // s1倒进s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // 出队列
        int top = s2.top();
        s2.pop();
        // s2倒回s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return top;
    }

    int peek()
    {
        // s1倒进s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // 记录队头元素
        int top = s2.top();
        // s2倒回s1
        while (!s2.empty()) {
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
```

不过上面这种实现方式在涉及栈顶元素的操作时，总是需要倒两遍（ `s1` :arrow_right: `s2` :arrow_right: `s1` ），哪怕连续 `peek` 也是每次如此，比较麻烦。

我们还可以进一步优化，以达到题目的**进阶**要求：每个操作均摊时间复杂度为 $O(1)$ 。方法是让两个栈分别负责“入队列”和“出队列”，分开维护：

```cpp
class MyQueue
{
private:
    stack<int> stIn; 
    stack<int> stOut;

public:
    MyQueue() {}

    void push(int x)
    {
        stIn.push(x);
    }

    int pop()
    {
        // 如果stOut为空，需要先倒入此时的stIn
        if (stOut.empty()) {
            while (!stIn.empty()) {
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
```

**Golang**中没有现成的栈和队列，所以这里用go也写一下：

> 这里就直接实现队列了，先实现栈、再用它来实现队列的思路同上。

```go
type MyQueue struct {
	s []int
}


func Constructor() MyQueue {
	return MyQueue{}
}


func (queue *MyQueue) Push(x int)  {
	queue.s = append(queue.s, x)
}


func (queue *MyQueue) Pop() int {
	top := queue.s[0]
	queue.s = queue.s[1:]
	return top
}


func (queue *MyQueue) Peek() int {
	return queue.s[0]
}


func (queue *MyQueue) Empty() bool {
	return len(queue.s) == 0
}
```

