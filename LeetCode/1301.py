class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        n = len(board)
        m = len(board[0])

        dp = [[(0, 0)] * m for _ in range(n)]
        dp[n-1][m-1] = (0, 1)
        for i in range(n-1, -1, -1):
            for j in range(m-1, -1, -1):
                if i == n-1 and j == m-1 or board[i][j] == 'X':
                    continue
                res = []
                if i < n-1:
                    res.append(dp[i+1][j])
                if j < m-1:
                    res.append(dp[i][j+1])
                if i < n-1 and j < m-1:
                    res.append(dp[i+1][j+1])
                
                to_add = 0
                if board[i][j] != 'E':
                    to_add = int(board[i][j])
                
                mx_val = max(res)[0]
                sum_mx_val = sum(r[1] for r in res if r[0] == mx_val)

                real_mx_val = mx_val + to_add if sum_mx_val > 0 else 0

                dp[i][j] = (real_mx_val, sum_mx_val % 1000000007)

        return list(dp[0][0])
                