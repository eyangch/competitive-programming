#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, H[200000], up[200000], T, in[200000];
vector<int> G[200000];
vector<pair<int, int>> G2[200000];
vector<int> s, d, n;

int dfs(int v, int p){
	int cur = H[v];
	for(int c : G[v]){
		if(c == p) continue;
		int x = dfs(c, v);
		if(x < 0){
			G2[c].push_back({v, -up[c]});
			in[v]++;
		}
		cur -= x;
	}
	up[v] = T-cur;
	if(up[v] > 0){
		G2[p].push_back({v, up[v]});
		in[v]++;
	}
	return up[v];
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> H[i];
	}
	T = accumulate(H, H+N, 0LL) / N;
	for(int i = 1; i < N; i++){
		int u, v; eat >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	//moo << T << endl;
	dfs(0, 0);
	//for(int i = 0; i < N; i++) moo << up[i] << endl;
	assert(up[0] == 0);
	queue<int> q;
	for(int i = 0; i < N; i++){
		if(!in[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(pair<int, int> e : G2[v]){
			s.push_back(v+1);
			d.push_back(e.first+1);
			n.push_back(e.second);
			if(--in[e.first] == 0){
				q.push(e.first);
			}
		}
	}
	moo << s.size() << endl;
	for(int i = 0; i < (int)s.size(); i++){
		moo << s[i] << ' ' << d[i] << ' ' << n[i] << endl;
	}
}