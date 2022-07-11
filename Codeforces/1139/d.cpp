#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int M, X[100001], I[100001];
vector<int> F[100001], P[100001];
int op[100001];

int inv(int x){
	int e = MOD-2;
	int ans = 1;
	while(e){
		if(e & 1){
			ans = ans * x % MOD;
		}
		e >>= 1;
		x = x * x % MOD;
	}
	return ans;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> M;
	for(int i = 1; i <= M; i++){
		for(int j = i; j <= M; j += i){
			F[j].push_back(i);
		}
		if((int)F[i].size() == 2){
			for(int j = i; j <= M; j += i){
				P[j].push_back(i);
			}
		}
	}
	for(int i = 1; i <= M; i++){
		I[i] = inv(i);
	}
	X[1] = 1;
	for(int i = 2; i <= M; i++){
		for(int j : F[i]) op[j] = 0;
		for(int j : F[i]){
			int a = i/j;
			int mx = M/j;
			int sz = P[a].size();
			int sum = 0;
			for(int k = 1; k < (1<<sz); k++){
				int cur = 1;
				for(int l = 0; l < sz; l++){
					if((k>>l) & 1){
						cur *= P[a][l];
					}
				}
				sum += mx/cur * ((__builtin_popcount(k) & 1) ? 1 : -1);
			}
			op[j] = mx - sum;
			/*op[j] = (op[j] + M/j) % MOD;
			for(int k : F[j]){
				int dv = j/k;
				if(dv == 1 || (int)F[dv].size() > 2) continue;
				op[k] = (op[k] - M/j) % MOD;
				moo << i << ' ' << j << ' ' << k << endl;
			}*/
		}
		/*moo << i << ' ';
		for(int j : F[i]){
			moo << j << '/' << op[j] << '|';
		}moo << endl;*/
		X[i] = M;
		for(int j : F[i]){
			if(i == j) break;
			X[i] = (X[i] + op[j] * X[j]) % MOD;
		}
		X[i] = X[i] * I[M-op[i]] % MOD;
	}
	int ans = 0;
	for(int i = 0; i <= M; i++){
		ans = (ans + X[i]) % MOD;
		//moo << i << ' ' << X[i] << endl;
	}
	ans = (ans * I[M]) % MOD;
	moo << ans << endl;
}