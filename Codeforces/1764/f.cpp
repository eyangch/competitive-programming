#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct edge{
	int u, v, w;
};

int N, F[2000][2000];
bool desc[2000][2000];
vector<edge> ans;

void dfs(int v){
	while(true){
		int mxv = -1, mxi = -1;
		for(int i = 0; i < N; i++){
			if(desc[v][i]){
				if(F[v][i] > mxv){
					mxv = F[v][i];
					mxi = i;
				}
			}
		}
		if(!~mxi) break;
		desc[v][mxi] = 0;
		int vi = F[v][v] - F[v][mxi];
		int vv = F[mxi][mxi] - F[v][mxi];
		assert((vi + vv) % N == 0);
		int x = (vi + vv) / N;
		ans.push_back({v+1, mxi+1, x});
		for(int i = 0; i < N; i++){
			if(desc[v][i]){
				if(F[v][i] < F[mxi][i]){
					desc[mxi][i] = 1;
					desc[v][i] = 0;
				}
			}
		}
		dfs(mxi);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++){
			eat >> F[i][j];
			F[j][i] = F[i][j];
		}
	}
	for(int i = 1; i < N; i++){
		desc[0][i] = 1;
	}
	dfs(0);
	for(edge e : ans){
		moo << e.u << ' ' << e.v << ' ' << e.w << endl;
	}
}