#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[2000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		int mx = *max_element(A, A+N);
		int mn = *min_element(A, A+N);
		int ans = A[N-1] - A[0];
		for(int i = 1; i < N; i++){
			ans = max(ans, A[i-1] - A[i]);
		}
		ans = max({ans, mx - A[0], A[N-1] - mn});
		moo << ans << endl;
	}
}