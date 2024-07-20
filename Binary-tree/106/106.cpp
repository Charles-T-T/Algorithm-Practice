#include "../TreeNode.h"

/*
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

示例 1:
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]

示例 2:
输入：inorder = [-1], postorder = [-1]
输出：[-1]

提示:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder 和 postorder 都由 不同 的值组成
postorder 中每一个值都在 inorder 中
inorder 保证是树的中序遍历
postorder 保证是树的后序遍历
*/

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

        log(
            inorder, postorder,
            leftInBegin, leftInEnd, rightInBegin, rightInEnd,
            leftPostBegin, leftPostEnd, rightPostBegin, rightPostEnd
        );

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

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    Solution obj;
    TreeNode *root = obj.buildTree(inorder, postorder);
    showTree(root);

    return 0;
}