#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int N, x[200000], y[200000], s[200000], BIT[800000];

int qry(int x){
    int sum = 0;
    for(; x > 0; x -= x&-x) sum = (sum + BIT[x]) % MOD;
    return sum;
}

void upd(int x, int dv){
    for(; x <= N; x += x&-x) BIT[x] = (BIT[x] + dv) % MOD;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> x[i] >> y[i] >> s[i];
    }
    int ans = x[N-1] + 1;
    for(int i = 0; i < N; i++){
        int np = upper_bound(x, x+N, y[i]) - x;
        int xtra = ((qry(N) - qry(np)) % MOD + MOD) % MOD;
        int cur = x[i] - y[i] + xtra;
        if(s[i]) ans = (ans + cur) % MOD;
        upd(i+1, cur);
    }
    moo << (ans % MOD + MOD) % MOD << endl;
}
