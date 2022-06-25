#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int fact[500000];
int N, a[200001];

int fexp(int a, int b){
    int ans = 1;
    for(int i = 0; i < 35; i++){
        if(b&(1LL<<i)){
            ans *= a;
        }
        a *= a;
        a %= MOD;
        ans %= MOD;
    }
    return ans;
}

int nCr(int n, int k){
	if(n <= 0) return 0;
	if(n < k) return 1;
    return fact[n] * fexp(fact[k] * fact[n-k] % MOD, MOD-2) % MOD;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	fact[0] = 1;
	for(int i = 1; i < 500000; i++){
		fact[i] = fact[i-1] * i % MOD;
	}
	eat >> N;
	for(int i = 0; i < N+1; i++){
		eat >> a[i];
	}
	int ans = 0;
	for(int i = 0; i <= N; i++){
		if(a[i] == 0) break;
		int cx = i, cy = a[i]-1;
		ans = (ans + nCr(cx + cy + 1, i+1)) % MOD;
	}
	moo << ans << endl;
}