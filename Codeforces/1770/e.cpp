#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353, inv2 = 499122177;

struct mint{
	int v;
	mint(){v = 0;}
	mint(int m){
		v = (m % MOD + MOD) % MOD;
	}
	mint inv(){
		mint xv(v);
		mint res(1);
		for(int i = 0; i < 32; i++){
			if((MOD-2)>>i & 1) res = res * xv;
			xv = xv * xv;
		}
		return res;
	}
	friend mint operator+(const mint &a, const mint &b){
		return (a.v + b.v) % MOD;
	}
	friend mint operator-(const mint &a, const mint &b){
		return (a.v - b.v + MOD) % MOD;
	}
	friend mint operator*(const mint &a, const mint &b){
		return (a.v * b.v) % MOD;
	}
};

int N, K, A[300000], U[300000], V[300000];
vector<int> G[300000];
int par[300000];
mint P[300000], sts[300000];

void dfs(int v, int p){
	par[v] = p;
	sts[v] = P[v];
	for(int c : G[v]){
		if(c == p) continue;
		dfs(c, v);
		sts[v] = sts[v] + sts[c];
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	for(int i = 0; i < K; i++){
		eat >> A[i];
		A[i]--, P[A[i]] = 1;
	}
	for(int i = 0; i < N-1; i++){
		eat >> U[i] >> V[i];
		U[i]--, V[i]--;
		G[U[i]].push_back(V[i]);
		G[V[i]].push_back(U[i]);
	}
	dfs(0, 0);
	mint ans(0);
	for(int i = 0; i < N-1; i++){
		int u = U[i], v = V[i];
		if(par[u] == v) swap(u, v);
		mint pu = P[u], pv = P[v];
		P[u] = inv2 * (pv * (1 - pu) + pu + pu * pv);
		P[v] = inv2 * (pu * (1 - pv) + pv + pv * pu);
		mint up = inv2 * pv * (1 - pu);
		mint down = inv2 * pu * (1 - pv);
		mint none = pu * pv + inv2 * (1 - pv) + inv2 * (1 - pu);
		assert((up + down + none).v == 1);
		ans = ans + none * sts[v] * (K - sts[v]);
		ans = ans + up * (sts[v]-1) * (K - (sts[v]-1));
		ans = ans + down * (sts[v]+1) * (K - (sts[v]+1));
	}
	ans = ans * (mint(K) * (K-1) * inv2).inv();
	moo << ans.v << endl;
}