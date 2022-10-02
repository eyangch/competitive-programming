#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, W[100000], L[100000], R[100000], dp[300][300], C[300][300][300];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	freopen("pieaters.in", "r", stdin); freopen("pieaters.out", "w", stdout);
	eat >> N >> M;
	for(int i = 0; i < M; i++){
		eat >> W[i] >> L[i] >> R[i];
		L[i]--, R[i]--;
		dp[L[i]][R[i]] = W[i];
		for(int j = L[i]; j <= R[i]; j++){
			C[j][L[i]][R[i]] = max(C[j][L[i]][R[i]], W[i]);
		}
	}
	for(int i = 1; i < N; i++){
		for(int j = 0; i + j < N; j++){
			int l = j, r = i+j;
			for(int k = l; k <= r; k++){
				C[k][l][r] = max(C[k][l][r], C[k][l+1][r]);
				C[k][l][r] = max(C[k][l][r], C[k][l][r-1]);
			}
		}
	}
	for(int i = 1; i < N; i++){
		for(int j = 0; j + i < N; j++){
			int l = j, r = i+j;
			dp[l][r] = max(dp[l][r], C[l][l][r] + dp[l+1][r]);
			dp[l][r] = max(dp[l][r], C[r][l][r] + dp[l][r-1]);
			for(int k = l+1; k < r; k++){
				dp[l][r] = max(dp[l][r], dp[l][k-1] + dp[k+1][r] + C[k][l][r]);
			}
		}
	}
	moo << dp[0][N-1] << endl;
}