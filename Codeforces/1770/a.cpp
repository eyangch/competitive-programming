#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, A[1000], B[1000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		for(int i = 0; i < M; i++){
			eat >> B[i];
		}
		for(int i = 0; i < M; i++){
			int mn = 1e15, mni = 0;
			for(int j = 0; j < N; j++){
				if(A[j] < mn){
					mn = A[j];
					mni = j;
				}
			}
			A[mni] = B[i];
		}
		int ans = 0;
		for(int i = 0; i < N; i++) ans += A[i];
		moo << ans << endl;
	}
}