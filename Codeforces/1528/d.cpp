#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, D[600][600];
bool vis[600][600];
vector<pair<int, int>> G[600];
int mn[600];

void dij(int v){
	D[v][v] = 0;
	while(true){
		int cv = -1, cvd = 1e15;
		for(int i = 0; i < N; i++){
			if(vis[v][i]) continue;
			if(D[v][i] < cvd){
				cv = i;
				cvd = D[v][i];
			}
		}
		if(cv == -1){
			break;
		}
		vis[v][cv] = 1;
		int m = mn[cv];
		int t = G[cv][m].second;
		int off = D[v][cv] % N; 
		int z = G[cv][m].first + off;
		while(z >= N) z -= N;
		for(int i = 1; i <= (int)G[cv].size(); i++){
			int c = m + i;
			while(c >= G[cv].size()) c -= G[cv].size();
			int targ = G[cv][c].first + off;
			while(targ >= N) targ -= N;
			while(true){
				D[v][z] = min(D[v][z], D[v][cv] + t);
				t++;
				z++;
				if(z == N) z = 0;
				if(z == targ) break;
			}
			if(G[cv][c].second < t){
				t = G[cv][c].second;
			}
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	for(int i = 0; i < M; i++){
		int u, v, w; eat >> u >> v >> w;
		G[u].push_back({v, w});
	}
	for(int i = 0; i < N; i++){
		sort(G[i].begin(), G[i].end());
		int cm = 1e15;
		for(int j = 0; j < (int)G[i].size(); j++){
			if(G[i][j].second < cm){
				cm = G[i][j].second;
				mn[i] = j;
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			D[i][j] = 1e15;
		}
	}
	for(int i = 0; i < N; i++){
		dij(i);
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			moo << D[i][j] << ' ';
		}
		moo << endl;
	}
}