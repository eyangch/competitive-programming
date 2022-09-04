#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct DSU{
	int par[1000], sz[1000];
	void init(int N){
		fill(sz, sz+N, 1);
		iota(par, par+N, 0);
	}
	int find(int u){
		if(u == par[u]) return u;
		return (par[u] = find(par[u]));
	}
	void un(int u, int v){
		u = find(u), v = find(v);
		if(u == v) return;
		if(sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		par[v] = par[u];
	}
};

int T, N, A[1000][1000], V[1000];
vector<int> G[1000];
DSU dsu;

void parity(int v, int p){
	V[v] = !V[v];
	for(int c : G[v]){
		if(c == p) continue;
		parity(c, v);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				eat >> A[i][j];
			}
		}
		dsu.init(N);
		fill(V, V+N, -1);
		for(int i = 0; i < N; i++){
			G[i].clear();
		}
		for(int i = 0; i < N; i++){
			for(int j = i+1; j < N; j++){
				if(A[i][j] == A[j][i]) continue;
				if(dsu.find(i) == dsu.find(j)) continue;
				int u = i, v = j;
				int edge = (A[i][j] > A[j][i]);
				if(V[u] != -1 && V[v] != -1){
					if(dsu.sz[u] < dsu.sz[v]) swap(u, v);
					if(V[u] ^ edge != V[v]){
						parity(v, -1);
					}
				}else if(V[u] == -1 && V[v] == -1){
					V[u] = 0;
					V[v] = edge;
				}else{
					if(V[v] == -1) swap(u, v);
					V[u] = V[v] ^ edge;
				}
				dsu.un(u, v);
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		for(int i = 0; i < N; i++){
			if(V[i]){
				for(int j = 0; j < N; j++){
					swap(A[i][j], A[j][i]);
				}
			}
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				moo << A[i][j] << ' ';
			}
			moo << endl;
		}
	}
}