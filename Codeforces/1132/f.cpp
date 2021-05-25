#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N, dp[500][500];
string s;

int dpf(int l, int r){
    if(l == r) return 1;
    if(l > r) return 0;
    if(dp[l][r] > 0) return dp[l][r];
    int ans = dpf(l, r-1) + 1;
    for(int i = l; i < r; i++){
        if(s[i] == s[r]) ans = min(dpf(l, i) + dpf(i+1, r-1), ans);
    }
    return (dp[l][r] = ans);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> s;
    moo << dpf(0, N-1) << endl;
}
