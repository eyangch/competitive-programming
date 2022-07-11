#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, Q, K, P[200000], up[20][200000], tin[200000], tout[200000], de[200000];
vector<int> graph[200000];
int t = 0;

void dfs(int v, int p, int d){
	tin[v] = t++;
	de[v] = d;
	for(int i = 1; i < 20; i++){
		up[i][v] = up[i-1][up[i-1][v]];
	}
	for(int c : graph[v]){
		if(c == p) continue;
		up[0][c] = v;
		dfs(c, v, d+1);
	}
	tout[v] = t++;
}

int jump(int u, int d){
	for(int i = 0; i < 20; i++){
		if((d>>i) & 1) u = up[i][u];
	}
	return u;
}

int lca(int u, int v){
	if(de[u] < de[v]) swap(u, v);
	u = jump(u, de[u]-de[v]);
	if(u == v) return u;
	for(int i = 19; i >= 0; i--){
		if(up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
	}
	return up[0][u];
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N-1; i++){
		int u, v; eat >> u >> v;
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}
	dfs(0, -1, 0);
	eat >> Q;
	while(Q--){
		eat >> K;
		for(int i = 0; i < K; i++){
			eat >> P[i];
			P[i]--;
		}
		sort(P, P+K, [](int a, int b){
			return tin[a] < tin[b];
		});
		int mx = 1e15;
		int cnt = 0;
		for(int i = 0; i < K; i++){
			if(tin[P[i]] > mx){
				cnt++;
			}
			mx = tout[P[i]];
		}
		if(cnt == 0){
			moo << "YES" << endl;
			continue;
		}
		if(cnt > 1){
			moo << "NO" << endl;
			continue;
		}
		int l = P[0];
		for(int i = 1; i < K; i++){
			l = lca(l, P[i]);
		}
		int flca = -1;
		for(int i = 0; i < K; i++){
			if(l == P[i]){
				flca = i;
				break;
			}
		}
		if(!~flca){
			moo << "YES" << endl;
			continue;
		}
		int l2 = -1;
		for(int i = 0; i < K; i++){
			if(i == flca) continue;
			if(l2 == -1) l2 = P[i];
			else l2 = lca(l2, P[i]);
		}
		if(l == l2){
			moo << "YES" << endl;
			continue;
		}else{
			moo << "NO" << endl;
		}
	}
}