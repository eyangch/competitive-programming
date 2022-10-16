#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int N, dp[150][150][2][2], sum[150][150][2][2];
bool C[150][150];
string S[150];

void MODify(int &x){
	x = (x % MOD + MOD) % MOD;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> S[i];
	}
	/*for(int l = 0; l < N; l++){
		for(int r = l; r < N; r++){
			sum[l][r][0][0] = 1;
		}
	}*/
	int ans = 0;
	for(int y = 0; y < N; y++){
		for(int l = 0; l < N; l++){
			C[l][l] = (S[y][l] == 'G');
			for(int r = l+1; r < N; r++){
				C[l][r] = (C[l][r-1] && S[y][r] == 'G');
			}
		}
		for(int l = 0; l < N; l++){
			for(int r = l; r < N; r++){
				dp[l][r][0][0] = sum[l][r][0][0] + 1;
				dp[l][r][1][0] = sum[l][r][1][0];
				if(l > 0) dp[l][r][1][0] -= sum[l-1][l-1][1][0];
				//if(l > 0) dp[l][r][1][0] += sum[l-1][r][0][0];
				dp[l][r][0][1] = sum[l][r][0][1];
				if(r < N-1) dp[l][r][0][1] -= sum[r+1][r+1][0][1];
				//if(r < N-1) dp[l][r][0][1] += sum[l][r+1][0][0];
				dp[l][r][1][1] = sum[l][r][1][1];
				//if(l > 0) dp[l][r][1][1] += sum[l-1][r][0][0];
				//if(r < N-1) dp[l][r][1][1] += sum[l][r+1][0][0];
				//if(l > 0 && r < N-1) dp[l][r][1][1] -= sum[l-1][r+1][0][0];
				//moo << dp[l][r][0][0] << ',' << dp[l][r][0][1] << ',' << dp[l][r][1][0] << ',' << dp[l][r][1][1] << " ";
				if(!C[l][r]){
					dp[l][r][0][0] = dp[l][r][1][0] = dp[l][r][0][1] = dp[l][r][1][1] = 0;
				}
				MODify(dp[l][r][0][0]), MODify(dp[l][r][1][0]), MODify(dp[l][r][0][1]), MODify(dp[l][r][1][1]);
				ans += dp[l][r][0][0] + dp[l][r][1][0] + dp[l][r][0][1] + dp[l][r][1][1];
				MODify(ans);
			}
			//moo << '/';
		}
		//moo << endl;
		for(int l = N-1; l >= 0; l--){
			for(int r = l; r < N; r++){
				sum[l][r][0][0] = dp[l][r][0][0];
				if(l < r) sum[l][r][0][0] += sum[l+1][r][0][0] + sum[l][r-1][0][0];
				if(l < r-1) sum[l][r][0][0] -= sum[l+1][r-1][0][0];
				MODify(sum[l][r][0][0]);
			}
		}
		for(int l = 0; l < N; l++){
			for(int r = l; r < N; r++){
				sum[l][r][1][0] = dp[l][r][1][0];
				bool bL = (l > 0), bR = (r > l);
				if(bL) sum[l][r][1][0] += dp[l-1][r][0][0];
				if(bL) sum[l][r][1][0] += sum[l-1][r][1][0];
				if(bR) sum[l][r][1][0] += sum[l][r-1][1][0];
				if(bL && bR) sum[l][r][1][0] -= sum[l-1][r-1][1][0];
				MODify(sum[l][r][1][0]);
			}
		}
		for(int l = N-1; l >= 0; l--){
			for(int r = N-1; r >= l; r--){
				sum[l][r][0][1] = dp[l][r][0][1];
				bool bL = (l < r), bR = (r < N-1);
				if(bR) sum[l][r][0][1] += dp[l][r+1][0][0];
				//if(bL) moo << "MOOOO: " << sum[l+1][r][0][1] << endl;
				if(bL) sum[l][r][0][1] += sum[l+1][r][0][1];
				if(bR) sum[l][r][0][1] += sum[l][r+1][0][1];
				if(bL && bR) sum[l][r][0][1] -= sum[l+1][r+1][0][1];
				MODify(sum[l][r][0][1]);
			}
		}
		for(int l = 0; l < N; l++){
			for(int r = N-1; r >= l; r--){
				sum[l][r][1][1] = dp[l][r][1][1];
				bool bL = (l > 0), bR = (r < N-1);
				if(bL) sum[l][r][1][1] += dp[l-1][r][0][1];
				if(bR) sum[l][r][1][1] += dp[l][r+1][1][0];
				if(bL && bR) sum[l][r][1][1] += dp[l-1][r+1][0][0];
				if(bL) sum[l][r][1][1] += sum[l-1][r][1][1];
				if(bR) sum[l][r][1][1] += sum[l][r+1][1][1];
				if(bL && bR) sum[l][r][1][1] -= sum[l-1][r+1][1][1];
				MODify(sum[l][r][1][1]);
			}
		}
	}
	moo << ans << endl;
}