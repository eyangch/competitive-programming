#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, A[100000], B[100000], I[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			I[i] = i;
			B[i] = A[i];
		}
		sort(I, I+N, [](int a, int b){
			return A[a] < A[b];
		});
		int max_direct = 1e9;
		if(K == 1){
			max_direct = *max_element(A, A+N);
		}
		for(int i = 0; i < K-1; i++) A[I[i]] = 1e9;
		int mn_ind = *min_element(A, A+N) * 2;
		int ans = min(max_direct, mn_ind);
		A[I[K-1]] = 1e9;
		max_direct = 0;
		for(int i = 1; i < N; i++){
			max_direct = max(max_direct, min(A[i], A[i-1]));
		}
		mn_ind = *min_element(A, A+N) * 2;
		int ans2 = min(max_direct, mn_ind);
		moo << max(ans, ans2) << endl;
	}
}