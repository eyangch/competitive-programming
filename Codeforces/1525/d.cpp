#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N, a[5000], dp[5000][5000];
vector<int> c;

int dpf(int x, int y){
    if(x < 0) return 0;
    if(y < 0) return 1e9-1;
    if(dp[x][y] < 1e9) return dp[x][y];
    dp[x][y] = dpf(x, y-1);
    if(!a[y]){
        dp[x][y] = min(dp[x][y], dpf(x-1, y-1) + abs(c[x] - y));
    }
    return dp[x][y];
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> a[i];
        if(a[i]) c.push_back(i);
    }
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) dp[i][j] = 1e9;
    moo << dpf(c.size()-1, N-1) << endl;
}
