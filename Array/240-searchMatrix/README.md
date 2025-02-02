# 240. 搜索二维矩阵 II

[点此跳转题目链接](https://leetcode.cn/problems/search-a-2d-matrix-ii/description/?envType=study-plan-v2&envId=top-100-liked)

## 题目描述

编写一个高效的算法来搜索 *`m x n`*  矩阵 `matrix` 中的一个目标值 `target` 。该矩阵具有以下特性：

- 每行的元素从左到右升序排列。
- 每列的元素从上到下升序排列。

**示例 1：**

![img1](./searchgrid2.jpg) 

```
输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true
```

**示例 2：**

![img2](./searchgrid.jpg) 

```
输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
输出：false
```

**提示：**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= n, m <= 300`
- `-109 <= matrix[i][j] <= 109`
- 每行的所有元素从左到右升序排列
- 每列的所有元素从上到下升序排列
- `-109 <= target <= 109`

## 题解

暴力算法直接遍历整个矩阵，时间复杂度为 $O(mn)$ ， $m、n$ 分别为矩阵的行、列数。

由于题中矩阵在行和列上的元素都是升序的，所以想到可以从上到下逐行利用二分查找解决：

```cpp
class Solution {
public:
    int binarySearch(const vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        // 逐行使用二分法查找target
        for (const vector<int>& line : matrix) {
            if (binarySearch(line, target) != -1) {
                return true;
            }
        }
        return false;
    }
};
```

行内 $n$ 个元素做二分查找的时间复杂度为 $O(logn)$ ，共 $m$ 行，故时间复杂度为 $O(mlogn)$ 。

不过上面两种方法似乎都过于直白简单了，考虑到这个题目带的是“中等”tag，肯定还有更高效的算法：

> :link: 以下内容来自 [LeetCode官方题解](https://leetcode.cn/problems/search-a-2d-matrix-ii/solutions/1062538/sou-suo-er-wei-ju-zhen-ii-by-leetcode-so-9hcx/?envType=study-plan-v2&envId=top-100-liked) 

我们可以从矩阵 `matrix` 的右上角 `(0,n−1)` 进行搜索。在每一步的搜索过程中，如果我们位于位置 `(x,y)` ，那么我们希望在以 `matrix` 的左下角为左下角、以 `(x,y)` 为右上角的矩阵中进行搜索，即行的范围为 `[x,m−1]` ，列的范围为 `[0,y]` ：

- 如果 `matrix[x,y]=target` ，说明搜索完成
- 如果 `matrix[x,y]>target` ，由于每一列的元素都是升序排列的，那么在当前的搜索矩阵中，所有位于第 `y` 列的元素都是严格大于 `target` 的，因此我们可以将它们全部忽略，即将 `y` 减少 1
- 如果 `matrix[x,y]<target` ，由于每一行的元素都是升序排列的，那么在当前的搜索矩阵中，所有位于第 `x` 行的元素都是严格小于 `target` 的，因此我们可以将它们全部忽略，即将 `x` 增加 1。

在搜索的过程中，如果我们超出了矩阵的边界，那么说明矩阵中不存在 `target` 。代码实现如下：

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = 0;
        int y = matrix[0].size() - 1;
        while (x < matrix.size() && y >= 0) {
            if (matrix[x][y] < target) {
                x++;
            } else if (matrix[x][y] > target) {
                y--;
            } else {
                return true;
            }
        }
        return false;
    }
};
```

时间复杂度： $O(m+n)$ 。在搜索的过程中，如果我们没有找到 `target` ，那么我们要么将 `y` 减少 1，要么将 `x` 增加 1。由于 `(x,y)` 的初始值分别为 `(0,n−1)` ，因此 `y` 最多能被减少 `n` 次， `x` 最多能被增加 `m` 次，总搜索次数为 `m+n` 。在这之后， `x` 和 `y` 就会超出矩阵的边界。
