#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, S[100000], A[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K;
		bool ok = 1;
		int pv = 0, pvd = -1e15;
		int fd = 0;
		fill(A, A+N+1, 0);
		for(int i = 0; i < K; i++){
			eat >> S[i];
			if(i != 0){
				int cd = S[i] - S[i-1];
				A[i+N-K] = cd;
			}
		}
		for(int i = N-K; i >= 0; i--){
			A[i] = A[i+1];
		}
		int s = accumulate(A, A+N-K+1, 0LL);
		if(s < S[0]){
			ok = 0;
		}
		for(int i = 1; i < N; i++){
			if(A[i] < A[i-1]){
				ok = 0;
			}
		}
		/*for(int i = 0; i < N; i++){
			moo << A[i] << ' ';
		}*/
		if(K == 1) ok = 1;
		moo << (ok ? "Yes" : "No") << endl;
	}
}