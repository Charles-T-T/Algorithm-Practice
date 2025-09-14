from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.target_sum: int = 0
        self.cur_prefix: int = 0
        self.prefix_cnt: dict[int, int] = {0: 1}
        self.path_cnt: int = 0

    def backtracking(self, root: TreeNode | None):
        if root == None:
            return

        self.cur_prefix += root.val
        need = self.cur_prefix - self.target_sum
        self.path_cnt += self.prefix_cnt.get(need, 0)

        if self.cur_prefix in self.prefix_cnt:
            self.prefix_cnt[self.cur_prefix] += 1
        else:
            self.prefix_cnt[self.cur_prefix] = 1
        self.backtracking(root.left)
        self.backtracking(root.right)
        self.prefix_cnt[self.cur_prefix] -= 1
        self.cur_prefix -= root.val

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.target_sum = targetSum
        self.backtracking(root)
        return self.path_cnt