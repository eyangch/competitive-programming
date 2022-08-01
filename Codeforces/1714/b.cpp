#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[200000], F[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			A[i]--;
		}
		fill(F, F+N, 0);
		int ans = 0;
		for(int i = N-1; i >= 0; i--){
			if(F[A[i]]){
				ans = i+1;
				break;
			}
			F[A[i]] = 1;
		}
		moo << ans << endl;
	}
}