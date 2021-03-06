#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, a[300], dp[300][300];

int dpf(int s, int e){
    if(s > e) return 0;
    if(s == e) return 1;
    if(dp[s][e] < 1e9) return dp[s][e];
    dp[s][e] = dpf(s, e-1) + 1;
    for(int i = s; i < e; i++){
        if(a[i] == a[e]){
            dp[s][e] = min(dp[s][e], dpf(s, i) + dpf(i+1, e-1));
        }
    }
    return dp[s][e];
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = 1e9;
        }
    }
    cout << dpf(0, N-1) << endl;
}
