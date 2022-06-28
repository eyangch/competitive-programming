#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M;
int X[81], S[81], L[81], R[81];
int dp[100001];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	for(int i = 0; i < N; i++){
		eat >> X[i] >> S[i];
		L[i] = X[i]-S[i];
		R[i] = X[i]+S[i];
	}
	X[N] = 0, S[N] = 0, L[N] = 0, R[N] = 0;
	dp[0] = 0;
	for(int i = 1; i <= M; i++){
		bool good = 0;
		for(int j = 0; j <= N; j++){
			if(L[j] <= i && R[j] >= i){
				good = 1;
				break;
			}
		}
		if(good){
			dp[i] = dp[i-1];
			continue;
		}
		dp[i] = 1e9;
		for(int j = 0; j <= N; j++){
			if(R[j] > i) continue;
			int expand = i - R[j];
			int pv = max(0LL, L[j] - expand-1);
			dp[i] = min(dp[i], dp[pv] + expand);
			if(i == 514){
				//moo << expand << ' ' << pv << ' ' << dp[pv] << endl;
			}
		}
		//moo << i << ' ' << dp[i] << endl;
	}
	moo << dp[M] << endl;
}