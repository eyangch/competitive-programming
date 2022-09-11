#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, A[500000], B[500000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	for(int tc = 1; tc <= T; tc++){
		moo << "Case #" << tc << ": ";
		eat >> N >> K;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			A[i]--;
		}
		for(int i = 0; i < N; i++){
			eat >> B[i];
			B[i]--;
		}
		int sum = 0;
		__int128 hashA = 0;
		__int128 hashB = 0;
		for(int i = 0; i < N; i++){
			sum += A[i];
			hashA += (A[i] * (i+1));
		}
		for(int i = 0; i < N; i++){
			hashB += (B[i] * (i+1));
		}
		vector<int> cand;
		for(int i = 0; i < N; i++){
			if(hashA == hashB){
				bool tes = 1;
				for(int j = 0; j < N; j++){
					if(A[(i+j) % N] != B[j]){
						tes = 0;
					}
				}
				if(tes){
					cand.push_back(i);
				}
			}
			hashA += A[i] * N - sum;
		}
		if(cand.size() == 0){
			moo << "NO" << endl;
		}else{
			if(N == 2) K %= 2;
			if(K == 0){
				if(cand[0] == 0){
					moo << "YES" << endl;
				}else{
					moo << "NO" << endl;
				}
			}else if(K == 1){
				if(cand[cand.size()-1] != 0){
					moo << "YES" << endl;
				}else{
					moo << "NO" << endl;
				}
			}else{
				moo << "YES" << endl;
			}
		}
	}
}