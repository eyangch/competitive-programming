#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct DSU{
	int par[200000], sz[200000];
	set<int> S[200000], E[200000];
	void init(int N){
		fill(sz, sz+N, 1);
		iota(par, par+N, 0);
		for(int i = 0; i < N; i++){
			S[i].insert(i);
		}
	}
	int find(int v){
		if(par[v] == v) return v;
		return (par[v] = find(par[v]));
	}
	void un(int u, int v){
		u = find(u), v = find(v);
		if(u == v) return;
		if(sz[u] > sz[v]) swap(u, v);
		sz[v] += sz[u];
		par[u] = v;
		for(int j : S[u]){
			S[v].insert(j);
		}
		for(int j : E[u]){
			E[v].insert(j);
		}
		for(int j : E[u]){
			if(S[v].count(j)) E[v].erase(j);
		}
		for(int j : S[u]){
			if(E[v].count(j)) E[v].erase(j);
		}
	}
} dsu;

int N, M;
vector<int> G[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	dsu.init(N);
	for(int i = 0; i < M; i++){
		int u, v; eat >> u >> v;
		u--, v--;
		if(u < v) swap(u, v);
		G[u].push_back(v);
		dsu.E[u].insert(v);
		dsu.E[v].insert(u);
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		for(int j : G[i]){
			dsu.un(i, j);
		}
		ans += dsu.E[dsu.find(i)].size();
	}
	moo << ans - M << endl;
}