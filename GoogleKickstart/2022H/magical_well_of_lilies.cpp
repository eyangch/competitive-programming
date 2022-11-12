#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, L, dp[100001];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	for(int tc = 1; tc <= T; tc++){
		moo << "Case #" << tc << ": ";
		eat >> L;
		dp[1] = 1;
		for(int i = 2; i <= L; i++){
			dp[i] = dp[i-1] + 1;
			for(int j = 2; j * j <= i; j++){
				if(i % j) continue;
				int cur1 = 4 + 2 * (j - 1);
				int cur2 = 4 + 2 * (i / j - 1);
				//moo << dp[i/j] << ' ' << dp[j] << ' ' << cur1 << ' ' << cur2 << endl;
				dp[i] = min(dp[i], dp[i/j] + cur1);
				dp[i] = min(dp[i], dp[j] + cur2);
			}
			//moo << i << ' ' << dp[i] << endl;
		}
		moo << dp[L] << endl;
	}
}