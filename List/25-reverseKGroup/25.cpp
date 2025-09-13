#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    // 遍历原链表，依次入栈，栈中达到 k 个就依次弹出、反着连接
    stack<ListNode*> st;
    auto dummyHead = new ListNode(0, head);
    auto cur = head;
    auto prev = dummyHead;
    while (cur) {
      st.push(cur);
      auto groupNext = cur->next;
      if (int(st.size()) == k) {
        st.pop();
        auto tmp = cur;
        while (!st.empty()) {
          tmp->next = st.top();
          tmp = tmp->next;
          st.pop();
        }
        tmp->next = groupNext;
        prev->next = cur;
        prev = tmp;
      }
      cur = groupNext;
    }
    return dummyHead->next;
  }
};

int main() {
  string line;
  cout << "input the values in the List: ";
  getline(cin, line);
  stringstream ss(line);
  auto dummyHead = new ListNode();
  auto cur = dummyHead;
  int val;
  while (ss >> val) {
    cur->next = new ListNode(val);
    cur = cur->next;
  }

  int k;
  cout << "input k: ";
  cin >> k;

  cout << "now List: ";
  cur = dummyHead->next;
  while (cur) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;

  Solution obj;
  cur = obj.reverseKGroup(dummyHead->next, 2);
  cout << "result: ";
  while (cur) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;

  return 0;
}