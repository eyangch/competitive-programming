#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct DSU{
	int par[200000], sz[200000];
	vector<int> P[200000];
	pair<int, int> A[200000];
	int f[200000];
	void init(int N, int Q, pair<int, int> (&X)[200000]){
		iota(par, par+N, 0);
		fill(sz, sz+N, 1);
		for(int i = 0; i < Q; i++){
			int u = X[i].first, v = X[i].second;
			P[u].push_back(i);
			P[v].push_back(i);
			A[i] = {u, v};
			if(u == v){
				f[i] = 0;
			}else{
				f[i] = -1;
			}
		}
	}
	int find(int u){
		if(par[u] == u) return u;
		return (par[u] = find(par[u]));
	}
	void un(int u, int v, int x){
		u = find(u), v = find(v);
		if(u == v) return;
		if(sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		par[v] = u;
		for(int i : P[v]){
			if(~f[i]) continue;
			P[u].push_back(i);
			if(A[i].first == v){
				A[i].first = u;
			}else{
				A[i].second = u;
			}
			if(A[i].first == A[i].second){
				f[i] = x;
			}
		}
	}
};

int N, M, Q;
pair<int, int> E[200000];
pair<int, int> X[200000];
DSU dsu;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M >> Q;
	for(int i = 0; i < M; i++){
		eat >> E[i].first >> E[i].second;
		E[i].first--, E[i].second--;
	}
	for(int i = 0; i < Q; i++){
		eat >> X[i].first >> X[i].second;
		X[i].first--, X[i].second--;
	}
	dsu.init(N, Q, X);
	for(int i = 0; i < M; i++){
		dsu.un(E[i].first, E[i].second, i+1);
	}
	for(int i = 0; i < Q; i++){
		moo << dsu.f[i] << endl;
	}
}