#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[100000], D[100000], I[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		for(int i = 0; i < N-1; i++){
			D[i] = A[i] - A[i+1];
		}
		iota(I, I+N-1, 0);
		sort(I, I+N-1, [](int a, int b){
			return D[a] < D[b];
		});
		moo << 1 << ' ';
		for(int i = 0; i < N-1; i++){
			moo << I[i] + 2 << ' ';
		}
		moo << endl;
	}
}