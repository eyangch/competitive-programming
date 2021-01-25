#include <bits/stdc++.h>
#define int long long

using namespace std;

int MOD = 1e9+7;

int T;
int N, K;
int a[1000];
int dp1[1001][1001], dp2[1001][1001];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N >> K;
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        for(int i = 0; i <= N; i++) for(int j = 0; j <= N; j++) dp1[i][j] = dp2[i][j] = -1e9;
        dp1[0][0] = 0;
        dp2[0][0] = 1;
        for(int i = 1; i <= N; i++){
            dp1[i][0] = 0;
            dp2[i][0] = 1;
            for(int j = 1; j <= K; j++){
                dp1[i][j] = dp1[i-1][j];
                dp2[i][j] = dp2[i-1][j];
                int cur = dp1[i-1][j-1] + a[i-1];
                if(cur > dp1[i][j]){
                    dp1[i][j] = cur;
                    dp2[i][j] = dp2[i-1][j-1];
                }else if(cur == dp1[i][j]){
                    dp2[i][j] = (dp2[i][j] + dp2[i-1][j-1]) % MOD;
                }
            }
        }
        cout << dp2[N][K] << endl;
    }
}
