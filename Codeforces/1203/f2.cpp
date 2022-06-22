#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, R, nP, nN;
pair<int, int> ps[100], ne[100];
int dp[101][101];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> R;
	for(int i = 0; i < N; i++){
		int a, b; eat >> a >> b;
		if(b >= 0){
			ps[nP] = {a, b};
			nP++;
		}else{
			ne[nN] = {a, b};
			nN++;
		}
	}
	sort(ps, ps+nP);
	int psz = 0;
	for(int i = 0; i < nP; i++){
		if(R >= ps[i].first){
			R += ps[i].second;
			psz++;
		}
	}
	sort(ne, ne+nN, [](pair<int, int> a, pair<int, int> b){
		return a.first + a.second > b.first + b.second;
	});
	for(int i = 0; i <= nN; i++){
		for(int j = 0; j <= nN; j++){
			dp[i][j] = -1;
		}
	}
	dp[0][0] = R;
	for(int i = 1; i <= nN; i++){
		for(int j = 0; j <= i; j++){
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if(j > 0){
				if(ne[i-1].first <= dp[i-1][j-1]){
					dp[i][j] = max(dp[i][j], dp[i-1][j-1] + ne[i-1].second);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= nN; i++){
		if(dp[nN][i] >= 0) ans = max(ans, i);
	}
	moo << ans + psz << endl;
}