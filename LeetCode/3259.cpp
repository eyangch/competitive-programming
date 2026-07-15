class Solution {
public:
    long long maxEnergyBoost(vector<int>& A, vector<int>& B) {
        long long dp[100000][2];
        int N = A.size();
        for(int i = 0; i < N; i++){
            dp[i][0] = dp[i][1] = 0;
        }
        dp[0][0] = A[0];
        dp[0][1] = B[0];
        for(int i = 1; i < N; i++){
            if(i > 1){
                dp[i][0] = max(dp[i][0], dp[i-2][1]);
                dp[i][1] = max(dp[i][1], dp[i-2][0]);
            }
            dp[i][0] = max(dp[i][0], dp[i-1][0]);
            dp[i][1] = max(dp[i][1], dp[i-1][1]);
            dp[i][0] += A[i];
            dp[i][1] += B[i];
        }
        return max(dp[N-1][0], dp[N-1][1]);
    }
};