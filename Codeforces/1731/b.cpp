#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int T, N;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		int ans = N * (N+1) % MOD * (2 * N + 1) % MOD * 166666668 % MOD;
		N--;
		ans += N * (N+1) % MOD * (N+2) % MOD * 333333336 % MOD;
		ans %= MOD;
		moo << (2022 * ans % MOD) << endl;
	}
}