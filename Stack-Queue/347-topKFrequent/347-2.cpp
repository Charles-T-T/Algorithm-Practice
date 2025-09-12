#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> heap;
  int parentID(int id) { return (id - 1) / 2; }
  int leftChildID(int id) { return id * 2 + 1; }
  int rightChildID(int id) { return id * 2 + 2; }
  
  void heapfyDown(int i) {
    int n = heap.size();
    while (i < n) {
      int left = leftChildID(i);
      int right = rightChildID(i);
      int largest = i;
      if (left < n && heap[left] > heap[largest]) {
        largest = left;
      }
      if (right < n && heap[right] > heap[largest]) {
        largest = right;
      }
      if (largest != i) {
        swap(heap[largest], heap[i]);
        i = largest;
      } else {
        return;
      }
    }
  }

  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> num2cnt;
    unordered_map<int, vector<int>> cnt2num;
    for (const int& num : nums) {
      ++num2cnt[num];
    }
    for (const auto& pair : num2cnt) {
      cnt2num[pair.second].push_back(pair.first);
      heap.push_back(pair.second);
    }

    for (int i = heap.size() / 2 - 1; i >= 0; --i) {
      heapfyDown(i);
    }

    vector<int> res;
    for (int i = 0; i < k; ++i) {
      res.push_back(cnt2num[heap[0]].back());
      cnt2num[heap[0]].pop_back();
      heap[0] = heap[heap.size() - 1];
      heap.pop_back();
      heapfyDown(0);
    }

    return res;
  }
};

int main() {
  vector<int> nums = {5, 3, 1, 1, 1, 3, 73, 1};
  int k = 1;
  Solution obj;
  vector<int> res = obj.topKFrequent(nums, k);
  for (auto v : res) {
    cout << v << " ";
  }
  cout << endl;

  return 0;
}