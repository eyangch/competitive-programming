#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int T, N, L, R, fact[300000];

int inv(int b){
    int e = MOD-2, ans = 1;
    while(e > 0){
        if(e & 1) ans = b * ans % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return ans;
}

int nCr(int n, int k){
    if(k < 0 || n < k) return 0;
    return (fact[n] * inv(fact[k] * fact[n-k] % MOD) % MOD);
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    fact[0] = 1;
    for(int i = 1; i < 300000; i++){
        fact[i] = i * fact[i-1] % MOD;
    }
    eat >> T;
    while(T--){
        eat >> N >> L >> R;
        int n2 = N/2;
        int ans = min(R - N, 1 - L) * (nCr(N, n2) + (N%2 * nCr(N, n2+1))) % MOD;
        for(int i = min(R-N, 1-L)+1; true; i++){
            if(i+1 > R || N-i < L) break;
            int ub = min(R - i, N), lb = max(1LL, L + i);
            int range = ub - lb + 1;
            int used = N - ub;
            int rem1 = n2 - used, rem2 = n2+N%2-used;
            if(rem1 > range) break;
            if(rem2 < 0) break;
            ans += nCr(range, rem1);
            if(N%2) ans += nCr(range, rem2);
            while(ans >= MOD) ans -= MOD;
            //moo << i << " " << range << " " << used <<" " << rem1 << " "<< rem2 << endl;
            //moo.flush();
        }
        moo << ans << endl;
    }
}
