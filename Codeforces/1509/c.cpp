#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, s[2000], dp[2000][2000];

int dpf(int l, int r){
    if(l > r) return 0;
    if(dp[l][r] != 1e17) return dp[l][r];
    return (dp[l][r] = s[r] - s[l] + min(dpf(l+1, r), dpf(l, r-1)));
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++) eat >> s[i];
    sort(s, s+N);
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) dp[i][j] = 1e17;
    moo << dpf(0, N-1) << endl;
}
