#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, D, B[100000], S[100000], E[100000];
vector<int> dp[100001];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K >> D;
		for(int i = 0; i < N; i++){
			eat >> B[i];
		}
		int csum = 0, eptr = 0;
		/*for(int i = 0; i < min(N, D); i++){
			if(B[eptr] == 0){
				break;
			}
			csum += B[eptr++];
		}*/
		for(int i = 0; i < N; i++){
			eptr = max(eptr, i);
			while(eptr < N && eptr < i+D && B[eptr] != 0){
				csum += B[eptr];
				eptr++;
			}
			S[i] = csum;
			E[i] = min(N, i+D);
			csum -= B[i];
		}
		//for(int i = 0; i < N; i++) moo << S[i] << ' ';
		//moo << endl;
		//for(int i = 0; i < N; i++) moo << E[i] << ' ';
		//moo << endl;
		for(int i = 0; i <= N; i++){
			dp[i].resize(K+1);
			fill(dp[i].begin(), dp[i].end(), 0);
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < K; j++){
				//if(dp[i][j] + S[i] == 18) moo << i << ' ' << j << endl;
				dp[E[i]][j+1] = max(dp[E[i]][j+1], dp[i][j] + S[i]);
				dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			}
			//moo << endl;
		}
		for(int i = 1; i <= N; i++){
			dp[i][K] = max(dp[i][K], dp[i-1][K]);
		}
		/*for(int i = 0; i <= N; i++){
			for(int j = 0; j <= K; j++){
				moo << dp[i][j] << ' ';
			}
			moo << endl;
		}*/
		moo << dp[N][K] << endl;
	}
}