#include "../../Binary-tree/TreeNode.h"

class Solution
{
private:
    int count = 0;

    /// @brief 从叶子节点自下往上后序遍历，确定摄像机的位置
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