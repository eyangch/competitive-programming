#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[200000], P[200000];
vector<int> G[200000];
bool X[200000][32];
int cd[200000][32][3];
int sts[200000];

int dfs_sts(int v){
	sts[v] = 1;
	for(int c : G[v]){
		sts[v] += dfs_sts(c);
		A[v] ^= A[c];
	}
	return sts[v];
}

void dfs(int v, int p){
	for(int c : G[v]){
		if(c == p) continue;
		dfs(c, v);
	}
	X[v][0] = 1;
	for(int c : G[v]){
		int C[32];
		fill(C, C+32, 0);
		for(int j = 0; j < 32; j++){
			if(X[v][j] > 0) continue;
			for(int k = 0; k < 32; k++){
				if(X[v][j^k] && X[c][k]){
					C[j] = 1;
					cd[v][j][0] = k;
					cd[v][j][2] = c;
					cd[v][j][1] = j^k;
					break;
				}
			}
		}
		for(int j = 0; j < 32; j++){
			X[v][j] |= C[j];
		}
	}
	if(sts[v] % 2 == 0) X[v][A[v]] = 1;
}

vector<int> ans;
void rec(int v, int x){
	int xo1 = cd[v][x][0], xo2 = cd[v][x][1];
	int xoi = cd[v][x][2];
	int xoi2 = v;
	if(xo1 <= 0) xoi = -1;
	if(xo2 <= 0) xoi2 = -1;
	if(xoi != -1){
		rec(xoi, xo1);
	}
	if(xoi2 != -1){
		rec(xoi2, xo2);
	}
	if(xoi == -1 && xoi2 == -1){
		ans.push_back(v);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	int TX = 0;
	for(int i = 0; i < N; i++){
		eat >> A[i];
		TX ^= A[i];
		for(int j = 0; j < 32; j++){
			cd[i][j][0] = cd[i][j][1] = cd[i][j][2] = -1;
		}
	}
	for(int i = 1; i < N; i++){
		eat >> P[i];
		P[i]--;
		G[P[i]].push_back(i);
	}
	dfs_sts(0);
	dfs(0, -1);
	if(X[0][TX]){
		rec(0, TX);
		ans.push_back(0);
		moo << ans.size() << endl;
		for(int i : ans){
			moo << i+1 << ' ';
		}
		moo << endl;
	}else{
		moo << -1 << endl;
	}
}