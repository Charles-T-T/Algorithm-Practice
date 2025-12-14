# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.ans = None

    def has_target_child(self, root: "TreeNode", p: "TreeNode", q: "TreeNode") -> bool:
        """用DFS检测当前节点root的子树中是否包含目标节点p或q"""
        if root is None:
            return False
        l_has = self.has_target_child(root.left, p, q)
        r_has = self.has_target_child(root.right, p, q)
        if (l_has and r_has) or (
            (root.val == p.val or root.val == q.val) and (l_has or r_has)
        ):
            self.ans = root
            return True
        return l_has or r_has or root.val == p.val or root.val == q.val

    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        self.has_target_child(root, p, q)
        return self.ans


class Solution2:
    """哈希表存储父节点然后回溯解决"""
    def __init__(self):
        self.parent: dict[int, "TreeNode"] = {}
        self.visited: dict[int, bool] = {}
        self.found_p = False
        self.found_q = False

    def dfs(self, root: "TreeNode", p: "TreeNode", q: "TreeNode") -> None:
        if root is None or self.found_p and self.found_q:
            return
        if root.val == p.val:
            self.found_p = True
        elif root.val == q.val:
            self.found_q = True
        if root.left:
            self.parent[root.left.val] = root
            self.dfs(root.left, p, q)
        if root.right:
            self.parent[root.right.val] = root
            self.dfs(root.right, p, q)

    def lowestCommonAncestor(
        self, root: "TreeNode", p: "TreeNode", q: "TreeNode"
    ) -> "TreeNode":
        self.dfs(root, p, q)
        self.parent[root.val] = None
        while p:
            self.visited[p.val] = True
            p = self.parent[p.val]
        while q:
            if self.visited.get(q.val, False):
                return q
            q = self.parent[q.val]
        return None
