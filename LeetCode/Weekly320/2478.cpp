class Solution {
public:
    #define ll long long
    ll MOD = 1e9+7;
    ll dp[1000][1000]; // # used, end char
    ll sdp[1000]; // # used
    bool pr(char c){
        if(c == '2' || c == '3' || c == '5' || c == '7') return true;
        else return false;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        ll N = s.length();
        ll K = k;
        for(int i = 0; i < N; i++){
            int x = i - minLength;
            if(x >= 0 && x+1 < N){
                if(!pr(s[x]) && pr(s[x+1])){
                    for(int j = 0; j < K; j++){
                        sdp[j] = (sdp[j] + dp[j][x]) % MOD;
                    }
                }
            }
            if(pr(s[0]) && !pr(s[i]) && i+1 >= minLength) dp[0][i] = 1;
            if(!pr(s[i])){
                for(int j = 1; j < K; j++){
                    dp[j][i] = (dp[j][i] + sdp[j-1]) % MOD;
                }
            }
        }
        return dp[K-1][N-1];
    }
};