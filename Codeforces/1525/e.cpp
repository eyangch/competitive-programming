#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int N, M, d[20][50000], v[21], f[21];

int bpow(int b, int e){
    b %= MOD;
    int ret = 1;
    for(int i = 0; i < 32; i++){
        if((e>>i)&1) ret = ret * b % MOD;
        b = b * b % MOD;
    }
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            eat >> d[i][j]; d[i][j]--;
        }
    }
    f[0] = 1;
    for(int i = 1; i < 21; i++) f[i] = f[i-1] * i;
    int ans = 0;
    for(int i = 0; i < M; i++){
        fill(v, v+N+1, 0);
        for(int j = 0; j < N; j++){
            v[d[j][i]]++;
        }
        int badbadsadsad = v[N];
        for(int j = N-1; j > 0; j--){
            v[j] += max(0LL, v[j+1]-1);
            badbadsadsad = badbadsadsad * v[j] % MOD;
        }
        int good = (f[N] - badbadsadsad) % MOD;
        ans = (ans + good * bpow(f[N], MOD-2) % MOD) % MOD;
    }
    moo << ans << endl;
}
