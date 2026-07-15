class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        for a, b, d in roads:
            adj[a-1].append((b-1, d))
            adj[b-1].append((a-1, d))

        vis = [False] * n
        vis[0] = True
        stack = [0]
        min_edge = 1e67
        while stack:
            v = stack.pop()
            for u, d in adj[v]:
                min_edge = min(min_edge, d)
                if vis[u]:
                    continue
                vis[u] = True
                stack.append(u)
        
        return min_edge