# 二叉树的前、中、后序遍历

[前序遍历题目链接](https://leetcode.cn/problems/binary-tree-preorder-traversal/description/)

[中序遍历题目链接](https://leetcode.cn/problems/binary-tree-inorder-traversal/description/)

[后序遍历题目链接](https://leetcode.cn/problems/binary-tree-postorder-traversal/description/)

## 题目描述

非常直白的三种遍历方式，基本概念参见  [代码随想录-二叉树理论基础](https://programmercarl.com/二叉树理论基础.html#二叉树的存储方式) ，不在此赘述。

## 题解

### 递归法

由于二叉树的结构较为简单、统一，很容易用递归写出三种遍历方式，而且代码都很相似，思路也很简单：先确定递归出口（遇到空节点），再按指定顺序递归处理当前节点、左孩子节点和右孩子节点即可。

**代码（C++）**

前序遍历

```cpp
void Traverse(TreeNode *cur, vector<int> &res)
{
    if (!cur) // 递归出口
        return;
    // 前序遍历，顺序：中 左 右
    res.push_back(cur->val);   // 中
    Traverse(cur->left, res);  // 左
    Traverse(cur->right, res); // 右
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    Traverse(root, res);
    return res;
}
```

中序遍历

```cpp
void Traverse(TreeNode *cur, vector<int> &res)
{
    if (!cur) // 递归出口
        return;
    // 中序遍历，顺序：左 中 右
    Traverse(cur->left, res);  // 左
    res.push_back(cur->val);   // 中
    Traverse(cur->right, res); // 右
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    Traverse(root, res);
    return res;
}
```

后续遍历

```cpp
void Traverse(TreeNode *cur, vector<int> &res) {
    if (!cur) // 递归出口
        return;
    // 后序遍历，顺序：左 右 中
    Traverse(cur->left, res);  // 左
    Traverse(cur->right, res); // 右
    res.push_back(cur->val);   // 中
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    Traverse(root, res);
    return res;
}
```

### 迭代法

由于递归函数本质上就是通过栈实现的，我们自然也可以直接利用栈采取迭代法实现三种遍历方式，这样的时空开销也会更小。

> 有关递归函数的底层实现机制，可以阅读 [这篇文章](https://cloud.tencent.com/developer/article/1705922) 

比如，实现前序遍历时，我们希望得到的节点顺序（节点出栈顺序）是“中-左-右”，那么节点入栈时的顺序就应该反过来，为“右-左-中”：

```cpp
vector<int> preorderTraversal_II(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;
    if (!root)
        return res;
    st.push(root);
    while (!st.empty())
    {
        // 要让出栈顺序为“中左右”，则入栈顺序应为“右左中”
        TreeNode *mid = st.top();
        st.pop();
        res.push_back(mid->val);
        if (mid->right)
            st.push(mid->right); // 右
        if (mid->left)
            st.push(mid->left); // 左
    }
    return res;
}
```

后序遍历的迭代法思路和上面类似，代码如下：

```cpp
vector<int> postorderTraversal_II(TreeNode *root) 
{
    vector<int> res;
    if (!root)
        return res;
    stack<TreeNode*> st;
    st.push(root);
    // 最终目标是“左右中”，那么先按“中右左”遍历，最后反转结果即可
    while (!st.empty()) {
        // 现在要得到“中右左”的出栈顺序，则按“左右中”入栈
        TreeNode *mid = st.top();
        st.pop();
        res.push_back(mid->val);
        if (mid->left) st.push(mid->left); // 左
        if (mid->right) st.push(mid->right); // 右
    }
    reverse(res.begin(), res.end()); // 反转结果
    return res;
}
```

但是按照这种思路，中序遍历的代码就不是简单改两行能实现的了：
```cpp
vector<int> inorderTraversal_II(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    while (cur || !st.empty())
    {
        // 中序遍历特点：每次都要从当前节点的“最左”节点开始遍历
        if (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = st.top();
            st.pop();
            res.push_back(cur->val); // 左
            cur = cur->right;        // 右
        }
    }
    return res;
}
```

可以看到，上述迭代法的思路类似、但是还不够“统一”。下面提供一种统一的迭代思路。

### 统一迭代法

对比下面统一迭代法实现前、中、后序遍历的代码，可以发现只是在入栈顺序处有所调整，其他部分都是 **“统一”** 的。思路见注释，更深入的讲解参见 [代码随想录-二叉树的统一迭代法](https://programmercarl.com/二叉树的统一迭代法.html#思路) 。

前序遍历

```cpp
vector<int> preorderTraversal_III(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop(); // 先从栈中弹出节点，便于后面统一按照“右左中”的顺序入栈
        if (cur)
        {
            if (cur->right)
                st.push(cur->right); // 右
            if (cur->left)
                st.push(cur->left); // 左
            st.push(cur);           // 中
            st.push(nullptr);       // 标记，表示当前节点入栈但尚未被访问
        }
        else
        {
            res.push_back(st.top()->val);
            st.pop();
        }
    }
    return res;
}
```

中序遍历

```cpp
vector<int> inorderTraversal_III(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop(); // 先从栈中弹出节点，便于后面统一按照“右中左”入栈
        if (cur)
        {
            if (cur->right)
                st.push(cur->right); // 右
            st.push(cur);            // 中
            st.push(nullptr);        // 标记，表示当前节点入栈但尚未访问
            if (cur->left)
                st.push(cur->left); // 左
        }
        else
        {
            // 遇到空指针标记
            res.push_back(st.top()->val); // 该访问的节点值计入结果集
            st.pop();                     // 弹出访问完毕的节点
        }
    }
    return res;
}
```

后序遍历

```cpp
vector<int> postorderTraversal_III(TreeNode *root) 
{
    vector<int> res;
    if (!root)
        return res;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode *cur = st.top();
        st.pop(); // 先从栈中弹出节点，便于后面统一按照“中右左”顺序入栈
        if (cur) {
            st.push(cur); // 中
            st.push(nullptr); // 标记，表示当前节点入栈但尚未被访问
            if (cur->right)
                st.push(cur->right);
            if (cur->left)
                st.push(cur->left);
        } else {
            // 遇到空指针标记
            res.push_back(st.top()->val);
            st.pop();
        }
    }
    return res;
}
```

附一个中序遍历递归法和统一迭代法的go代码。其中，栈可以利用切片的截取操作方便地模拟。

```go
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 递归法
func Traverse(cur *TreeNode, res *[]int) {
	if cur == nil { // 递归出口
		return
	}
	// 中序遍历，顺序：左 中 右
	Traverse(cur.Left, res)      // 左
	*res = append(*res, cur.Val) // 中
	Traverse(cur.Right, res)     // 右
}

func inorderTraversal(root *TreeNode) []int {
	res := make([]int, 0)
	Traverse(root, &res)
	return res
} 

// 统一迭代法
func inorderTraversal_II(root *TreeNode) []int {
	res := make([]int, 0)
	if root == nil {
		return res
	}
	st := []*TreeNode{root}
	for len(st) != 0 {
		cur := st[len(st) - 1]
		st = st[0:len(st) - 1]
		if cur != nil {
			if cur.Right != nil {
				st = append(st, cur.Right) // 右
			}
			st = append(st, cur) // 中
			st = append(st, nil) // 空节点标记
			if cur.Left != nil {
				st = append(st, cur.Left) // 左
			}
		} else {
			// 遇到空指针标记
			res = append(res, st[len(st) - 1].Val)
			st = st [0:len(st) - 1]
		}
	}
	return res
}
```

