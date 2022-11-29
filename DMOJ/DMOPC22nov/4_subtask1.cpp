#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;
// COVER CASE WHERE ans is 0

struct DSU{
	int par[300000], sz[300000];
	void init(int N){
		fill(sz, sz+N, 1);
		iota(par, par+N, 0);
	}
	int find(int v){
		if(par[v] == v) return v;
		return (par[v] = find(par[v]));
	}
	void un(int u, int v){
		u = find(u), v = find(v);
		if(u == v) return;
		if(sz[u] < sz[v]) swap(u, v);
		par[v] = u;
		sz[u] += sz[v];
	}
};

int MOD = 1e9+7;
int f[300001], fi[300001];

int N, K, A[300000];
vector<int> G[300000];
pair<int, int> E[300000];
DSU dsu;
vector<int> bc, bcp;
pair<int, int> mem[3000][3000];

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

void dfs_bc(int v, int p, int C){
	if(v == -1) return;
	if(A[v] == C){
		bc.push_back(v);
		bcp.push_back(p);
		return;
	}
	for(int c : G[v]){
		if(c == p) continue;
		dfs_bc(c, v, C);
	}
}

pair<int, int> dfs(int v, int p){
	//moo << v << endl;
	if(mem[v][p].second != 0) return mem[v][p];
	int w = 1, n = 0;
	for(int c : G[v]){
		if(c == p) continue;
		pair<int, int> res = dfs(c, v);
		int wc = res.first;
		int nc = res.second;
		w = (w * wc) % MOD * nCr(n + nc, n) % MOD;
		n += nc;
	}
	n++;
	return (mem[v][p] = {w, n});
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	f[0] = 1;
	for(int i = 1; i <= N; i++){
		f[i] = f[i-1] * i % MOD;
	}
	for(int i = 0; i <= N; i++){
		fi[i] = inv(f[i]);
	}
	for(int i = 0; i < N; i++){
		eat >> A[i];
		A[i]--;
	}
	for(int i = 0; i < N-1; i++){
		int u, v; eat >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
		E[i] = {u, v};
	}
	for(int i = 0; i < K; i++){
		dsu.init(N);
		for(int j = 0; j < N-1; j++){
			int u = E[j].first, v = E[j].second;
			if(A[u] == i || A[v] == i) continue;
			dsu.un(u, v);
		}
		int mxv = 0;
		for(int j = 0; j < N; j++){
			if(A[j] != i && dsu.sz[j] > mxv){
				mxv = dsu.sz[j];
			}
		}
		int ans = 0;
		vector<int> mis;
		for(int j = 0; j < N; j++){
			if(A[j] != i && dsu.sz[j] == mxv){
				mis.push_back(j);
			}
		}
		for(int mxi : mis){
			bc.clear();
			bcp.clear();
			dfs_bc(mxi, -1, i);
			if(bc.size() == 0){
				continue;
			}
			int w = 1, n = 0;
			for(int j = 0; j < bc.size(); j++){
				//moo << "STARTING: " << endl;
				pair<int, int> res = dfs(bc[j], bcp[j]);
				int wc = res.first;
				int nc = res.second;
				w = (w * wc) % MOD * nCr(n + nc, n) % MOD;
				n += nc;
			}
			ans += w;
			//moo << w << endl;
		}
		moo << ans % MOD << endl;
	}
}