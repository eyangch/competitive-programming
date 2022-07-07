#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct DSU{
	int par[100000], sz[100000];
	void init(int N){
		iota(par, par+N, 0);
		fill(sz, sz+N, 1);
	}
	int find(int u){
		if(par[u] == u) return u;
		return (par[u] = find(par[u]));
	}
	void un(int u, int v){
		u = find(u), v = find(v);
		if(u == v) return;
		if(sz[u] < sz[v]){
			swap(u, v);
		}
		par[v] = u;
		sz[u] += sz[v];
	}
};

int N, M, U[100000], V[100000], W[100000], C[100000], ans[100000];
vector<int> I[1000001];
vector<pair<int, int>> graph[100000];
bool vis[100000];
int in[100000], lo_in[100000], gt;
DSU dsu;

void dfs(int v, int p){
	vis[v] = 1;
	in[v] = lo_in[v] = gt++;
	for(pair<int, int> i : graph[v]){
		int c = i.first, id = i.second;
		if(id == p) continue;
		if(vis[c]){
			lo_in[v] = min(lo_in[v], in[c]);
			if(lo_in[c] > in[v]){
				ans[id] = 2;
			}
			continue;
		}
		dfs(c, id);
		lo_in[v] = min(lo_in[v], lo_in[c]);
		if(lo_in[c] > in[v]){
			ans[id] = 2;
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	for(int i = 0; i < M; i++){
		eat >> U[i] >> V[i] >> W[i];
		U[i]--, V[i]--;
		I[W[i]].push_back(i);
	}
	dsu.init(N);
	for(int i = 0; i <= 1000000; i++){
		if(!I[i].size()) continue;
		for(int j : I[i]){
			int u = dsu.find(U[j]), v = dsu.find(V[j]);
			if(u != v){
				graph[u].push_back({v, j});
				graph[v].push_back({u, j});
				ans[j] = 1;
			}
		}
		gt = 0;
		for(int j : I[i]){
			int u = dsu.find(U[j]), v = dsu.find(V[j]);
			if(vis[u] || vis[v]) continue;
			dfs(u, -1);
			dfs(v, -1);
		}
		for(int j : I[i]){
			int u = dsu.find(U[j]), v = dsu.find(V[j]);
			graph[u].clear(), graph[v].clear();
			vis[u] = 0, vis[v] = 0;
		}
		for(int j : I[i]){
			dsu.un(U[j], V[j]);
		}
	}
	for(int i = 0; i < M; i++){
		if(ans[i] == 0) moo << "none";
		if(ans[i] == 1) moo << "at least one";
		if(ans[i] == 2) moo << "any";
		moo << endl;
	}
}