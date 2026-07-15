class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ptf(n, vector<int>(m));
        for(int i = 0; i < m; i++)
            ptf[n-1][i] = 1;
        for(int i = 0; i < n; i++)
            ptf[i][m-1] = 1;
        for(int i = n - 2; i >= 0; i--)
            for(int j = m - 2; j >= 0; j--)
                ptf[i][j] = ptf[i + 1][j] + ptf[i][j + 1];
        return ptf[0][0];
    }
};