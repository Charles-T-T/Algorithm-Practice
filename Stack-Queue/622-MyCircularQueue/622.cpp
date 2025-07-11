#include <cmath>
#include <iostream>

using namespace std;

class MyCircularQueue {
 private:
  int *queue;
  int front;
  int rear;
  int cap;
 public:
  MyCircularQueue(int k) {
    queue = new int[k + 1];
    front = 0;
    rear = 0;
    cap = k + 1;
  }

  bool enQueue(int value) {
    if (isFull()) return false;
    queue[rear] = value;
    rear = (rear + 1) % cap;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;
    front = (front + 1) % cap;
    return true;
  }

  int Front() {
    return isEmpty() ? -1 : queue[front];
  }

  int Rear() {
    return isEmpty() ? -1 : queue[(rear + cap - 1) % cap];
  }

  bool isEmpty() {
    return front == rear;
  }

  bool isFull() {
    return (rear + 1) % cap == front;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


int main() {
  auto *q = new MyCircularQueue(3);
  q->enQueue(1);
  q->enQueue(2);
  q->enQueue(3);

  cout << q->Front() << endl;
  cout << q->Rear() << endl;

  return 0;
}