class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int l = 0; l < k; l++){
                    int nl = (l + grid[i][j]) % k;
                    if(i) dp[i][j][nl] += dp[i-1][j][l];
                    if(j) dp[i][j][nl] += dp[i][j-1][l];
                    dp[i][j][nl] %= 1000000007;
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};