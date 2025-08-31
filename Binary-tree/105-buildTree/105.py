from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.inorder_id = dict()
        self.preorder: List[int] = []
        self.inorder: List[int] = []

    def helpBuild(
        self, pre_left: int, pre_right: int, in_left: int, in_right: int
    ) -> TreeNode | None:
        if pre_left > pre_right:
            return None

        root_v = self.preorder[pre_left]
        root_id_inorder = self.inorder_id[root_v]
        left_subtree_size = root_id_inorder - in_left

        root = TreeNode(root_v)
        root.left = self.helpBuild(
            pre_left=pre_left + 1,
            pre_right=pre_left + left_subtree_size,
            in_left=in_left,
            in_right=root_id_inorder - 1,
        )
        root.right = self.helpBuild(
            pre_left=pre_left + left_subtree_size + 1,
            pre_right=pre_right,
            in_left=root_id_inorder + 1,
            in_right=in_right,
        )

        return root

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        self.preorder = preorder
        self.inorder = inorder
        for id, v in enumerate(inorder):
            self.inorder_id[v] = id
        return self.helpBuild(0, len(inorder) - 1, 0, len(inorder) - 1)
