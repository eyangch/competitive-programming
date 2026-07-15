class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)
        adj = [[] for _ in range(n)]
        mx_cost = 0
        for u, v, cost in edges:
            adj[u].append((v, cost))
            mx_cost = max(mx_cost, cost)
        def dfs(z, v, vis):
            heap = [(0, 0)]
            vis[0] = 0
            while heap:
                d, v = heapq.heappop(heap)
                if d != vis[v]:
                    continue
                if not online[v]:
                    continue
                if v == n-1:
                    return True
                for u, c in adj[v]:
                    if d + c > k or d + c > vis[u] or c < z:
                        continue
                    vis[u] = d + c
                    heapq.heappush(heap, (d + c, u))
            return False

        if not dfs(-67, 0, [1e67] * n):
            return -1

        lo = 0
        hi = mx_cost
        mid = 0
        ans = 0
        while lo <= hi:
            mid = (lo + hi) // 2
            if dfs(mid, 0, [1e67] * n):
                ans = max(0, mid)
                lo = mid+1
            else:
                hi = mid-1
        return ans
