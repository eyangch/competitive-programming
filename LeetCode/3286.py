class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]

        n = len(grid)
        m = len(grid[0])

        heap = [(grid[0][0] + 67, 0, 0)]
        grid[0][0] += 67
        while heap:
            d, x, y = heapq.heappop(heap)
            for k in range(4):
                nx, ny = x + dx[k], y + dy[k]
                if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] < 67:
                    new_d = d + grid[nx][ny]
                    heapq.heappush(heap, (new_d, nx, ny))
                    grid[nx][ny] = new_d
        
        res = grid[n-1][m-1] - 67
        return res < health
            