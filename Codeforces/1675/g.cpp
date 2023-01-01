#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, A[250], dp[251][251][251], mn[251][251][251];

void upd_min(int i, int j){
	mn[i][j][M] = dp[i][j][M];
	for(int k = M-1; k >= 0; k--){
		mn[i][j][k] = min(mn[i][j][k+1], dp[i][j][k]);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= M; j++){
			for(int k = 0; k <= M; k++){
				dp[i][j][k] = 1e15;
				mn[i][j][k] = 1e15;
			}
		}
	}
	dp[0][0][M] = 0;
	upd_min(0, 0);
	int csum = 0;
	for(int i = 1; i <= N; i++){
		csum += A[i-1];
		for(int j = 0; j <= M; j++){
			for(int k = 0; k <= j; k++){
				dp[i][j][k] = mn[i-1][j-k][k] + abs(csum - j);
			}
			upd_min(i, j);
		}
	}
	moo << mn[N][M][0] << endl;	
}