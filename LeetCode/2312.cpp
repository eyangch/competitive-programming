typedef long long ll;

class Solution {
public:
    long long dfs(int h, int w, vector<vector<ll>>& p, vector<vector<ll>>& dp) {
        if (dp[h][w] != -1) return dp[h][w];
        ll res = p[h][w];

        // split horizontal
        for (int i = 1; i < h; i++) {
            res = max(res, dfs(i, w, p, dp) + dfs(h-i, w, p, dp));
        }

        // split vertical
        for (int i = 1; i < w; i++) {
            res = max(res, dfs(h, i, p, dp) + dfs(h, w-i, p, dp));
        }

        dp[h][w] = res;
        return res;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<ll>> p(m+1, vector<ll>(n+1, 0));
        vector<vector<ll>> dp(m+1, vector<ll>(n+1, -1));

        for (vector<int> &v : prices) {
            p[v[0]][v[1]] = v[2];
        }

        return dfs(m, n, p, dp);
    }
};