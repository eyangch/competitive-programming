#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, B[100001], A[100001], K;
vector<int> R[100001];

int c = 0;
void dfs(int v){
	A[c++] = v;
	//moo << "VIS: " << v << endl;
	int delay = -1;
	for(int c : R[v]){
		if(R[c].size()) delay = c;
		else dfs(c);
	}
	if(~delay) dfs(delay);
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		R[0].clear();
		K = 0;
		for(int i = 1; i <= N; i++){
			eat >> B[i];
			if(B[i] > i) K = i;
			R[i].clear();
		}
		for(int i = 1; i <= N; i++){
			if(B[i] == 0 || B[i] == N+1){
				R[0].push_back(i);
			}else{
				R[B[i]].push_back(i);
			}
		}
		c = 0;
		dfs(0);
		moo << K << endl;
		for(int i = 1; i <= N; i++){
			moo << A[i] << ' ';
		}
		moo << endl;
	}
}