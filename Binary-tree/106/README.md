# 106. 从中序和后序遍历序列构造二叉树

[点此跳转题目链接](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/)

## 题目描述

给定两个整数数组 `inorder` 和 `postorder` ，其中 `inorder` 是二叉树的中序遍历， `postorder` 是同一棵树的后序遍历，请你构造并返回这颗 *二叉树* 。

 

**示例 1:**

![img](./tree.jpg)

```
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]
```

**示例 2:**

```
输入：inorder = [-1], postorder = [-1]
输出：[-1]
```

 

**提示:**

- `1 <= inorder.length <= 3000`
- `postorder.length == inorder.length`
- `-3000 <= inorder[i], postorder[i] <= 3000`
- `inorder` 和 `postorder` 都由 **不同** 的值组成
- `postorder` 中每一个值都在 `inorder` 中
- `inorder` **保证**是树的中序遍历
- `postorder` **保证**是树的后序遍历



## 题解

蛮锻炼思维的一道题目 :rocket: 

我觉得核心是要理解两点：

:one: 中序序列 `inorder` 的第 `i` 个值对应的节点，其左、右子树中的节点对应的就是 `i` 左边、右边的序列

:two: 后序序列 `postorder` 的最后一个值，就是该序列对应的二叉树的根节点

这两点不难由中序遍历和后序遍历的定义和性质得出。于是，我们可以据此从根节点递归地“生长”出二叉树：

- 取 `postorder` 的最后一个值 `r` 为根节点 `root`  的值

- 在 `inorder` 中找到 `r` 对应的下标 `i` ，则 `i` 左边的值就对应着 `root` 的左子树、 `i` 右边的值就对应着 `root` 的右子树

  > 题目说了：`inorder` 和 `postorder` 都由 **不同** 的值组成，所以可以根据数值（唯一）对应去找下标

- 以 `i` 为“分割点”，将 `inorder` 拆分为左右两部分；相应地也将 `postorder` 拆分，满足

  - 排除 `postorder` 的最后一个值（因为它是分割点，对应着当前根节点）
  - `postorder` 的左右部分长度和 `inorder` 的左右部分长度相同

- 按照上述方法递归地生成 `root` 的左右子树，递归出口为序列切片已经不可分割则返回空指针

此思路更详细的分析可参阅 [代码随想录此题讲解](https://programmercarl.com/0106.从中序与后序遍历序列构造二叉树.html#算法公开课) 。我的代码如下，包括了一个调试函数 `log` ，用于debug的时候检查每次生成的中序、后序左右子序列长度是否一致、数值是否一一对应（即它们都表示着同一棵子树）：

```cpp
class Solution
{
private:
    // 由于所有值各不相同，先用哈希表存储其在中序、后序数组中的下标
    unordered_map<int, int> inMap, postMap;
    void getIndexMap(const vector<int> &inorder, const vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            inMap[inorder[i]] = i;
            postMap[postorder[i]] = i;
        }
    }

    // todo debug
    void log(
        const vector<int> &inorder, const vector<int> &postorder,
        int inLeftB, int inLeftE, int inRightB, int inRightE,
        int postLeftB, int postLeftE, int postRightB, int postRightE)
    {
        cout << "----------inorder left----------" << endl;
        for (int i = inLeftB; i < inLeftE; ++i)
            cout << inorder[i] << " ";
        cout << endl;

        cout << "---------postorder left---------" << endl;
        for (int i = postLeftB; i < postLeftE; ++i)
            cout << postorder[i] << " ";
        cout << endl;

        cout << "----------inorder right---------" << endl;
        for (int i = inRightB; i < inRightE; ++i)
            cout << inorder[i] << " ";
        cout << endl;

        cout << "-----------post right-----------" << endl;
        for (int i = postRightB; i < postRightE; ++i)
            cout << postorder[i] << " ";
        cout << endl;

        cout << "********************************" << endl;
    }

public:
    /// @brief 根据中序、后序数组的切片（左闭右开），递归获取树中的节点
    /// @param postorder 后序遍历数组（用于初始化当前的新节点）
    /// @param inBegin 当前中序数组的起始指针
    /// @param inEnd 当前中序数组的结尾指针
    /// @param postBegin 当前后序数组的起始指针
    /// @param postEnd 当前后序数组的结尾指针
    /// @return 当前获得的节点
    TreeNode *getNode(
        const vector<int> &inorder, const vector<int> &postorder,
        int inBegin, int inEnd, int postBegin, int postEnd)
    {
        if (inBegin == inEnd)
            return nullptr;

        // 后序数组的最后一个值，就是当前子树根节点的值
        TreeNode *root = new TreeNode(postorder[postEnd - 1]);

        // 定位该节点在中序数组中的位置，作为分割点
        int cutPoint = inMap[root->val];

        // 将中序数组拆分，则root的左右子树对应节点值也就是拆分后的左右部分
        int leftInBegin = inBegin, leftInEnd = cutPoint;     // 左半部分
        int rightInBegin = cutPoint + 1, rightInEnd = inEnd; // 右半部分

        // 相应的，将后序数组也按照同样位置拆分
        int leftPostBegin = postBegin, leftPostEnd = postBegin + (cutPoint - inBegin);     // 左半部分
        int rightPostBegin = postBegin + (cutPoint - inBegin), rightPostEnd = postEnd - 1; // 右半部分

        // log(
        //     inorder, postorder,
        //     leftInBegin, leftInEnd, rightInBegin, rightInEnd,
        //     leftPostBegin, leftPostEnd, rightPostBegin, rightPostEnd
        // );

        // 获取当前root的左右子树，然后返回当前root
        root->left = getNode(
            inorder, postorder, leftInBegin, leftInEnd, leftPostBegin, leftPostEnd);
        root->right = getNode(inorder, postorder, rightInBegin, rightInEnd, rightPostBegin, rightPostEnd);

        return root;
    }

    // 递归、多指针解决
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        getIndexMap(inorder, postorder);
        return getNode(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};
```

上面的写法比较便于理解算法和调试，将 `log` 那部分代码注释取消，运行题目描述中的示例1，可以看到每次递归生成的子序列。以第一次分割为例，有输出：

```
----------inorder left----------
9
---------postorder left---------
9
----------inorder right---------
15 20 7
-----------post right-----------
15 7 20
********************************
...
```

可以看到，中序、后序的左、右子序列都是一一对应的。

实际上，后序遍历的左右子序列没必要每次都全部维护，可以发现代码中我们实际用到的也就是其尾指针（每次指向当前的根节点）。所以可以简化代码如下（来源：LeetCode官方题解）：

```cpp
class Solution {
    int post_idx;
    unordered_map<int, int> idx_map;
public:
    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder){
        // 如果这里没有节点构造二叉树了，就结束
        if (in_left > in_right) {
            return nullptr;
        }

        // 选择 post_idx 位置的元素作为当前子树根节点
        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);

        // 根据 root 所在位置分成左右两棵子树
        int index = idx_map[root_val];

        // 下标减一
        post_idx--;
        // 构造右子树
        root->right = helper(index + 1, in_right, inorder, postorder);
        // 构造左子树
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 从后序遍历的最后一个元素开始
        post_idx = (int)postorder.size() - 1;

        // 建立（元素，下标）键值对的哈希表
        int idx = 0;
        for (auto& val : inorder) {
            idx_map[val] = idx++;
        }
        return helper(0, (int)inorder.size() - 1, inorder, postorder);
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solutions/426738/cong-zhong-xu-yu-hou-xu-bian-li-xu-lie-gou-zao-14/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

