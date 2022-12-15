#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K;
vector<pair<int, int>> E;

bool ok;
bool vis[15];
void chk(){
	ok = 1;
	fill(vis, vis+N, 0);
	function<void(int, int)> run;
	run = [&run](int v, int p){
		if(vis[v] || !ok){
			ok = 0;
			return;
		}
		vis[v] = 1;
		for(pair<int, int> e : E){
			if(e.first == p || e.second == p) continue;
			if(e.first == v){
				run(e.second, v);
			}
			if(e.second == v){
				run(e.first, v);
			}
		}
	};
	for(int i = 0; i < N; i++){
		if(vis[i]) continue;
		run(i, -1);
	}
}

bool fin = 0;
void dfs(){
	if(fin) return;
	chk();
	if(!ok){
		return;
	}
	if(E.size() == N-1){
		moo << "SOLN: " << endl;
		for(pair<int, int> e : E){
			moo << e.first << ' ' << e.second << endl;
		}
		moo << endl;
		fin = 1;
		return;
	}
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			pair<int, int> e1 = {i, j};
			pair<int, int> e2 = {(i+K) % N, (j+K) % N};
			auto it1 = find(E.begin(), E.end(), e1);
			auto it2 = find(E.begin(), E.end(), e2);
			if(it1 != E.end() || it2 != E.end()){
				continue;
			}
			E.push_back(e1);
			E.push_back(e2);
			dfs();
			E.pop_back();
			E.pop_back();
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	dfs();
}