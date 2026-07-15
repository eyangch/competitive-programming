class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]
        n = len(grid)
        queue = []
        lptr = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    queue.append((i, j, -1))
        while lptr < len(queue):
            i, j, d = queue[lptr]
            lptr += 1
            if grid[i][j] < 0:
                continue
            grid[i][j] = d
            for k in range(4):
                ni, nj = i + dx[k], j + dy[k]
                if 0 <= ni < n and 0 <= nj < n and grid[ni][nj] >= 0:
                    queue.append((ni, nj, d-1))
        
        print(grid)

        def possible(z: int) -> bool:
            if -grid[0][0] < z:
                return False
            vis = [False] * (n * n)
            stack = [(0, 0)]
            while stack:
                i, j = stack.pop()
                if vis[i * n + j]:
                    continue
                vis[i * n + j] = True
                if i == n-1 and j == n-1:
                    return True
                for k in range(4):
                    ni, nj = i + dx[k], j + dy[k]
                    if 0 <= ni < n and 0 <= nj < n:
                        if -grid[ni][nj] < z:
                            continue
                        stack.append((ni, nj))
            return False
            
        
        lo = 0
        hi = 2 * n
        mid = 0
        ans = 0
        while lo <= hi:
            mid = (lo + hi) // 2
            if possible(mid):
                lo = mid+1
                ans = mid
            else:
                hi = mid-1
        return ans - 1