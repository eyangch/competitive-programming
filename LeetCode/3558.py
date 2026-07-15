class Solution:
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        adj = [[] for _ in range(n)]
        for e in edges:
            adj[e[0]-1].append(e[1]-1)
            adj[e[1]-1].append(e[0]-1)
        
        mx_dep = 0
        stack = [(0, 0, 0)]

        while stack:
            node, par, dep = stack.pop()
            mx_dep = max(mx_dep, dep)
            for c in adj[node]:
                if c == par:
                    continue
                stack.append((c, node, dep+1))
        
        return pow(2, mx_dep-1, 1000000007)