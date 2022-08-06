#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int T, N, M, A, B, vis[200000];
unordered_map<int, int, custom_hash> graph[200000];

void dfs(int u, int v, vector<vector<int>> &V){
	vis[u] = 1, vis[v] = 1;
	vector<int> cur1, cur2;
	if(graph[u].find(v) != graph[u].end()){
		cur1 = V[graph[u][v]];
	}
	if(graph[v].find(u) != graph[v].end()){
		cur2 = V[graph[v][u]];
	}
	graph[u].erase(v);
	graph[v].erase(u);
	//moo << u << ' ' << v << endl;
	//moo << "CUR1: ";
	//for(int i : cur1) moo << i <<  ' ';
	//moo << endl;
	for(int i : cur1){
		dfs(i, v, V);
	}
	for(int i : cur2){
		dfs(u, i, V);
	}
}

void add(int u, int v, int l, vector<vector<int>> &V){
	if(graph[u].find(l) != graph[u].end()){
		V[graph[u][l]].push_back(v);
	}else{
		int cnt = V.size();
		vector<int> cur;
		cur.push_back(v);
		V.push_back(cur);
		graph[u][l] = cnt;
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M >> A >> B;
		for(int i = 0; i < N; i++){
			graph[i].clear();
			vis[i] = 0;
		}
		A--, B--;
		vector<vector<int>> V;
		//moo << "TEST1" << endl; moo.flush();
		for(int i = 0; i < M; i++){
			int u, v, l; eat >> u >> v >> l;
			u--, v--, l--;
			add(u, v, l, V);
			add(v, u, l, V);
		}
		/*for(int i = 0; i < N; i++){
			moo << "NODE: " << i << "    ";
			for(pair<int, int> j  : graph[i]) moo << j.first << ' ';
				moo << endl;
		}*/
		//moo << "TEST2" << endl; moo.flush();
		//moo << "DFS PROBLEM" << endl; moo.flush();
		dfs(A, B, V);
		//moo << "NOT DFS PROBLEM" << endl; moo.flush();
		int ans = 0;
		for(int i = 0; i < N; i++){
			ans += vis[i];
		}
		moo << ans << endl;
	}
}