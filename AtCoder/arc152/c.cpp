#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[200000];

int solve(){
	int g = A[1] - A[0];
	for(int i = 2; i < N; i++){
		g = gcd(g, A[i] - A[i-1]);
	}
	g *= 2;
	int dif = A[N-1] - A[0];
	int sm = A[0] % g;
	return sm + dif;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	int ans = solve();
	for(int i = 0; i < N; i++){
		A[i] = A[N-1] * 2 - A[i];
	}
	reverse(A, A+N);
	ans = min(ans, solve());
	moo << ans << endl;
}