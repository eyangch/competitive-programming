#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int f[300005], fi[300005], p2[300005], aux[300005];
int T, N;

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

int A[300000], B[300000];
bool isap(){
	for(int i = 0; i < N; i++){
		B[A[i]] = i;
	}
	bool flag = 0;
	for(int i = 0; i < N; i++){
		if(abs(A[i] - B[i]) > 1) return 0;
		if(abs(A[i] - B[i]) == 1){
			flag = 1;
		}
	}
	if(flag){
		for(int i = 0; i < N; i++){
			moo << A[i] << ' ';
		}
		moo << endl;
		for(int i = 0; i < N; i++){
			moo << B[i] << ' ';
		}
		moo << endl;
		moo << endl;
		return 1;
	}
	return 0;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	f[0] = 1;
	for(int i = 1; i < 300005; i++){
		f[i] = f[i-1] * i % MOD;
	}
	for(int i = 0; i < 300005; i++){
		fi[i] = inv(f[i]);
	}
	p2[0] = 1;
	for(int i = 1; i < 300005; i++){
		p2[i] = p2[i-1] * 2 % MOD;
	}
	aux[0] = 1;
	aux[1] = 1;
	aux[2] = 2;
	for(int i = 3; i < 300005; i++){
		aux[i] = (aux[i-1] + (i-1) * aux[i-2] % MOD) % MOD;
	}
	eat >> T;
	while(T--){
		eat >> N;
		int ans = 0;
		for(int i = 0; i <= N; i+=4){
			int x1 = nCr(i/2+N-i, i/2);
			int nt = i/2;
			int x2 = f[nt] * inv(f[nt/2] % MOD) % MOD;
			ans = (ans + x1 * x2 % MOD * aux[N-i] % MOD) % MOD;
		}
		moo << ans << endl;
	}
}