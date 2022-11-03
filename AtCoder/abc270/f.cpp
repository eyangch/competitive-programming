#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, X[200002], Y[200002], vis[200002];
vector<pair<int, int>> G[200002];

int prim(){
	int ans = 0;
	fill(vis, vis+N+2, 0);
	priority_queue<pair<int, int>> pq;
	pq.push({0, 0});
	while(!pq.empty()){
		int d = -pq.top().first, v = pq.top().second;
		pq.pop();
		if(vis[v]) continue;
		vis[v] = 1;
		ans += d;
		for(pair<int, int> i : G[v]){
			if(vis[i.first]) continue;
			pq.push({-i.second, i.first});
		}
	}
	for(int i = 0; i < N; i++){
		if(!vis[i]){
			ans = 1e15;
		}
	}
	return ans;
}

void addX(){
	for(int i = 0; i < N; i++){
		G[i].push_back({N, X[i]});
		G[N].push_back({i, X[i]});
	}
}

void addY(){
	for(int i = 0; i < N; i++){
		G[i].push_back({N+1, Y[i]});
		G[N+1].push_back({i, Y[i]});
	}
}

void rmX(){
	for(int i = 0; i < N; i++){
		G[i].pop_back();
		G[N].pop_back();
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	for(int i = 0; i < N; i++){
		eat >> X[i];
	}
	for(int i = 0; i < N; i++){
		eat >> Y[i];
	}
	for(int i = 0; i < M; i++){
		int u, v, w; eat >> u >> v >> w;
		u--, v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	int ans = 1e15;
	ans = min(ans, prim());
	addX();
	ans = min(ans, prim());
	rmX();
	addY();
	ans = min(ans, prim());
	addX();
	ans = min(ans, prim());
	moo << ans << endl;
}