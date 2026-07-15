class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        # map emails to their name
        email_to_name = {}
        for account in accounts:
            for email in account[1:]:
                # name is in account[0], emails in account[1:]
                email_to_name[email] = account[0]

        emails = list(email_to_name.keys())  # keys contains the emails themselves
        n = len(emails)  # number of distinct emails

        # reverse map from email -> index
        email_to_idx = {email: index for index, email in enumerate(emails)}

        # build adjacency list with accounts
        adj = [[] for _ in range(n)]

        # <3 <3 <3 build the adjacency list here
        for account in accounts:
            for i in range(2, len(account)):
                # combine i-th email and (i-1)-th email
                # start iterating from 2 b/c the 0th entry is a name
                index1 = email_to_idx[account[i-1]]
                index2 = email_to_idx[account[i]]

                adj[index1].append(index2)
                adj[index2].append(index1)

        ans = []

        # initially, everything is not visited
        visited = [False for _ in range(n)]

        def dfs(v, vis, res):
            vis[v] = True
            res.append(emails[v])
            for c in adj[v]:
                if vis[c]:
                    continue
                # visit all children if it hasn't been visited
                dfs(c, vis, res)

        for i in range(n):
            if visited[i]:
                # don't reprocess something already processed
                continue
            res = []
            dfs(i, visited, res)

            # sort emails
            res.sort()

            # append the name of arbitrary email in the list to the front
            res = [email_to_name[res[0]]] + res
            ans.append(res)

        return ans
