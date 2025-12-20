from typing import List


class Coord:
    """坐标"""

    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

    def has_conflict(self, other: "Coord") -> bool:
        if self.x == other.x or self.y == other.y:
            return True
        if abs(self.x - other.x) == abs(self.y - other.y):
            return True
        return False


class Solution:
    def __init__(self):
        self.n = 0
        self.candidate_queens: list[Coord] = []  # 当前正在探索Queen坐标方案
        self.queen_coords_results: list[list[Coord]] = []  # 保存合理方案的Queen坐标

    def backtracking(self, cur_queen: Coord):
        for queen in self.candidate_queens[:-1]:
            if cur_queen.has_conflict(queen):
                return

        if len(self.candidate_queens) == self.n:
            self.queen_coords_results.append(self.candidate_queens)
            return

        for i in range(cur_queen.x + 1, self.n):
            for j in range(0, self.n):
                new_candidate = Coord(i, j)
                self.candidate_queens.append(new_candidate)
                self.backtracking(new_candidate)
                self.candidate_queens = self.candidate_queens[:-1]

    def solveNQueens(self, n: int) -> List[List[str]]:
        self.n = n
        for j in range(n):
            first_queen = Coord(0, j)
            self.candidate_queens = [first_queen]
            self.backtracking(first_queen)

        res: list[list[str]] = []
        for queen_coords in self.queen_coords_results:
            cur_res: list[str] = []
            for queen_coord in queen_coords:
                line = "." * n
                line = line[: queen_coord.y] + "Q" + line[queen_coord.y + 1 :]
                cur_res.append(line)
            res.append(cur_res)
        return res


class Solution2:
    def solveNQueens(self, n: int) -> List[List[str]]:
        """更优雅的回溯"""
        res: list[list[str]] = []
        cols = [-1] * n
        used_cols = set()
        diag1 = set()  # 辅助判断是否处于同一正对角线
        diag2 = set()  # 辅助判断是否处于同一逆对角线

        def backtracking(row: int):
            if row == n:
                board: list[str] = []
                for i in range(n):
                    line = "." * cols[i] + "Q" + "." * (n - 1 - cols[i])
                    board.append(line)
                res.append(board)
                return

            for col in range(n):
                if (col in used_cols or  # 同一列重复
                    (row - col) in diag1 or  # 正对角线上重复
                    (row + col) in diag2  # 逆对角线上重复
                ):
                    continue

                cols[row] = col
                used_cols.add(col)
                diag1.add(row - col)
                diag2.add(row + col)
                
                backtracking(row + 1)

                used_cols.remove(col)
                diag1.remove(row - col)
                diag2.remove(row + col)

        backtracking(0)
        return res

if __name__ == "__main__":
    res = Solution2().solveNQueens(4)
    print(res)
