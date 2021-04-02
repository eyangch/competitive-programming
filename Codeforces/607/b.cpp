#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N, c[500], dp[500][500];

int dpf(int l, int r){
    if(l > r) return 1;
    if(dp[l][r]) return dp[l][r];
    int ans = 1e9;
    if(c[l] == c[r]) ans = min(ans, dpf(l+1, r-1));
    for(int i = l; i < r; i++){
        ans = min(ans, dpf(l, i) + dpf(i+1, r));
    }
    return (dp[l][r] = ans);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++) eat >> c[i];
    moo << dpf(0, N-1) << endl;
}
