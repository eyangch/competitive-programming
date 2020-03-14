#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    if(N % 2 == 0){
        cout << 0 << endl;
        return 0;
    }
    int dp[K+1][N+1];
    fill(dp[0], dp[K] + N + 1, 0);
    dp[1][1] = 1;
    for(int i = 2; i <= K; i++){
        int upto;
        if(i > 10){
            upto = N;
        }else{
            upto = min(N, (int)pow(2, i) - 1);
        }
        for(int j = (i * 2) - 1; j <= upto; j += 2){
            for(int k = 1; k <= j - 1 - k; k += 2){
                int add1 = 0;
                int mp1 = 0;
                    add1 += dp[i-1][k];
                    for(int l = 1; l < i - 1; l++){
                        mp1 += dp[l][k];
                    }
                int add2 = 0;
                int mp2 = 0;
                    add2 += dp[i-1][j-k-1];
                    for(int l = 1; l < i - 1; l++){
                        mp2 += dp[l][j-k-1];
                    }
                mp1 %= 9901;
                mp2 %= 9901;
                int fadd = 2 * (add1 * add2 + add1 * mp2 + add2 * mp1);
                if(k == j - 1 - k){
                    fadd /= 2;
                }
                dp[i][j] += fadd;
                dp[i][j] %= 9901;
            }
        }
    }
    cout << dp[K][N] << endl;
    return 0;
}

