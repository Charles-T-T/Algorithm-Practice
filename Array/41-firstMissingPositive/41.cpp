#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> heap;
  void heapfyDown(int i) {
    int n = heap.size();
    while (i < n - 1) {
      int left = 2 * i + 1;
      int right = left + 1;
      int smallest = i;
      if (left < n && heap[left] < heap[smallest]) {
        smallest = left;
      }
      if (right < n && heap[right] < heap[smallest]) {
        smallest = right;
      }
      if (smallest != i) {
        swap(heap[smallest], heap[i]);
        i = smallest;
      } else {
        return;
      }
    }
  }

  // 思路1：建立小根堆，然后依次取出最小值，遇到不连续的做判断。
  int firstMissingPositive(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums.front() == 1 ? 2 : 1;
    }

    heap = nums;
    for (int i = nums.size() / 2 - 1; i >= 0; --i) {
      heapfyDown(i);
    }

    int lastSmallest = heap.front();
    if (lastSmallest > 1) {
      return 1;
    }
    heap[0] = heap.back();
    heap.pop_back();
    heapfyDown(0);

    while (heap.size() > 0) {
      int curSmallest = heap.front();
      if (curSmallest > lastSmallest + 1 && curSmallest > 0) {
        if (lastSmallest < 0 && curSmallest > 1) {
          return 1;
        } 
        if (lastSmallest == 0) {
          return 1;
        } 
        if (lastSmallest > 0) {
          return lastSmallest + 1;
        }
      }
      heap[0] = heap.back();
      heap.pop_back();
      heapfyDown(0);
      lastSmallest = curSmallest;
    }

    return lastSmallest > 0 ? lastSmallest + 1 : 1;
  }
};

int main() {
  vector<int> nums = {3, 4, -1, 1};
  Solution obj;
  cout << obj.firstMissingPositive(nums) << endl;

  return 0;
}