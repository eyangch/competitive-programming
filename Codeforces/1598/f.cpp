#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, ts[20], ct[20][400001], mn[20], dp[1<<20];
string S[20];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> S[i];
		int cur = 0;
		mn[i] = 0;
		for(int j = 0; j < (int)S[i].size(); j++){
			cur += (S[i][j] == '(' ? 1 : -1);
			mn[i] = min(mn[i], cur);
			if(mn[i] == cur){
				ct[i][-cur]++;
			}
		}
		ts[i] = cur;
	}
	fill(dp, dp+(1<<N), -1e9);
	dp[0] = 0;
	int ans = 0;
	for(int i = 0; i < (1<<N); i++){
		if(dp[i] < 0) continue;
		int pr = 0;
		for(int j = 0; j < N; j++){
			if((i>>j)&1){
				pr += ts[j];
			}
		}
		for(int j = 0; j < N; j++){
			if(!((i>>j)&1)){
				int wys = dp[i] + ct[j][pr];
				int cmn = pr + mn[j];
				ans = max(ans, wys);
				if(cmn >= 0) dp[i|(1<<j)] = max(dp[i|(1<<j)], wys);
			}
		}
	}
	moo << ans << endl;
}