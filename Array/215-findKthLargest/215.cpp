#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  // 利用快速排序，找到升序排列下 nums 的第 k 个元素
  int findSeqKth(vector<int>& nums, int l, int r, int k) {
    if (l == r) {
      return nums[k];
    }

    int pivot_id = l + rand() % (r - l);
    int pivot = nums[pivot_id];
    int i = l - 1, j = r + 1;
    while (i < j) {
      do {
        ++i;
      } while (nums[i] < pivot);
      do {
        --j;
      } while (nums[j] > pivot);
      if (i < j) {
        swap(nums[i], nums[j]);
      }
    }

    if (k <= j) {
      return findSeqKth(nums, l, j, k);
    } else {
      return findSeqKth(nums, j + 1, r, k);
    }
  }
  int findKthLargest(vector<int>& nums, int k) {
    return findSeqKth(nums, 0, nums.size() - 1, nums.size() - k);
  }
};

// 最大堆解决：搞成最大堆，然后pop掉前k-1个，此时堆顶就是第k个最大的
class Solution_2 {
 private:
  int parent(int i) {
    return (i - 1) / 2;
  }

  int leftChild(int i) {
    return i * 2 + 1;
  }

  int rightChild(int i) {
    return i * 2 + 2;
  }

  void heapUp(vector<int>& heap, int i) {
    while (i > 0 && heap[i] > heap[parent(i)]) {
      swap(heap[i], heap[parent(i)]);
      i = parent(i);
    }
  }

  void heapDown(vector<int>& heap, int i) {
    int n = heap.size();
    while (i < n) {
      int largest_id = i;
      int left_id = leftChild(i);
      int right_id = rightChild(i);

      if (left_id < n && heap[left_id] > heap[largest_id]) {
        largest_id = left_id;
      }

      if (right_id < n && heap[right_id] > heap[largest_id]) {
        largest_id = right_id;
      }

      if (largest_id == i) break;

      swap(heap[i], heap[largest_id]);
      i = largest_id;
    }
  }

  void push(vector<int>& heap, int value) {
    heap.push_back(value);
    heapUp(heap, heap.size() - 1);
  }

  void pop(vector<int>& heap) {
    heap[0] = heap.back();
    heap.pop_back();
    heapDown(heap, 0);
  }

  void buildHeap(vector<int>& arr) {
    int edge = (arr.size() - 2) / 2;
    for (int i = edge; i >= 0; --i) {
      heapDown(arr, i);
    }
  }
  
 public:
  int findKthLargest(vector<int>& nums, int k) {
    buildHeap(nums);
    for (int i = 0; i < k - 1; ++i) {
      pop(nums);
    }
    return nums[0];
  }
};

int main() {
  vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  Solution_2 obj;
  cout << obj.findKthLargest(nums, 4) << endl;
  return 0;
}

// pivot = 4, nums = [8, 3, 2, 9, 7, 4]
