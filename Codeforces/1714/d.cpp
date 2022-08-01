#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int Q, N, dp[101];
string T, S[10];

bool match(int x, int j){
	for(int i = 0; i < (int)S[j].size(); i++){
		if(T[x+i] != S[j][i]) return false;
	}
	return true;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> Q;
	while(Q--){
		eat >> T >> N;
		for(int i = 0; i < N; i++){
			eat >> S[i];
		}
		int M = T.size();
		fill(dp, dp+M+1, 1e15);
		dp[0] = 0;
		for(int i = 0; i < M; i++){
			for(int j = 0; j < N; j++){
				if(match(i, j)){
					for(int k = i+1; k <= M && k <= i+S[j].size(); k++){
						dp[k] = min(dp[k], dp[i] + 1);
					}
				}
			}
		}
		if(dp[M] == 1e15){
			moo << -1 << endl;
			continue;
		}
		moo << dp[M] << endl;
		int cur = M;
		while(cur > 0){
			for(int i = 0; i < M; i++){
				if(dp[i] != dp[cur] - 1) continue;
				bool f = 0;
				for(int j = 0; j < N; j++){
					if(match(i, j)){
						if(i + S[j].size() >= cur){
							cur = i;
							f = 1;
							moo << j+1 << ' ' << i+1 << endl;
							break;
						}
					}
				}
				if(f) break;
			}
		}
	}
}