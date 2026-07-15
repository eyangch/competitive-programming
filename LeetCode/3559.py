class Solution:
    def assignEdgeWeights(self, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        n = len(edges) + 1
        adj = [[] for _ in range(n)]
        for e in edges:
            adj[e[0]-1].append(e[1]-1)
            adj[e[1]-1].append(e[0]-1)
        
        dep = [0] * n
        stack = [(0, 0)]
        up = [[0] * n for _ in range(18)]
        while stack:
            node, par = stack.pop()
            up[0][node] = par
            for c in adj[node]:
                if c == par:
                    continue
                dep[c] = dep[node] + 1
                stack.append((c, node))
        
        for i in range(1, 18):
            for j in range(n):
                up[i][j] = up[i-1][up[i-1][j]]
        
        def lift(u, x):
            for i in range(18):
                if (x & (1 << i)) != 0:
                    u = up[i][u]
            return u

        def lca(u, v):
            if dep[u] > dep[v]:
                u, v = v, u
            v = lift(v, dep[v] - dep[u])
            if u == v:
                return v
            for i in range(17, -1, -1):
                if up[i][u] != up[i][v]:
                    u, v = up[i][u], up[i][v]
            return up[0][v]

        res = []
        for u, v in queries:
            res_dep = dep[u-1] + dep[v-1] - 2 * dep[lca(u-1, v-1)] - 1
            if res_dep < 0:
                res.append(0)
            else:
                res.append(pow(2, res_dep, 1000000007))

        return res
        