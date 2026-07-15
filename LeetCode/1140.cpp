class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int N = piles.size();
        int dp[105][205][2];
        int pfx[105];
        pfx[0] = 0;
        for(int i = 1; i <= N; i++){
            pfx[i] = pfx[i-1] + piles[i-1];
        }
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= 2*N; j++){
                dp[i][j][0] = -1e9;
                dp[i][j][1] = 1e9;
            }
        }
        for(int i = 0; i <= 2*N; i++){
            dp[N][i][0] = dp[N][i][1] = 0;
        }
        for(int i = N; i > 0; i--){
            for(int M = 1; M <= N; M++){
                for(int X = 1; X < M; X++){
                    int j = i-X;
                    if(j < 0) break;
                    dp[j][M][0] = max(dp[j][M][0], dp[i][M][1] + pfx[i] - pfx[j]);
                    dp[j][M][1] = min(dp[j][M][1], dp[i][M][0]);
                }
                // X = M
                for(int M2 = (M+1)/2; M2 <= M; M2++){
                    int j = i-M;
                    if(j < 0) break;
                    dp[j][M2][0] = max(dp[j][M2][0], dp[i][M][1] + pfx[i] - pfx[j]);
                    dp[j][M2][1] = min(dp[j][M2][1], dp[i][M][0]);
                    
                }
            }
        }
        return dp[0][1][0];
    }
};