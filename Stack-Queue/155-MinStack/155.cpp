#include <iostream>
#include <limits>

using namespace std;

/*
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
 
示例 1:
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
*/

class MinStack {
typedef struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}ListNode;



private:
    int _size;
    int curMinVal;
    ListNode *curMinNode;
    ListNode *dummyHead;

public:
    MinStack() {
        _size = 0;
        curMinVal = numeric_limits<int>::max();
        dummyHead = new ListNode();
        curMinNode = dummyHead;
    }
    
    void push(int val) {
        ListNode *newNode = new ListNode(val, dummyHead->next);
        dummyHead->next = newNode;
        _size++;
        if (val <= curMinVal){
            curMinVal = val;
            curMinNode = newNode;
        }
    }
    
    void pop() {
        if (_size == 0){
            cerr << "empty stack!" << endl;
            return;
        }

        ListNode* temp = dummyHead->next;
        dummyHead->next = dummyHead->next->next;
        _size--;
        if (temp == curMinNode){
            ListNode *cur = dummyHead;
            curMinVal = numeric_limits<int>::max();
            for (int i = 0; i < _size; ++i){
                cur = cur->next;
                if (cur->val < curMinVal){
                    curMinVal = cur->val;
                    curMinNode = cur;
                }
            }
        }
        delete temp;
    }
    
    int top() {
        return dummyHead->next->val;
    }
    
    int getMin() {
        return curMinVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "min: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "top: " << minStack.top() << endl;
    cout << "min: " << minStack.getMin() << endl;

    return 0;
}