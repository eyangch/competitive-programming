#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, M, dp[1000000][8], x[1000000];
string s[3];

bool ok(int a, int b){
    if(N == 3){
        if(((a>>2&1) + (a>>1&1) + (b>>2&1) + (b>>1&1)) % 2 == 0){
            return false;
        }
    }
    if(((a>>1&1) + (a&1) + (b>>1&1) + (b&1)) % 2 == 0){
        return false;
    }
    return true;
}

int dpf(int id, int m){
    if(id < 0) return 0;
    if(~dp[id][m]) return dp[id][m];
    dp[id][m] = 1e9;
    for(int i = 0; i < (1<<N); i++){
        if(ok(m, i)){
            dp[id][m] = min(dp[id][m], dpf(id-1, i));
        }
    }
    dp[id][m] += __builtin_popcount(m ^ x[id]);
    return dp[id][m];
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> M;
    if(N > 3){
        cout << -1 << endl;
        return 0;
    }
    if(N == 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }
    for(int i = 0; i < M; i++){
        x[i] = s[0][i] - '0' + 2 * (s[1][i] - '0');
        if(N == 3){
            x[i] += 4 * (s[2][i] - '0');
        }
    }
    fill_n(&dp[0][0], 8000000, -1);
    int ans = 1e9;
    for(int i = 0; i < (1<<N); i++){
        ans = min(ans, dpf(M-1, i));
    }
    cout << ans << endl;
}
