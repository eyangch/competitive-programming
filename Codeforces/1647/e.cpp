#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct lift{
	int up[31][100000];
	void init(int N, int (&A)[100000]){
		for(int i = 0; i < N; i++){
			up[0][i] = A[i];
		}
		for(int i = 1; i < 31; i++){
			for(int j = 0; j < N; j++){
				up[i][j] = up[i-1][up[i-1][j]];
			}
		}
	}
	int jump(int v, int d){
		for(int i = 0; i < 31; i++){
			if((d>>i)&1){
				v = up[i][v];
			}
		}
		return v;
	}
};

int N, P[100000], A[100000], in[100000], ans[100000];
bool vis[100000];
lift L;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> P[i];
		P[i]--;
		in[P[i]]++;
	}
	for(int i = 0; i < N; i++){
		eat >> A[i];
		A[i]--;
	}
	int cntin = 0;
	for(int i = 0; i < N; i++){
		if(in[i] == 0){
			cntin++;
		}
	}
	int mxA = *max_element(A, A+N);
	int tn = (mxA-(N-1))/cntin;
	L.init(N, P);
	fill(ans, ans+N, -1);
	set<int> S;
	for(int i = 0; i < N; i++){
		S.insert(i);
	}
	for(int i = 0; i < N; i++){
		int to = L.jump(i, tn);
		if(vis[to]) continue;
		vis[to] = 1;
		ans[i] = A[to];
		S.erase(A[to]);
	}
	for(int i = 0; i < N; i++){
		if(~ans[i]) continue;
		int to = L.jump(i, tn);
		auto it = S.lower_bound(A[to]);
		ans[i] = *it;
		S.erase(it);
	}
	for(int i = 0; i < N; i++){
		moo << ans[i]+1 << ' ';
	}
	moo << endl;
}