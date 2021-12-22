#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int MOD = 998244353;
int16_t N, oc[23][26], g[1<<23][26];
int f[1<<23];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        string s; eat >> s;
        for(char c : s) oc[i][c-'a']++;
    }
    fill(g[0], g[0]+26, 1e15);
    for(int i = 1; i < 1<<N; i++){
        int l = 31 - __builtin_clz(i);
        f[i] = 1;
        for(int j = 0; j < 26; j++){
            g[i][j] = min(g[i^(1<<l)][j], oc[l][j]);
            f[i] = f[i] * (g[i][j]+1) % MOD;
        }
        f[i] = (__builtin_popcount(i) % 2 ? 1 : MOD-1) * f[i] % MOD;
    }
    for(int i = 0; i < N; i++){
        for(int j = 1; j < 1<<N; j++){
            if(!(j & (1<<i))) continue;
            f[j] = (f[j] + f[j^(1<<i)]) % MOD;
        }
    }
    int ans = 0;
    for(int i = 1; i < 1<<N; i++){
        int m = 0;
        for(int j = 0; j < N; j++){
            if(i & (1<<j)) m += j+1;
        }
        ans ^= f[i] * __builtin_popcount(i) * m;
    }
    moo << ans << endl;
}
