#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct DSU{
	int par[100000], sz[100000], N, comp;
	void init(int N){
		this->N = N;
		comp = N;
		fill(sz, sz+N, 1);
		iota(par, par+N, 0);
	}
	int find(int u){
		if(par[u] == u) return u;
		return (par[u] = find(par[u]));
	}
	void un(int u, int v){
		u = find(u), v = find(v);
		if(u == v) return;
		if(sz[u] > sz[v]) swap(u, v);
		par[u] = v;
		sz[v] += sz[u];
		comp--;
	}
};

int T, N, S[100000][3], I[100000];
DSU dsu;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		dsu.init(N);
		for(int i = 0; i < N; i++){
			eat >> S[i][0] >> S[i][1] >> S[i][2];
		}
		iota(I, I+N, 0);
		sort(I, I+N, [](int a, int b){
			return S[a][1] < S[b][1];
		});
		set<pair<int, int>> s[2];
		for(int id = 0; id < N; id++){
			int i = I[id];
			for(int j = 0; j < 2; j++){
				for(auto it = s[j].begin(); it != s[j].end();){
					if(it -> first < S[i][1]){
						it = s[j].erase(it);
					}else{
						break;
					}
				}
			}
			vector<pair<int, int>> rm;
			for(pair<int, int> j : s[!S[i][0]]){
				dsu.un(i, j.second);
				rm.push_back(j);
			}
			for(int j = 0; j < (int)rm.size() - 1; j++){
				s[!S[i][0]].erase(rm[j]);
			}
			s[S[i][0]].insert({S[i][2], i});
		}
		moo << dsu.comp << endl;
	}
}