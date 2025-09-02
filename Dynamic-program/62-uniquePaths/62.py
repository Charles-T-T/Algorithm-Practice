class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        board = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    board[i][j] = 1
                elif i == 0:
                    board[i][j] = board[i][j - 1]
                elif j == 0:
                    board[i][j] = board[i - 1][j]
                else:
                    board[i][j] = board[i - 1][j] + board[i][j - 1]
        return board[-1][-1]
