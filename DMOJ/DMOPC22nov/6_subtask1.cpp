#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, dp[300][300], ele[300];
string S[50000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	for(int i = 0; i < N; i++){
		eat >> S[i];
	}
	for(int i = 0; i < N; i++){
		dp[i][i] = 1;
	}
	int ans = 1;
	for(int i = 0; i < N; i++){
		fill(ele, ele+M, 0);
		for(int j = i; j < N; j++){
			bool ok = 0;
			for(int k = 0; k < M; k++){
				char x = S[j][k];
				if(x == '1'){
					if(ele[k] == 1) ok = 1;
					ele[k] = 1;
				}
			}
			if(!ok) continue;
			if(j != i && !dp[i][j-1]) continue;
			dp[i][j] = 1;
			ans = max(ans, j-i+1);
		}
		fill(ele, ele+M, 0);
		for(int j = i; j >= 0; j--){
			bool ok = 0;
			for(int k = 0; k < M; k++){
				char x = S[j][k];
				if(x == '1'){
					if(ele[k] == 1) ok = 1;
					ele[k] = 1;
				}
			}
			if(!ok) continue;
			if(j != i && !dp[j+1][i]) continue;
			dp[j][i] = 1;
			ans = max(ans, i-j+1);
		}
	}
	/*for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			moo << dp[i][j] << ' ';
		}
		moo << endl;
	}*/
	moo << ans << endl;
}