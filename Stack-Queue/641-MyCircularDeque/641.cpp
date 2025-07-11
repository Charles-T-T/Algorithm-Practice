#include <iostream>

using namespace std;

class MyCircularDeque {
 private:
  int *queue;
  int front;
  int rear;
  int cap;
  int size;
 public:
  MyCircularDeque(int k) {
    queue = new int[k];
    front = 0;
    rear = 0;
    cap = k;
    size = 0;
  }

  bool insertFront(int value) {
    if (isFull()) return false;
    front = (front + cap - 1) % cap;
    queue[front] = value;
    ++size;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) return false;
    queue[rear] = value;
    rear = (rear + 1) % cap;
    ++size;
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) return false;
    front = (front + 1) % cap;
    --size;
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) return false;
    rear = (rear + cap - 1) % cap;
    --size;
    return true;
  }

  int getFront() {
    return isEmpty() ? -1 : queue[front];
  }

  int getRear() {
    return isEmpty() ? -1 : queue[(rear + cap - 1) % cap];
  }

  bool isEmpty() {
    return size == 0;
  }

  bool isFull() {
    return size == cap;
  }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
  auto *q = new MyCircularDeque(8);
  q->insertFront(5);
  cout << q->getFront() << endl;
  cout << q->isEmpty() << endl;
  q->deleteFront();
  q->insertLast(3);
  cout << q->getRear() << endl;
  q->insertLast(7);
  q->insertFront(7);
  q->deleteLast();
  q->insertLast(4);
  cout << q->isEmpty() << endl;

  return 0;
}