#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int MOD = 998244353;
int N, K, fact[5005], pfx[5000];
string S;

int inv(int x){
    int ans = 1;
    for(int i = 0; i < 35; i++){
        if((MOD-2) & (1LL<<i)) ans = ans * x % MOD;
        x = x * x % MOD;
    }
    return ans;
}

int os(int l, int r){
    if(l == 0) return pfx[r];
    return pfx[r] - pfx[l-1];
}

int zs(int l, int r){
    return r - l + 1 - os(l, r);
}

int w(int l, int r){
    int tf = fact[r-l+1];
    int of = fact[os(l, r)];
    int zf = fact[zs(l, r)];
    return tf * inv(of) % MOD * inv(zf) % MOD;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    fact[0] = 1;
    for(int i = 1; i < 5005; i++){
        fact[i] = fact[i-1] * i % MOD;
    }
    eat >> N >> K >> S;
    for(int i = 0; i < N; i++){
        pfx[i] = (S[i] - '0');
        if(i > 0) pfx[i] += pfx[i-1];
    }
    if(K > os(0, N-1) || K == 0){
        moo << 1 << endl;
        return 0;
    }
    int l = 0, r = 0, pvr = -1;
    while(r < N && os(l, r) <= K) r++;
    r--;
    int ans = 0;
    while(r < N){
        ans = (ans + w(l, r)) % MOD;
        if(pvr >= l){
            ans = ((ans - w(l, pvr)) % MOD + MOD) % MOD;
        }else if(pvr != -1){
            ans = ((ans - 1) % MOD + MOD) % MOD;
        }
        pvr = r;
        r++;
        if(r == N) break;
        while(os(l, r) > K) l++;
        while(r < N && os(l, r) == K) r++;
        r--;
        if(os(l, r) != K) break;
    }
    moo << ans << endl;
}
