#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, X, A[300000];
vector<pair<int, int>> G[300000];

struct DSU{
	int par[300000], sz[300000];
	multiset<pair<int, int>> S;
	void init(int N){
		fill(sz, sz+N, 1);
		iota(par, par+N, 0);
		for(int i = 0; i < N; i++){
			S.insert({A[i], i});
		}
	}
	int find(int u){
		if(par[u] == u) return u;
		return (par[u] = find(par[u]));
	}
	int mx(){
		return S.rbegin()->second;
	}
	void un(int u, int v){
		u = find(u), v = find(v);
		if(u == v) return;
		if(sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		S.erase(S.find({A[u], u}));
		S.erase(S.find({A[v], v}));
		A[u] += A[v] - X;
		assert(A[u] >= 0);
		S.insert({A[u], u});
		par[v] = u;
		for(auto i : G[v]){
			G[u].push_back(i);
		}
	}
} dsu;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M >> X;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	if(accumulate(A, A+N, 0LL) < X * (N-1)){
		moo << "NO" << endl;
		return 0;
	}
	for(int i = 0; i < M; i++){
		int u, v; eat >> u >> v;
		u--, v--;
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	dsu.init(N);
	moo << "YES" << endl;
	for(int i = 0; i < N-1; i++){
		int j = dsu.mx();
		while(dsu.find(j) == dsu.find(G[j].back().first)){
			//moo << "SKIP: " << G[j].back().first << endl;
			//moo << "P1: " << dsu.find(j) << ' ' << dsu.find(G[j].back().first) << endl;
			G[j].pop_back();
		}
		//moo << "J: " << j << endl;
		//moo << G[j].size() << endl;
		//moo << "DEST: " << G[j].back().first << endl;
		moo << G[j].back().second + 1 << endl;
		//for(auto [k, _] : G[j]) moo << k << ' ';
		//moo << endl << endl;
		int v = G[j].back().first;
		G[j].pop_back();
		dsu.un(j, v);
	}
}