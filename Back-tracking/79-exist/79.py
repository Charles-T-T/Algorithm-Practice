from typing import List


class Solution(object):
    def __init__(self):
        self.path = ""
        self.visited: list[list[bool]]
        self.moves = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    def legalPos(self, i: int, j: int, board: list[list[str]]) -> bool:
        return i >= 0 and i < len(board) and j >= 0 and j < len(board[0])

    def backTracking(self, board, word, i, j) -> bool:
        self.path += board[i][j]

        l = len(self.path)
        if l == len(word):
            if self.path == word:
                return True
            else:
                self.path = self.path[: l - 1]
                return False

        if self.path[l - 1] != word[l - 1]:
            self.path = self.path[: l - 1]
            return False

        self.visited[i][j] = True
        for movei, movej in self.moves:
            newi, newj = i + movei, j + movej
            if self.legalPos(newi, newj, board) and not self.visited[newi][newj]:
                if self.backTracking(board, word, newi, newj):
                    return True
        self.visited[i][j] = False
        self.path = self.path[: l - 1]
        return False

    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        self.visited = [[False] * len(board[0]) for _ in range(len(board))]
        for i, _ in enumerate(board):
            for j, _ in enumerate(board[0]):
                if self.backTracking(board, word, i, j):
                    return True

        return False


class Solution2:
    """更优雅高效的解决方法"""

    def exist(self, board: List[List[str]], word: str) -> bool:
        # 如果 word 中有某个字符在 board 中根本不够，直接返回 False
        from collections import Counter

        c_word = Counter(word)
        c_board = Counter(c for row in board for c in row)
        for char in c_word:
            if c_word[char] > c_board.get(char, 0):
                return False

        # 回溯，但是不额外维护 visited 和 path
        def backTracking(board, word, i, j, k) -> bool:
            # k 表示当前匹配到的 word 中字符的下标
            if k == len(word):
                return True
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
                return False
            if board[i][j] != word[k]:
                return False
            if board[i][j] == "#":
                return False

            saved, board[i][j] = board[i][j], "#"
            found = (
                backTracking(board, word, i + 1, j, k + 1)
                or backTracking(board, word, i, j + 1, k + 1)
                or backTracking(board, word, i - 1, j, k + 1)
                or backTracking(board, word, i, j - 1, k + 1)
            )
            board[i][j] = saved
            return found

        for i in range(len(board)):
            for j in range(len(board[0])):
                if backTracking(board, word, i, j, 0):
                    return True

        return False


if __name__ == "__main__":
    obj = Solution()
    board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
    word = "ABCCED"
    print(obj.exist(board, word))
