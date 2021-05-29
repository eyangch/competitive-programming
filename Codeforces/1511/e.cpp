#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int MOD = 998244353;
int N, M, w, p2[300001], len[300005];
string b[300000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < N; i++){
        eat >> b[i];
        for(int j = 0; j < M; j++){
            w += (b[i][j] == 'o');
        }
    }
    if(w < 2){
        moo << 0 << endl;
        return 0;
    }
    p2[0] = 1;
    for(int i = 1; i <= 300000; i++){
        p2[i] = p2[i-1] * 2 % MOD;
    }
    len[2] = p2[w-2];
    len[3] = p2[w-3];
    for(int i = 4; i <= w; i++){
        len[i] = (len[i/2*2-1] + p2[w-i]) % MOD;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        int cur = 0;
        for(int j = 0; j < M; j++){
            if(b[i][j] != 'o'){
                cur = 0;
                continue;
            }
            cur++;
            ans = (ans + len[cur]) % MOD;
        }
    }
    for(int i = 0; i < M; i++){
        int cur = 0;
        for(int j = 0; j < N; j++){
            if(b[j][i] != 'o'){
                cur = 0;
                continue;
            }
            cur++;
            ans = (ans + len[cur]) % MOD;
        }
    }
    moo << ans << endl;
}
