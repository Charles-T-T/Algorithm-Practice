#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        dummyHead = new Node(0, 0);
        tail = dummyHead;
    }

    // 将某个节点 target_node 移动到链表结尾
    void TouchNode(Node *target_node) {
        if (tail == target_node || target_node == nullptr) {
            return;
        }
        target_node->prev->next = target_node->next;
        target_node->next->prev = target_node->prev;
        tail->next = target_node;
        target_node->prev = tail;
        tail = target_node;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        } else {
            Node *target_node = cache[key];
            TouchNode(target_node);
            return target_node->val;
        }
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // 在缓存中，更新节点值，并将节点放到链表结尾
            Node *target_node = cache[key];
            target_node->val = value;
            TouchNode(target_node);
        } else {
            if (cache.size() >= capacity) {
                // 不在缓存且缓存已满，先删除最久没用的节点——即头节点
                cache.erase(dummyHead->next->key);
                if (dummyHead->next == tail) {
                    dummyHead->next = nullptr;
                    tail = dummyHead;
                } else {
                    dummyHead->next = dummyHead->next->next;
                    dummyHead->next->prev = dummyHead;
                }

            }
            // 将新节点放入缓存，接到链表结尾
            Node *newNode = new Node(key, value);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            cache[key] = newNode;
        }
    }

private:
    int capacity;
    unordered_map<int, Node *> cache;  // <key, node>
    Node *dummyHead;
    Node *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache *obj = new LRUCache(1);
    cout << obj->get(6) << endl;
    cout << obj->get(8) << endl;
    obj->put(12, 1);
    cout << obj->get(2) << endl;
    obj->put(15, 11);
    obj->put(5, 2);
    obj->put(1, 15);

    return 0;
}