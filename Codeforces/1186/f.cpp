#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, C[1000001];
set<int> graph[1000001];
vector<int> etour;
bool used[2000000];
set<int> rm[1000001];

void dfs(int start, int comp){
	stack<int> s;
	s.push(start);
	while(!s.empty()){
		int v = s.top();
		C[v] = comp;
		if(graph[v].empty()){
			s.pop();
			etour.push_back(v);
		}else{
			int c = *graph[v].begin();
			graph[v].erase(c);
			graph[c].erase(v);
			s.push(c);
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	for(int i = 0; i < M; i++){
		int u, v; eat >> u >> v;
		graph[u-1].insert(v-1);
		graph[v-1].insert(u-1);
	}
	for(int i = 0; i < N; i++){
		if((int)graph[i].size() & 1){
			graph[i].insert(N);
			graph[N].insert(i);
		}
	}
	fill(C, C+N+1, -1);
	for(int i = 0; i <= N; i++){
		if(~C[i]) continue;
		dfs(i, i);
	}
	vector<pair<int, int>> ans;
	for(int i = 2; i < (int)etour.size(); i += 2){
		int u = etour[i-1];
		int v = etour[i];
		if(u > v) swap(u, v);
		if(C[u] != C[v]) continue;
		if(v != N){
			rm[u].insert(v);
			rm[v].insert(u);
		}
	}
	for(int i = 1; i < (int)etour.size(); i += 2){
		int u = etour[i-1];
		int v = etour[i];
		if(u > v) swap(u, v);
		if(C[u] != C[v]) continue;
		if(v == N){
			if(!rm[u].size()) continue;
			v = *rm[u].begin();
			ans.push_back({u, v});
			rm[u].erase(v);
			rm[v].erase(u);
		}else{
			ans.push_back({u, v});
		}
	}
	moo << ans.size() << endl;
	for(pair<int, int> i : ans){
		moo << i.first+1 << ' ' << i.second+1 << endl;
	}
}