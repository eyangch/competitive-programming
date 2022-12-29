#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int N, K;
int f[100001], fi[100001];

int bp(int n, int e){
    int a = 1;
    for(int i = 0; i < 32; i++){
        if(e>>i & 1) a = a * n % MOD;
        n = n * n % MOD;
    }
    return a;
}

int inv(int n){
    return bp(n, MOD-2);
}

int nCr(int n, int r){
    if(n < r) return 0;
    return f[n] * fi[r] % MOD * fi[n-r] % MOD;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	f[0] = fi[0] = 1;
	for(int i = 1; i <= 100000; i++){
		f[i] = f[i-1] * i % MOD;
		fi[i] = inv(f[i]);
	}
	eat >> N >> K;
	K = min(K, N);
	int ans = 0;
	for(int i = 0; i <= K; i++){
		ans = (ans + nCr(N, i)) % MOD;
	}
	moo << ans << endl;
}