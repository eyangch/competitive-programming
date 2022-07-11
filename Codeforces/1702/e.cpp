#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, C[200000];
pair<int, int> X[200000];
vector<int> graph[200000], nb[200000];
bool good = 1;

void dfs(int v, int cl){
	if(C[v] == cl){
		return;
	}
	if(C[v] == -1) C[v] = cl;
	if(C[v] != cl){
		good = 0;
		return;
	}
	for(int c : graph[v]){
		dfs(c, !cl);
		if(!good) return;
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		good = 1;
		for(int i = 0; i < N; i++){
			graph[i].clear();
			nb[i].clear();
		}
		for(int i = 0; i < N; i++){
			int a, b; eat >> a >> b;
			a--, b--;
			X[i].first = a, X[i].second = b;
			nb[a].push_back(i);
			nb[b].push_back(i);
		}
		bool fd = 0;
		for(int i = 0; i < N; i++){
			if((int)nb[i].size() != 2){
				fd = 1;
				break;
			}
		}
		if(fd){
			moo << "NO" << endl;
			continue;
		}
		for(int i = 0; i < N; i++){
			int a = X[i].first, b = X[i].second;
			if(nb[a][0] == i) swap(nb[a][0], nb[a][1]);
			if(nb[b][0] == i) swap(nb[b][0], nb[b][1]);
			graph[i].push_back(nb[a][0]);
			graph[i].push_back(nb[b][0]);
		}
		fill(C, C+N, -1);
		for(int i = 0; i < N; i++){
			if(!good) break;
			if(C[i] == -1) dfs(i, 0);
		}
		if(good){
			moo << "YES" << endl;
		}else{
			moo << "NO" << endl;
		}
	}
}