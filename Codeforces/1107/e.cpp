#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[100], dp[100][100][100];
string s;

int dpf(int l, int r, int p){
	if(l > r) return 0;
	if(dp[l][r][p] > 0) return dp[l][r][p];
	int ans = 0;
	if(p > 0){
		ans = A[p-1] + dpf(l+1, r, 1); 
	}
	for(int i = l+1; i <= r; i++){
		if(s[i] == s[l]) ans = max(ans, dpf(l+1, i-1, 1) + dpf(i, r, p+1));
	}
	//moo << l << ' ' << r << ' ' << p << ' ' << ans << endl;
	return (dp[l][r][p] = ans);
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> s;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	moo << dpf(0, N-1, 1) << endl;
}