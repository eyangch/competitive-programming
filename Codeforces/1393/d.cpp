#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, dp[2000][2000], vert[2000][2000];
string s[2000];

bool ok(int x, int y, int d){
    int down = x+d-1, up = x-d+1;
    if(up < 0 || down >= N || s[x][y] != s[down][y] || s[x][y] != s[up][y]) return false;
    return true;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < N; i++) eat >> s[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i == 0 || s[i][j] != s[i-1][j]){
                vert[i][j] = 1;
                continue;
            }
            vert[i][j] = vert[i-1][j] - 1;
            if(ok(i, j, vert[i][j]+1)){
                vert[i][j]++;
                if(ok(i, j, vert[i][j]+1)){
                    vert[i][j]++;
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        dp[i][0] = 1;
        for(int j = 1; j < M; j++){
            if(s[i][j] != s[i][j-1]){
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = min(vert[i][j], dp[i][j-1]+1);
        }
    }
    for(int i = 0; i < N; i++){
        dp[i][M-1] = 1;
        for(int j = M-2; j >= 0; j--){
            if(s[i][j] != s[i][j+1]){
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = min(dp[i][j], min(vert[i][j], dp[i][j+1]+1));
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            ans += dp[i][j];
        }
    }
    moo << ans << endl;
}
