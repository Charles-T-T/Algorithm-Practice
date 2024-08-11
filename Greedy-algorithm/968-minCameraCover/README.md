# 968. 监控二叉树

[点此跳转题目链接](https://leetcode.cn/problems/binary-tree-cameras/description/)

## 题目描述

给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视**其父对象、自身及其直接子对象。**

计算监控树的所有节点所需的最小摄像头数量。

 

**示例 1：**

![img](./bst_cameras_01.png)

```
输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。
```

**示例 2：**

![img](./bst_cameras_02.png)

```
输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
```


**提示：**

1. 给定树的节点数的范围是 `[1, 1000]`。
2. 每个节点的值都是 0。



## 题解

比较巧妙的贪心算法利用。结合给出的示例，我们不难想出一种最节省摄像头的方案：如果如果当前节点、子节点、父节点都没有被监控范围覆盖，则在当前节点添加一个摄像头即可。例如，要将监控下面这棵单侧树的所有6个节点：

```sh
          0 
         /
        0
       /
      0
     /
    0
   /
  0
 /
0
```

只需要在第1和第5个节点处添加摄像头即可（用 '2' 表示摄像头）：

```sh
          0 
         /
        2
       /
      0
     /
    0
   /
  2
 /
0
```

同时可以发现，我们总是不需要在叶子节点安装摄像头的（除非是平凡树），即应该从叶子节点开始向上**贪心地**尽可能少地安装摄像头。因此，应当需要一种自下而上的算法，自然联想到**后序遍历**。考虑递归方法解决，基本框架应该是：

```cpp
int traversal(TreeNode* cur) {
    if (终止条件) return ;

    int left = traversal(cur->left);    // 左
    int right = traversal(cur->right);  // 右

    逻辑处理                            // 中
    return ;
}
```

返回一个整数，表示当前节点此时的状态——无外乎3种：

- 未覆盖（ `0` ）
- 有覆盖但不是摄像头（ `1` ）
- 是摄像头（ `2` ）

根据子节点的状态，可以确定当前节点是否安装摄像头：

```cpp
class Solution
{
private:
    int count = 0;

    /// @brief 从叶子节点自下而上后序遍历，确定摄像摄像头的位置
    /// @param cur
    /// @return 当前节点未覆盖(0)，被覆盖但无摄像头(1)，有摄像头(2)
    int traverse(TreeNode *cur)
    {
        if (!cur)
            return 1; // 空节点认为被覆盖但无摄像头

        int left = traverse(cur->left);   // 左
        int right = traverse(cur->right); // 右

        // 中
        if (!left || !right) // 左右孩子中有没被覆盖的
        { 
            count++;
            return 2; // 放摄像头
        }
        else if (left == 2 || right == 2) // 左右孩子中有摄像头
            return 1;                     // 当前节点肯定被覆盖，没必要放摄像头
        else                              // 左右孩子都被覆盖但都不是摄像头
            return 0;                     // 当前节点（暂时）不覆盖，交给父节点解决
    }

public:
    int minCameraCover(TreeNode *root)
    {
        if (!traverse(root))
            return count + 1;
        else
            return count;
    }
};
```

:warning: 注意两处细节：

- 空节点被认为是“被覆盖但无摄像头”，因为这样才确保能其父节点（即叶子节点）不会安装多余的摄像头
- 最后要检查一下根节点 `root` 是否被覆盖，如没有还需要给它自己再安一个摄像头