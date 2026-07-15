class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        vis = [False] * n
        n_edges = 0
        n_nodes = 0

        ans = 0
        for i in range(n):
            if vis[i]:
                continue
            stack = [i]
            vis[i] = True
            while stack:
                u = stack.pop()
                n_nodes += 1
                n_edges += len(adj[u])
                for v in adj[u]:
                    if vis[v]:
                        continue
                    vis[v] = True
                    stack.append(v)
            
            if n_edges == n_nodes * (n_nodes - 1):
                ans += 1
            
            n_edges = 0
            n_nodes = 0
        
        return ans