#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, A[100000], D[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		for(int i = 0; i < M; i++){
			eat >> A[i];
		}
		sort(A, A+M);
		for(int i = 0; i < M-1; i++){
			D[i] = A[i+1] - A[i]-1;
		}
		D[M-1] = N - A[M-1] + A[0]-1;
		int days = 0;
		sort(D, D+M);
		int ans = 0;
		for(int i = M-1; i >= 0; i--){
			int cur = D[i] - days * 2;
			if(cur <= 0) break;
			ans += max(1LL, cur-1);
			days += 2;
		}
		moo << N - ans << endl;
	}
}