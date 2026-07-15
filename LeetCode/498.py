class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        N: int = len(mat)
        M: int = len(mat[0])
        diagonals: list[list[int]] = [[] for _ in range(N+M-1)]
        for i in range(N):
            for j in range(M):
                diagonals[i+j].append(mat[i][j])
        result: list[int] = []
        for i in range(N+M-1):
            if i % 2 == 0:
                result.extend(reversed(diagonals[i]))
            else:
                result.extend(diagonals[i])
        return result