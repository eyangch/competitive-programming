#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[200000], P[200000];
int cnt[300000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		P[0] = A[0];
		for(int i = 1; i < N; i++){
			P[i] = P[i-1] ^ A[i];
		}
		int n2 = 1;
		while(n2 <= N){
			n2 *= 2;
		}
		for(int i = 0; i < n2; i++){
			cnt[i] = 0;
		}
		int ans = N * (N+1) / 2;
		cnt[0] = 1;
		for(int i = 0; i < N; i++){
			for(int j = 0; j * j < n2; j++){
				ans -= cnt[P[i] ^ (j*j)];
			}
			cnt[P[i]]++;
		}
		moo << ans << endl;
	}
}