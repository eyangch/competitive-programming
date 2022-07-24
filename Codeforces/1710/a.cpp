#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, K, A[100000], B[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M >> K;
		for(int i = 0; i < K; i++){
			eat >> A[i];
		}
		sort(A, A+K);
		bool good = false;
		for(int test = 0; test < 2; test++){
			copy(A, A+K, B);
			int cnt = M;
			if(M & 1){
				if(B[K-1] < 3 * N){
					swap(N, M);
					continue;
				}
				int amt = B[K-1] / N;
				B[K-1] = 0;
				cnt -= amt;
			}
			for(int i = 0; i < K; i++){
				if(B[i] >= 2 * N){
					int amt = B[i] / N;
					cnt -= amt;
				}
			}
			if(cnt <= 0){
				good = 1;
			}
			swap(N, M);
		}
		moo << (good ? "Yes" : "No") << endl;
	}
}