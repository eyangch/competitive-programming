#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[200000], P[200000], S[200000], ans;
vector<int> G[200000];
set<int> ss[200000];

void pdfs(int v, int p, int x){
	P[v] = x;
	S[v] = (x ^= A[v]);
	for(int c : G[v]){
		if(c == p) continue;
		pdfs(c, v, x);
	}
}

int dfs(int v, int p){
	vector<int> sts;
	for(int c : G[v]){
		if(c == p) continue;
		sts.push_back(dfs(c, v));
	}
	int mxv = -1, mxi = v;
	for(int i : sts){
		if((int)ss[i].size() > mxv){
			mxv = ss[i].size();
			mxi = i;
		}
	}
	bool fnd = 0;
	for(int i : sts){
		if(i == mxi) continue;
		for(int j : ss[i]){
			if(fnd) break;
			int cur = j^A[v];
			if(ss[mxi].count(cur)){
				fnd = 1;
				break;
			}
		}
		for(int j : ss[i]){
			ss[mxi].insert(j);
		}
	}
	if(ss[mxi].count(P[v])) fnd = 1;
	ss[mxi].insert(S[v]);
	if(fnd){
		ans++;
		ss[mxi].clear();
	}
	return mxi;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	for(int i = 0; i < N-1; i++){
		int u, v; eat >> u >> v;
		G[u-1].push_back(v-1);
		G[v-1].push_back(u-1);
	}
	pdfs(0, -1, 0);
	/*for(int i = 0; i < N; i++){
		moo << P[i] << '/' << S[i] << endl;
	}*/
	dfs(0, -1);
	moo << ans << endl;
}