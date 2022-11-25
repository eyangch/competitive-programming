#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N;
vector<int> G[200000];
int nd = 0, R = 0, mD[200000];

pair<int, int> dfs1(int v, int p){
	pair<int, int> mx1 = {0, v}, mx2 = {0, v};
	for(int c : G[v]){
		if(c == p) continue;
		pair<int, int> x = dfs1(c, v);
		if(x > mx1){
			mx2 = mx1;
			mx1 = x;
		}else if(x > mx2){
			mx2 = x;
		}
	}
	int tot = mx1.first + mx2.first;
	if(tot > nd){
		nd = tot;
		R = mx1.second;
	}
	return {mx1.first + 1, mx1.second};
}

void dfs2(int v, int p, int d){
	mD[v] = d;
	for(int c : G[v]){
		if(c == p) continue;
		dfs2(c, v, d+1);
		mD[v] = max(mD[v], mD[c]);
	}
}

int E[200000], cE = 1;
void dfs3(int v, int p){
	E[v] = cE++;
	int mxv = 0, mxi = -1;
	for(int c : G[v]){
		if(c == p) continue;
		if(mD[c] > mxv){
			mxv = mD[c];
			mxi = c;
		}
	}
	for(int c : G[v]){
		if(c == p || c == mxi) continue;
		dfs3(c, v);
	}
	if(mxi != -1){
		dfs3(mxi, v);
	}
	cE++;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N-1; i++){
		int u, v; eat >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(0, -1);
	dfs2(R, -1, 0);
	dfs3(R, -1);
	for(int i = 0; i < N; i++){
		moo << E[i] << ' ';
	}
	moo << endl;
}