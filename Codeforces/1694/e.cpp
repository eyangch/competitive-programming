#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, D[200000];
vector<int> graph[200000], rgraph[200000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int in[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	for(int i = 0; i < M; i++){
		int u, v; eat >> u >> v;
		graph[u-1].push_back(v-1);
		rgraph[v-1].push_back(u-1);
	}
	fill(D, D+N, 1e15);
	pq.push({0, N-1});
	while(!pq.empty()){
		int v = pq.top().second, d = pq.top().first;
		pq.pop();
		if(D[v] <= d) continue;
		D[v] = d;
		for(int c : rgraph[v]){
			if(D[c] < 1e15) continue;
			in[c]++;
			int tot = graph[c].size();
			int adjd = d + 1 + tot - in[c];
			pq.push({adjd, c});
		}
	}
	moo << D[0] << endl;
}