from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.max_path_sum = 0

    def max_single_path(self, root: TreeNode | None) -> int:
        """基于dfs+递归求以当前节点为起点的最长路径
        顺便更新最大路径和
        """
        if root is None:
            return 0
        max_left = self.max_single_path(root.left)
        max_right = self.max_single_path(root.right)
        cur_max_path = root.val + max_left + max_right
        self.max_path_sum = max(self.max_path_sum, cur_max_path)
        return max(0, max(max_left, max_right) + root.val)

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_path_sum = root.val  # 题目说了树中至少有一个节点
        self.max_single_path(root)
        return self.max_path_sum
